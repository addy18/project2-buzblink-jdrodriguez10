#include <msp430.h>
#include "stateMachines.h"

char super_state = 0;
void
__interrupt_vec(WDT_VECTOR) WDT(){       /* 250 interrupts/sec */
  static char s1Count = 0;
  
  if (super_state == 1){
    if (++ s1Count == 125){
      state_advance();
      s1Count = 0;
    }
  }
