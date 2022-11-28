


#include "KeyPad.h"
#include "Dio.h"
#include "avr/delay.h"

u8 keys[4][4] = {

		{'1', '2', '3', '+'},

		{'4', '5', '6', '-'},

		{'7', '8', '9', '*'},

		{'0', 'C', '=', '/'}

};
void KeyPad_Init(void)
{
	Dio_SetPinDirection(PH_PORTA, ROW_1, OUTPUT_DIRECTION);
	Dio_SetPinDirection(PH_PORTA, ROW_2, OUTPUT_DIRECTION);
	Dio_SetPinDirection(PH_PORTA, ROW_3,OUTPUT_DIRECTION );
	Dio_SetPinDirection(PH_PORTA,ROW_4 , OUTPUT_DIRECTION);

	Dio_SetPinDirection(PH_PORTA, COLUMN_1,INPUT_DIRECTION );
	Dio_SetPinDirection(PH_PORTA, COLUMN_2, INPUT_DIRECTION);
	Dio_SetPinDirection(PH_PORTA,COLUMN_3,INPUT_DIRECTION);
	Dio_SetPinDirection(PH_PORTA,COLUMN_4 ,INPUT_DIRECTION );

	// Write 5v on pins PORTC_PIN0, PORTC_PIN1, PORTC_PIN2, PORTC_PIN3
	Dio_WritePin(PH_PORTA,ROW_1 ,HIGH_LEVEL);
	Dio_WritePin(PH_PORTA, ROW_2,HIGH_LEVEL );
	Dio_WritePin(PH_PORTA, ROW_3, HIGH_LEVEL);
	Dio_WritePin(PH_PORTA, ROW_4, HIGH_LEVEL);

	// Activate pull up resistor for pins PORTC_PIN4 , PORTC_PIN5, PORTC_PIN6, PORTC_PIN7
	Dio_ActivatePinPullUpResistor(PH_PORTA, COLUMN_1);
	Dio_ActivatePinPullUpResistor(PH_PORTA, COLUMN_2);
	Dio_ActivatePinPullUpResistor(PH_PORTA, COLUMN_3);
	Dio_ActivatePinPullUpResistor(PH_PORTA, COLUMN_4);
}

u8 KeyPad_GetPressedKey(void)
{
	u8 row, column;
	u8 keyLevel;
	u8 pressedKey = 0;

	for(row = 0; row<=3; row++)
	{
		Dio_WritePin(PH_PORTA, row, LOW_LEVEL);

		for(column = 0; column<=3; column++)
		{
			keyLevel = Dio_ReadPin(PH_PORTA, column+4);

			if(keyLevel == 0)
			{
				_delay_ms(100);    // Wait till bouncing is passed

				if(Dio_ReadPin(PH_PORTA, column+4) == 0)  // Confirm that button is really pressed (i.e.Not a Noise)
				{
					pressedKey = keys[row][column];


					while(Dio_ReadPin(PH_PORTA, column+4) == 0)    // Wait until button is released
					{

					}
					break;
				}
				else
				{
					// Do nothing
				}

			}


		}

		Dio_WritePin(PH_PORTA,row ,HIGH_LEVEL) ;


		if(keyLevel == 0)
		{
			break;
		}
	}

	return pressedKey;

}

