#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT6
#define LED_GREEN BIT0
#define LEDS (BIT6 | BIT0)

void led_init();
void led_update();

extern unsigned char red_on, green_on;
extern unsigned char led_changed;
extern unsigned char dim_on;

#endif
