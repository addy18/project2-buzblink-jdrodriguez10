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


void buzzer_advance(){
  if (state2_status) freq += 225;
  else freq -= 450;
  short cycles = 2000000/freq;
  buzzer_set_period(cycles);
}


void state_up()
{
  state2_status = 1; red_on = 1; green_on = 0;
  led_changed = 1; led_update();
}


void state_down()
{
  state2_status = 0; red_on = 0; green_on = 1;
  led_changed= 1; led_update();
}


void dim_leds(char x){
  static short dimCount = 0;
  switch(dimCount % x){
  case 0: red_on = 1; green_on = 1; dimCount++; break;
  case 1: red_on = 0; green_on = 0; dimCount++; break;
  default: red_on = 0; green_on = 0; dimCount++; break;
  }
  led_changed = 1;
  led_update();
}
