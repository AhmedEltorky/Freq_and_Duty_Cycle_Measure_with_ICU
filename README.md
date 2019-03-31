# Frequency and Duty Cycle Measure with ICU

### Measuring Frequency and Duty Cycle with ICU (Input Capture Unit).

> Duty_Cycle = Ton / (Ton + Toff) %

> Signal_freq = 1 / time_period_of_signal

> time_period_of_signal = time_period_of_timer * timer_cnt

> time_period_of_timer = 1 / timer_freq

> timer_freq = F_CPU / prescaler

> Signal_freq = F_CPU / (prescaler * timer_cnt)

## Output:

![output](https://user-images.githubusercontent.com/26473614/55288337-4f3c0e80-53b6-11e9-8bbc-75504fc639e8.PNG)
