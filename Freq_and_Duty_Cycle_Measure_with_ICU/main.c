/*
 * Freq_and_Duty_Cycle_Measure_with_ICU.c
 *
 * Created: 3/29/19 7:49:29 PM
 * Author : Ahmed El-Torky
 */

#define F_CPU 8000000ul

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd/lcd.h"
#include "BIT_MATH.h"

volatile uint16_t a, b, c;
volatile uint8_t i, ready;

int main(void)
{
	char freq_data[14], duty_data[7];

	/* Timer1 initial */
	TCCR1B |= (1 << ICNC1); // enable noise canceler input
	TCCR1B |= (1 << CS11);	// set prescaler to 8
	TCCR1B |= (1 << ICES1); // the rising edge will trigger the capture
	TIMSK1 |= (1 << ICIE1); // enable input capture interrupt

	/* LCD initial */
	lcd_init();
	lcd_write_cmnd(LCD_CURSOR_OFF);
	lcd_write_string("Signal Measuring");
	_delay_ms(500);

	sei(); // set global interrupt

	while (1)
	{
		while (!ready)
			; // wait till measures be ready
		cli();

		uint16_t high = (b - a);
		uint16_t period = (c - a);

		// check if values valid
		if (a < b && b < c)
		{
			uint8_t duty_cycle = ((float)high / period) * 100;
			uint32_t freq = F_CPU / (uint32_t)(8 * period);
			itoa(duty_cycle, duty_data, 10);
			itoa(freq, freq_data, 10);
			lcd_write_cmnd(LCD_CLEAR);
			_delay_ms(1);
			lcd_write_string("Freq: ");
			lcd_write_string(freq_data);
			lcd_write_string(" Hz");
			lcd_goto_rc(1, 0);
			_delay_ms(1);
			lcd_write_string("Duty: ");
			lcd_write_string(duty_data);
			lcd_write_string(" %");
			_delay_ms(1000);
		}

		i = 0;
		ready = 0;
		TCNT1 = 0;
		sei();
	}
}

ISR(TIMER1_CAPT_vect)
{
	i++;
	switch (i)
	{
	case 1:
		a = ICR1;
		CLR_BIT(TCCR1B, ICES1); // interrupt at falling edge
		break;
	case 2:
		b = ICR1;
		SET_BIT(TCCR1B, ICES1); // interrupt at rising edge
		break;
	case 3:
		c = ICR1;
		ready = 1;
		break;
	default:
		break;
	}
}
