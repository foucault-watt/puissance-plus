// #include <Wire.h>
// #include <Arduino.h>
// #include "ht1632.h"
// #include <avr/pgmspace.h>
// int k=0;
// int utils=0;


// void setup () { 
// 	ht1632_setup();                       // initialise the wire library and hardware  
// 	Serial.begin(9600);
//         Wire.begin();
// 	setup7Seg();    
// 	cls();

//   Wire.beginTransmission(0x22);      // start talutilsing to the device
//   Wire.write(0x09);                   // select the GPIO register
//   Wire.write(Tab7Segts[0]);                   // set register value-all low
//   Wire.endTransmission();            // stop talutilsing to the device

//   Wire.beginTransmission(0x21);      // start talutilsing to the device
//   Wire.write(0x09);                   // select the GPIO register
//   Wire.write(Tab7Segts[0]);                   // set register value-all low
//   Wire.endTransmission();            // stop talutilsing to the device

//   Wire.beginTransmission(0x23);      // start talutilsing to the device
//   Wire.write(0x09);                   // select the GPIO register
//   Wire.write(Tab7Segts[0]);                   // set register value-all low
//   Wire.endTransmission();            // stop talutilsing to the device

// }

// void loop () { 
//   for (int i = 0; i < 15; i++) {
//       for (int j = 0; j < 32; j++) {
//           ht1632_plot(j,i, ORANGE);
//       }
//   }

//   for (int i = 15; i >= 0; i--) {
//     for (int j = 0; j < 32; j++) {
//         ht1632_plot(j,i, RED);
//     }
// }

// //   for (int i = 0; i < 15; i++) {
// //       for (int j = 0; j < 32; j++) {
// //           ht1632_plot(j,i, GREEN);
// //       }
// //   }

// //   for (int i = 15; i >= 0; i--) {
// //     for (int j = 0; j < 32; j++) {
// //         ht1632_plot(j,i, BLACK);
// //     }
// // }

//   k+=1;
//   utils=k;
  

//   if (utils/4096 != 0){
//     Wire.beginTransmission(0x23);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[utils/4096]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device
//     utils= utils % 4096;
//   }

//   if (utils/256 != 0){
//     Wire.beginTransmission(0x22);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[utils/256]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device
//     utils= utils % 256;
//   }

//   if (utils/16 != 0){
//     Wire.beginTransmission(0x21);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[utils/16]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device
//     utils= utils % 16;
//   }

//   if (utils/1 != 0){
//     Wire.beginTransmission(0x20);      // start talutilsing to the device
//     Wire.write(0x09);                   // select the GPIO register
//     Wire.write(Tab7Segts[utils/1]);                   // set register value-all low
//     Wire.endTransmission();            // stop talutilsing to the device
//     utils= utils % 1;
//   }

// }



