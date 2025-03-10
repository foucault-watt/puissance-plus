#include <TimerOne.h>
#include <Wire.h>
#include <Arduino.h>
#include "ht1632.h"
#include <avr/pgmspace.h>

/////////////////////////////////////////////////////////////////////////////////////
// ARCHITECTURE MATERIELLE

/////////////////////////////////////////////////////////////////////////////////////
// FONCTION PERIODIQUE
int compteur = 0;

/////////////////////////////////////////////////////////////////////////////////////
// PROTOTYPES

void fnPeriodique();

/////////////////////////////////////////////////////////////////////////////////////
// SETUP
void setup () {

  ht1632_setup();                       // initialise the wire library and hardware
  Serial.begin(9600);
  Wire.begin();
  setup7Seg();
  cls();

  Timer1.initialize(25000); // 25ms
  Timer1.attachInterrupt( fnPeriodique );

  // Initialisation du générateur aléatoire
  randomSeed(analogRead(6)); // bruit électromagnétique sur Entrée analogique 6

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
  Wire.endTransmission();            // stop talutilsing to th
}

/////////////////////////////////////////////////////////////////////////////////////
// LOOP

void loop () {
  for (int i = 0; i >= 3; i++) {
     int j=3;
        ht1632_plot(j,i, RED);
    
}
}

/////////////////////////////////////////////////////////////////////////////////////
// FN PERIODIQUE

void fnPeriodique() {
  // Comptage du temps
  compteur++;

}

