/*
 * DieSketch.cpp
 *
 *  Created on: Oct 23, 2011
 *      Author: dkinzer
 */
#include <WProgram.h>
#include "Die.h"
// #include "pure_virtual.cpp"

int blinks = 0;
Die die;

void setup() {
	Serial.begin(BAUD_RATE); // opens serial port
	pinMode(LED, OUTPUT);
	pinMode(BUTTON, INPUT);
}

void loop() {

	blinks = die.Toss();

	die.Blink(blinks);

}
