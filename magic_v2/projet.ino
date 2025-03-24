#include <Wire.h>
#include <Arduino.h>
#include "ht1632.h"
#include <avr/pgmspace.h>
#include <TimerOne.h>

int k = 0;
int x = 0;
int y = 0;
int utils = 0;
int lastX = 0; // Store the last x coordinate
int lastY = 0; // Store the last y coordinate

#define BUTTON 2

void fnPeriodique();

void setup() {
    ht1632_setup();                   // initialise the wire library and hardware
    pinMode(BUTTON, INPUT_PULLUP);    // patte 2 en entrée
    Serial.begin(9600);
    Wire.begin();
    setup7Seg();
    cls();

    // Definition d'une fonction de traitement d'interruption pour le bouton
    Timer1.initialize(25000); // période des appels =  25000 microseconds = 25 ms
    Timer1.attachInterrupt(fnPeriodique); // toutes les 25ms, on appelera la fonction fnPeriodique

    Wire.beginTransmission(0x22);      // start talutilsing to the device
    Wire.write(0x09);                   // select the GPIO register
    Wire.write(Tab7Segts[0]);                   // set register value-all low
    Wire.endTransmission();            // stop talutilsing to the device

    Wire.beginTransmission(0x21);      // start talutilsing to the device
    Wire.write(0x09);                   // select the GPIO register
    Wire.write(Tab7Segts[0]);                   // set register value-all low
    Wire.endTransmission();            // stop talutilsing to the device

    Wire.beginTransmission(0x23);      // start talutilsing to the device
    Wire.write(0x09);                   // select the GPIO register
    Wire.write(Tab7Segts[0]);                   // set register value-all low
    Wire.endTransmission();            // stop talutilsing to the device

    Wire.beginTransmission(0x20);      // start talutilsing to the device
    Wire.write(0x09);                   // select the GPIO register
    Wire.write(Tab7Segts[0]);                   // set register value-all low
    Wire.endTransmission();            // stop talutilsing to the device

    for (int i = 4; i >= 0; i--) {
        for (int j = 0; j < 32; j++) {
            ht1632_plot(j, i, BLACK);
        }
    }
}

void add(int x, int y, bool player) {  // Declare parameter types
  if (player){
    coolor = RED;
  }
  else{
    coolor = GREEN;
  }

  ht1632_plot( (2*x)+8 , 2*y , add);
  ht1632_plot( (2*x)+9 , 2*y , add);
  ht1632_plot( (2*x)+8 , (2*y)+1 , add);
  ht1632_plot( (2*x)+9 , (2*y)+1 , add);
}

void loop() {
  coolor(4,6,true); 
}
void fnPeriodique() {

}
