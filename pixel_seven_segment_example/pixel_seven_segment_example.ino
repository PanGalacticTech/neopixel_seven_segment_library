/* ~~~~** Neopixel **~~~~** Seven Segment Display Library **~~~~~


   Library to manage neopixel strips arranged into 7 segment display digits.
   The segments

   Setups:
   Number of LEDS in each Segment
   Number of Digits.

   Inputs:
   individual digit ID & Value
   hours, minutes, seconds as char strings or ints
   time as complete string
   current display colour
   specific digit colour


 * *
   Outputs:
   Data to Neopixel string

   Serial print of current displayed time/values



*/


//#include <FastLED.h>

#include <DateTime.h>
#include <autoDelay.h>
#include "pixelSevenSegment.h"

pixelSevenSegment countdownClock;

#include "animations.h"
#include "displayFunctions.h"



//#define NUM_LEDS   21                        // Number of LEDs in a single digit [Depreciated]







//@@@@@@@@@@@\\\ Options ///@@@@@@@@@@@@@@@@@@@


uint8_t maxBrightness = 20;                      // Define the max brightness of all LEDs. 0 - 255. 20-50 reccomended for testing: MUST use seperate 5v supply for full brightness operation! Do not use USB power!

//   N.B. on power consumption:
// At full brightness each LED can draw 60 mA

// 60 mA * 126 = 7560 mA = 7.6 A !
// including the 14 extra = 8.4 A
// These LEDs can draw a decent amount of current and require a decent PSU. 10A @ 5v Recommended




//@@@@@@@@@@@\\\ Options ///@@@@@@@@@@@@@@@@@@@



unsigned long updateDisplayDelay = 1000;  //   (will also be used to slow down printing to the serial monitor during testing)
unsigned long lastDisplayUpdate;        // save the time of the last update






autoDelay ledDelay;




void setup() {
  Serial.begin(115200);
 displaySetup();
}










void loop() {


  // Set up displayed digits with correct bit arrays for the current time
  countdownClock.displayedDigits[0] = countdownClock.alldigits[0];
  countdownClock.displayedDigits[1] = countdownClock.alldigits[1];
  countdownClock.displayedDigits[2] = countdownClock.alldigits[2];
  countdownClock.displayedDigits[3] = countdownClock.alldigits[3];
  countdownClock.displayedDigits[4] = countdownClock.alldigits[4];
  countdownClock.displayedDigits[5] = countdownClock.alldigits[5];



  //Set The digit with the data passed from presaved bit arrays

for (int q = 0; q < 6; q++){
  
  countdownClock.setDigit(countdownClock.displayedDigits[q], q, CURRENT_COLOUR.r, CURRENT_COLOUR.g, CURRENT_COLOUR.b);  // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)


  Serial.printf("Set Digit %i to ~", q);
  Serial.println("");

}


 // Print data to the LED strip

if (ledDelay.millisDelay(200)) {

  FastLED.show();    // trying this on every loop to see if it works more smoothly


}





}