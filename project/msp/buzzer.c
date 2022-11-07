#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

char play_song = 0;

int notes[43] = {D5, D5, D6, D5, D5, D6, D6, D6, D6, D5, D5, D6, D5, D5, D5, D6, D5, D5, D5,

		 D5, D6, D6, D6, D5, D5, D6, D5, D5, D6, D6, D6, D5, D6, D6, D6, D5, D5, D5,

		 D6, D5, D5, D5, D5};



// The duration of each note

int note_duration[43] = {100, 100, 200, 100, 100, 200, 200, 100, 100, 100, 100, 100, 100, 200,

			 200, 100, 100, 100, 200, 200, 100, 100, 100, 100, 100, 200, 100, 100,

			 200, 200, 100, 100, 100, 100, 100, 100, 200, 200, 100, 100, 300, 200,

			 300};



// The delay between each note

int delay_time[43] = {4, 4, 12, 4, 4, 12, 15, 15, 4, 4, 4, 4, 15, 5, 5, 5,

		      5, 25, 5, 5, 5, 5, 25, 4, 4, 12, 4, 4, 12, 10, 5, 4,

		      4, 4, 4, 15, 5, 5, 5, 5, 5, 5, 2000};

void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
