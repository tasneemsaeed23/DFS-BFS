/*
 * main.c
 *
 *  Created on: Mar 28, 2021
 *      Author: Administrator
 */

#include "MCAL/GPIO_INTERFACE.h"
#include "HAL/LCD.h"

int main(void)
{

	 set_pin_directin(GPIOA ,1);

	 set_pin_directin  (GPIOB,pin0, 1);
      set_pin_directin  (GPIOB,pin1, 1);
      set_pin_directin  (GPIOB,pin2, 1);


	/*initialization*/
	 LCD_Initial();
	/*send data*/
	 LCD_string("NORA IBRAHEEM");

}
