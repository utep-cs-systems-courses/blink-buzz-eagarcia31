#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "state_machine.h"
#include "led.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char count =0;
  static char note =0;
  static char delay =0;
  static char make_noise =0;
  static char time_until_change = 0;

  if(play_song && note < 43){
    if(++count == time_until_change){
      count=0;
      if(make_noise){
	make_noise =0;
	buzzer_set_period(0);
	time_until_change = delay_time[delay++];
	led_state(0,1);
      }
      else{
	make_noise = 1;
	buzzer_set_period(notes[note]);
	time_until_change = note_duration[note++];
	led_state(1,0);
      }
    }
  }
  else{
    delay = 0;
    note = 0;
    buzzer_set_period(0);
  }
}
