/**************************************************************************/
/*!
    @file     xplane_dials.ino
    @author   @DavidHowlett (David Howlett, Peter Dobson)
    @license  BSD (see license.txt)

	This example uses an array of 4 sensors
	
    @section  HISTORY

    v1.0.0 - First release

*/
/**************************************************************************/

#include <ams_as5048b.h>
//#include <FlightSimFloat.h> // missing lib or struct ?

// the constant U_DEG means the results are given in degrees
#define U_DEG 3

// declare an array of sensors
# define NUM_SENSORS 4
AMS_AS5048B sensors[NUM_SENSORS] = {AMS_AS5048B(0x40), AMS_AS5048B(0x41), AMS_AS5048B(0x42), AMS_AS5048B(0x43)};

//FlightSimFloat angles[NUM_SENSORS]; //- to be fixed

void setup() {
	//Start serial
	Serial.begin(9600);
	while (!Serial) ; //wait until Serial ready
	
	
	for(int i=0;i<NUM_SENSORS;i++){
		sensors[i].begin();
	}
}

void loop() {
	for(int i=0;i<NUM_SENSORS;i++){
		Serial.print("auto gain: ");
		Serial.print(sensors[i].getAutoGain());
		Serial.print(" angle: ");
		//angles[i] = sensors[i].angleR(U_DEG,true); //- to be fixed
		//Serial.print(angles[i]); //- to be fixed
		Serial.print(sensors[i].angleR(U_DEG,true)); //- replaces the 2 lines above
		Serial.print(' ');
	}
	
	Serial.print('\n');
	//FlightSim.update(); //- to be fixed
	delay (5);
}