// #include <Wire.h>
// #include <Arduino.h>
// #include "ht1632.h"
// #include <avr/pgmspace.h>
// #include <TimerOne.h>

// int k = 0;
// int x = 0;
// int y = 0;
// int utils = 0;
// volatile bool direction = true; // true pour aller vers la droite, false pour aller vers la gauche
// volatile bool changeDirection = false; // Flag to indicate direction change
// int lastX = 0; // Store the last x coordinate
// int lastY = 0; // Store the last y coordinate

// #define BUTTON 2

// void fnPeriodique();

// void setup() {
//     ht1632_setup();                       // initialise the wire library and hardware
//     pinMode(BUTTON, INPUT_PULLUP);    // patte 2 en entrée
//     Serial.begin(9600);
//     Wire.begin();
//     setup7Seg();
//     cls();

//     // Definition d'une fonction de traitement d'interruption pour le bouton
//     Timer1.initialize(25000); // période des appels =  25000 microseconds = 25 ms
//     Timer1.attachInterrupt(fnPeriodique); // toutes les 25ms, on appelera la fonction fnPeriodique

//     Wire.beginTransmission(0x22);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[0]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device

//     Wire.beginTransmission(0x21);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[0]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device

//     Wire.beginTransmission(0x23);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[0]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device

//     Wire.beginTransmission(0x20);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[0]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device

//     for (int i = 4; i >= 0; i--) {
//         for (int j = 0; j < 32; j++) {
//             ht1632_plot(j, i, BLACK);
//         }
//     }
// }

// int count(int i, int j) {
//     Wire.beginTransmission(0x23);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[j / 10]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device
//     j %= 10;

//     Wire.beginTransmission(0x22);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[j]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device

//     Wire.beginTransmission(0x21);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[i]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device
// }

// void loop() {
//     if (changeDirection) {
//         // Turn off the last pixel before changing direction
//         ht1632_plot(lastX, lastY, BLACK);
//         direction = !direction; // Inverser la direction
//         changeDirection = false; // Reset the flag
//     }

//     if (direction) {
//         for (int i = 0; i < 16; i++) {
//             for (int j = 0; j < 32; j++) {
//                 ht1632_plot(j, i, GREEN);

//                 if (i == 0 && j == 0) {
//                     ht1632_plot(31, 15, BLACK);
//                 }
//                 else if (j == 0) {
//                     ht1632_plot(31, i - 1, BLACK);
//                 }
//                 else {
//                     ht1632_plot(j - 1, i, BLACK);
//                 }
//                 count(i, j);

//                 // Store the current pixel coordinates
//                 lastX = j;
//                 lastY = i;

//                 // Check for direction change within the loop
//                 if (changeDirection) {
//                     ht1632_plot(lastX, lastY, BLACK); // Turn off the last pixel
//                     direction = !direction;
//                     changeDirection = false;
//                     return; // Exit the loop to start in the new direction
//                 }
//             }
//         }
//     } else {
//         for (int i = 15; i >= 0; i--) {
//             for (int j = 31; j >= 0; j--) {
//                 ht1632_plot(j, i, RED);

//                 if (i == 15 && j == 31) {
//                     ht1632_plot(0, 0, BLACK);
//                 }
//                 else if (j == 31) {
//                     ht1632_plot(0, i + 1, BLACK);
//                 }
//                 else {
//                     ht1632_plot(j + 1, i, BLACK);
//                 }
//                 count(i, j);

//                 // Store the current pixel coordinates
//                 lastX = j;
//                 lastY = i;

//                 // Check for direction change within the loop
//                 if (changeDirection) {
//                     ht1632_plot(lastX, lastY, BLACK); // Turn off the last pixel
//                     direction = !direction;
//                     changeDirection = false;
//                     return; // Exit the loop to start in the new direction
//                 }
//             }
//         }
//     }
// }
// //
// void fnPeriodique() {
//     static bool lastButtonState = HIGH;
//     bool currentButtonState = digitalRead(BUTTON);

//     if (currentButtonState == LOW && lastButtonState == HIGH) {
//         changeDirection = true; // Set the flag to change direction
//         Serial.print("knf");
//     }

//     lastButtonState = currentButtonState;
// }
