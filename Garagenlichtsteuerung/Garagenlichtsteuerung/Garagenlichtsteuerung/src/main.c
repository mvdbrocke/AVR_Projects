/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
//#include <asf.h>

#define F_CPU 16E6

#include "led_handler.h"
#include "input_handler.h"
#include <util/delay.h>


#define LIGHT_ON_MS 300000

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	uint8_t init_ctr = 0;
	uint32_t light_on_delay_ctr = 0;
	uint16_t light_on_delayed_evt = 0;
	uint8_t light_on_delayed = 0;
	uint8_t light_on_direct = 0;
	uint16_t blink_led_ctr = 0;
	uint8_t blink_led_state = 0;
	
	init_leds();
	init_inputs();
	
	//Bootup blink
	for(init_ctr=0;init_ctr<16;init_ctr++)
	{
		set_led(0,0);
		set_led(1,0);
		set_led(2,0);
		set_led(3,0);
		if(init_ctr&0x01)
			set_led(0,1);	
		if(init_ctr&0x02)
			set_led(1,1);
		if(init_ctr&0x04)
			set_led(2,1);
		if(init_ctr&0x08)
			set_led(3,1);
			
		_delay_ms(500);
	}
	
	while(1)
	{
		_delay_ms(1);
		
		//handle light on static
		if(get_input_val(0)||get_input_val(1)||get_input_val(2)||get_input_val(3))
			light_on_direct = 0xFF;
		else
			light_on_direct = 0x00;
		
		//read hvps in val	
		if(get_hvps_in_val())		
			light_on_delayed_evt = 0xFF;
		else
			light_on_delayed_evt = 0x00;
		
		set_led(3,light_on_delayed_evt);	
		
		//handle light on delayed
		if(light_on_delayed_evt)
		{
			light_on_delay_ctr = 1;
			light_on_delayed = 1;
		}
		
		if(light_on_delay_ctr!=0)
		{	light_on_delay_ctr++;
			light_on_delayed = 1;
		}
			
		if(light_on_delay_ctr>=LIGHT_ON_MS)
		{	light_on_delay_ctr = 0;
			light_on_delayed = 0;
		}
		
		//switch light on
		if(light_on_delayed || light_on_direct)
		{	enable_light(0xFF);
			set_led(0,0xFF);
		}
		else
		{	enable_light(0x00);
			set_led(0,0xFF);
		}
		
		//blink test led
		blink_led_ctr++;
		if(blink_led_ctr==1000)
			blink_led_state = ~blink_led_state;
		set_led(4,0xFF);
		
	}

}
