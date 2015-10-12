

#include <avr/io.h>
#include "input_handler.h"
#include "pin_definition.h"


void init_inputs(void)
{
	NORMAL_INPUTS_DDR &= ~NORMAL_INPUT_MASK;
	HVIN_DDR &= ~HVIN_MASK;
}

unsigned char get_input_val(unsigned char input_num)
{
	unsigned char helper = 0;
	if(input_num == 0)
	{
		if(!(NORMAL_INPUTS_PIN&NORMAL_INPUT0_MASK))
			helper = 1;
	}
	else if(input_num == 1)
	{
		if(!(NORMAL_INPUTS_PIN&NORMAL_INPUT1_MASK))
			helper = 1;
		
	}
	else if(input_num == 2)
	{
		if(!(NORMAL_INPUTS_PIN&NORMAL_INPUT2_MASK))
			helper = 1;		
	}
	else if(input_num == 3)
	{
		if(!(NORMAL_INPUTS_PIN&NORMAL_INPUT3_MASK))
			helper = 1;		
	}
	return helper;	
}

unsigned char get_hvps_in_val(void)
{
	unsigned char helper = 0;
	if(!(HVIN_PIN&HVIN_MASK))
		helper = 1;
	
	return helper;
}