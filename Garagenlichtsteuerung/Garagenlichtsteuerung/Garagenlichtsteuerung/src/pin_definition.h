

#ifndef _pin_definition_h
#define _pin_definition_h

//normal inputs, negated: PD1, PD2, PD6, PD7
#define NORMAL_INPUTS_PIN PIND
#define NORMAL_INPUTS_DDR DDRD
#define NORMAL_INPUT_MASK 0xC3
#define NORMAL_INPUT0_MASK 0x02
#define NORMAL_INPUT1_MASK 0x04
#define NORMAL_INPUT2_MASK 0x40
#define NORMAL_INPUT3_MASK 0x80

//LEDs: PC4, PC3, PC2, PC1
#define LED_PORT PORTC
#define LED_DDR  DDRC
#define LED_MASK 0x1E
#define LED0_MASK 0x02
#define LED1_MASK 0x04
#define LED2_MASK 0x08
#define LED3_MASK 0x10

//#HVIN: PC5  
#define HVIN_PIN  PINC
#define HVIN_DDR  DDRC
#define HVIN_MASK 0x20

//OUT_ENABLE: PB0
#define OUT_ENABLE_PORT PORTB
#define OUT_ENABLE_DDR  DDRB
#define OUT_ENABLE_MASK 0x01

#endif