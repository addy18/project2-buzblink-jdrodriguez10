#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static short freq = 500;
static short state2_status = 1;

char turn_green_on()
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    buzzer_set_period(3000);
    changed = 1;
  }
  return changed;
}

char turn_red_on()
{
  static char stateS1 = 1;
  switch (stateS1) {
  case 0:
    red_on = 1;
    buzzer_set_period(1000);
    stateS1 = 1;
    break;
  case 1:
    red_on = 0;
    buzzer_set_period(0);
    stateS1 = 0;
    break;
  }
  return 1;
}
