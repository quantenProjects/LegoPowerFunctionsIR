
#include <wiringPi.h>

#include <stdio.h>

#include <math.h>

#include <stdlib.h> 

int pin;

int send(int time) {
	digitalWrite(pin, 0);
	delayMicroseconds(156);
	digitalWrite(pin,1);
	delayMicroseconds(26*time);
}


int main(int argc, char *argv[]) {

  // Starte die WiringPi-Api (wichtig)
  if (wiringPiSetup() == -1)
    return 1;

  pin = atoi(argv[1]);
  
  unsigned int data = atol(argv[2]);
  // Wichtig: Hier wird das WiringPi Layout verwendet 
  pinMode(7, OUTPUT);

	
	int i;
	unsigned int temp = data;
	send(39);
	for(i=15; i >= 0; i--) {
		temp = data;
		if (temp & ( (unsigned int) pow(2,i) )) {
			//printf("1");
			send(21);
		} else {
			//printf("0");
			send(10);
		}
	}
	send(39);
	digitalWrite(7, 0);
	return 0;
	//digitalWrite(7, 1);
  /*while(0) {
    // LED an
    digitalWrite(7, 1);

    // Warte 100 ms
    delay(1000);

    // LED aus
    digitalWrite(7, 0);

    // Warte 100 ms
    delay(1000);
  }*/
}

