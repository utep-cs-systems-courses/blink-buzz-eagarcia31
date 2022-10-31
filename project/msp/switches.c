#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "state_machine.h"
#include "toggle.h"

char sw1_down, sw2_down, sw3_down, sw4_down, switch_state_changed;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val & ~SWITCHES);
  return p2val;
}

void switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  sw1_down = (p2val & SW1) ? 0 : 1;
  sw2_down = (p2val & SW2) ? 0 : 1;
  sw3_down = (p2val & SW3) ? 0 : 1;
  sw4_down = (p2val & SW4) ? 0 : 1;
  switch_state_changed = 1;

  if(sw1_down){
    led_update();
    toggle();
  }
  else if(sw2_down){
    reset_state();
    play_song = 1;
    led_update();
  }
  else if(sw3_down){
    dim_on = 1;
    dim();
  }
  else if(sw4_down){
    play_song = 0;
    reset_state();
    led_update();
    dim_on = 0;
  }
}
