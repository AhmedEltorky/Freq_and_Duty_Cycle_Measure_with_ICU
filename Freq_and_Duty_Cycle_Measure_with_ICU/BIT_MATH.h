/*
 * BIT_MATH.h
 *
 * Created: 3/29/19 11:02:00 AM
 *  Author: Ahmed El-Torky
 */

#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(Register, BIT_Num) ((Register) |= (1 << (BIT_Num)))
#define CLR_BIT(Register, BIT_Num) ((Register) &= ~(1 << (BIT_Num)))
#define TOG_BIT(Register, BIT_Num) ((Register) ^= (1 << (BIT_Num)))
#define GET_BIT(Register, BIT_Num) (((Register) >> (BIT_Num)) & 0x01)
#define IS_BIT_SET(Register, BIT_Num) ((Register) & (1 << (BIT_Num)))
#define IS_BIT_CLR(Register, BIT_Num) (!((Register) & (1 << (BIT_Num))))
#define SHFT_LEFT(Register, Num) ((Register) = ((Register) << (Num)))
#define SHFT_RIGHT(Register, Num) ((Register) = ((Register) >> (Num)))
#define ROT_LEFT(Register, Num) ((Register) = (((Register) << (Num)) | ((Register) >> (8 - Num))))
#define ROT_RIGHT(Register, Num) ((Register) = (((Register) >> (Num)) | ((Register) << (8 - Num))))

#endif