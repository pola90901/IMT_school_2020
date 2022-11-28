/*
 * KeyPad.h
 *
 *  Created on: Aug 18, 2018
 *      Author: user
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "Types.h"


#define ROW_1   0
#define ROW_2   1
#define ROW_3   2
#define ROW_4   3

#define COLUMN_1  4
#define COLUMN_2  5
#define COLUMN_3  6
#define COLUMN_4  7

void KeyPad_Init(void);
u8 KeyPad_GetPressedKey(void);
#endif /* KEYPAD_H_ */
