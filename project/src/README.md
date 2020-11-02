Project 2: Blinky-Buzzy Toy
===========================

## Description:

Interrupt-driven toy program that flashes the LEDs and makes sounds depending
on which of the 4 switches you press.

## Compile and Run:

* Inside project/src enter (make all). A file called "toy.elf" will be generated.
* Plug in the MSP430 to your computer, and inside project/src type (make load).
* The program will now run on the MSP430.
* You can type (make clean) to remove all compiled and .o files.

## Button Functions:

* S1 will turn on/off the red LED with a high pitch and turn on/off green LED
  with low pitch.
* S2 will act like a siren with a increasing pitch with the red LED on and
  decreasing pitch with the green LED on.
* S3 will begin to dim the LEDs with the pitch decreasing with it.
* S4 will turn off the LEDs and buzzer(sound).
