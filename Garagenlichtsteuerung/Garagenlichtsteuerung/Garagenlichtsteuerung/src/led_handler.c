#include <avr/io.h>
#include "pin_definition.h"
#include "led_handler.h"

void init_leds(void)
{
	LED_PORT &= ~LED_MASK;
	LED_DDR |= LED_MASK;	
	
	OUT_ENABLE_PORT &= ~OUT_ENABLE_MASK;
	OUT_ENABLE_DDR |= OUT_ENABLE_MASK;
}

void set_led(unsigned char led_num, unsigned char val)
{
	if(led_num == 0)
	{
		if(val)
			LED_PORT |= LED0_MASK;
		else
			LED_PORT &= ~LED0_MASK;
	}
	else if(led_num == 1)
	{
		if(val)
			LED_PORT |= LED1_MASK;
		else
			LED_PORT &= ~LED1_MASK;		
	}
	else if(led_num == 2)
	{
		if(val)
			LED_PORT |= LED2_MASK;
		else
			LED_PORT &= ~LED2_MASK;			
	}
	else if(led_num == 3)
	{
		if(val)
			LED_PORT |= LED3_MASK;
		else
			LED_PORT &= ~LED3_MASK;		
	}
}

void enable_light(unsigned char val)
{
	if(val)
		OUT_ENABLE_PORT |= OUT_ENABLE_MASK;
	else
		OUT_ENABLE_PORT &= ~OUT_ENABLE_MASK;	
	
}