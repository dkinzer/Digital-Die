/*
 * die.cpp
 *
 *  Created on: Oct 23, 2011
 *      Author: dkinzer
 */

#include <WProgram.h>
#include "Die.h"

Die::Die() {
	val = 0; // State of pin variable
	old_val = 0; // Stores previous pin state
	state = 0; // Stores the current stae of light.  either 1 for "on" or 0 for "off".
	faces = FACES;
}
int Die::Toss() {
	randomSeed(analogRead(SEED));
	face_up = random(1, faces + 1);
	return face_up;
}

void Die::Blink(int blinks) {
	old_val = val;

	val = digitalRead(BUTTON);

	for (int i = 0; i < blinks; i++) {
		//Check whether input is HIGH (button pressed)
		if ((val == HIGH) && (old_val == LOW)) {
			state = 1 - state;
			delay(BLINK_DELAY);
		}
		if (state == 1) {
			digitalWrite(LED, HIGH); // Turn LED on.
			delay(BLINK_DELAY);
			digitalWrite(LED, LOW); // Turn off
			state = 0;
		} else {
			digitalWrite(LED, LOW); //Default should be off
		}
	}
}

void Die::setFaces(int faces) {
	this->faces = faces;
}

int Die::getFaces() {
	return faces;
}

