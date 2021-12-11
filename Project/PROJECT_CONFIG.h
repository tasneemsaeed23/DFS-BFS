/* 
 * File:   PROJECT_CONFIG.h
 * Author: Mohamed_Arafa
 *
 * Created on April 26, 2021, 12:36 PM
 */

#ifndef PROJECT_CONFIG_H
#define	PROJECT_CONFIG_H


#define F_CPU 8000000
#include <avr/eeprom.h>
//#include "MCAL/EEPROM.h" 
#include <util/delay.h>
#include "MCAL/GPIO_INTERFACE.h"
#include "MCAL/ADC_Function.h"
//#include "serveice/serviece.h"
#include "MCAL/UART_driver.h"
#include "MCAL/External_intrrupt_Atmega32H.h"
#include "HAL/keypad.h"
#include "HAL/LCD.h"

#define LED_1   0
#define LED_2   1
#define LED_3   2
#define LED_4   3
#define LED_5   4

#define fan_1   1
#define fan_2   2

#define led_buzzer_fire 7


u8 gas_read();
void fire_off();
void fan_speed(u8 speed, u8 fan_number);
void door_open_off(u8 door_status);
void task_excution(u8 command);
u8 pop_outof_queu();
void   push_into_queu(u8 data);






#endif	/* PROJECT_CONFIG_H */

