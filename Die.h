/*
 * Die.h
 *
 *  Created on: Oct 23, 2011
 *      Author: dkinzer
 */

#ifndef DIE_H_
#define DIE_H_
#endif /* DIE_H_ */

const long  BAUD_RATE = 115200; // Baud Rate for the Arduino Controller. It's hardware dependent.
const int  LED = 12; // LED pin
const int  BUTTON = 7; // Input pin connected to pushbutton
const int  FACES = 6;
const int  SEED = 5; // Open analog input as random seed generator
const int  BLINK_DELAY = 500;


// Class Die decleration.
class Die {
private:
	int faces;
	int face_up;
	int val; // State of pin variable
	int old_val; // Stores previous pin state
	int state;

public:
	Die();
	int Toss();
	void setFaces(int faces);
	void Blink(int blinks);
	int getFaces();
};

