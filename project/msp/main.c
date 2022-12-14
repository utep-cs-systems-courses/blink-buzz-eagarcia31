#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "state_machine.h"

void main(void){
  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  reset_state();
  enableWDTInterrupts();

  or_sr(0x18);
}
