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



//#define NUM_LEDS   21                        // Number of LEDs in a single digit [Depreciated]







//@@@@@@@@@@@\\\ Options ///@@@@@@@@@@@@@@@@@@@


uint8_t maxBrightness = 20;                      // Define the max brightness of all LEDs. 0 - 255. 20-50 reccomended for testing: MUST use seperate 5v supply for full brightness operation! Do not use USB power!

//   N.B. on power consumption:
// At full brightness each LED can draw 60 mA

// 60 mA * 126 = 7560 mA = 7.6 A !
// including the 14 extra = 8.4 A
// These LEDs can draw a decent amount of current and require a decent PSU. 10A @ 5v Recommended


int8_t colourSelect = 0;                        // selectes the display colour. 0 = skyrora blue, 1 = offwhite, 2 = yellowOrange. (currently cycles through each)

//@@@@@@@@@@@\\\ Options ///@@@@@@@@@@@@@@@@@@@



unsigned long updateDisplayDelay = 1000;  //   (will also be used to slow down printing to the serial monitor during testing)
unsigned long lastDisplayUpdate;        // save the time of the last update



pixelSevenSegment countdownClock;

autoDelay ledDelay;



void setup() {

  countdownClock.sevenSegSetup();

  //  currentColour = skyroraBlue;                                                                                 // Preset the starting LED colour, can be changed later in program


 countdownClock.setDigit(countdownClock.zero, 0, 0, 0, 0);

}










void loop() {



  countdownClock.setDigit(countdownClock.blank, 0, 0, 75, 255);       //passed (digitSeg.CHARACTER_NAME, digit_Number, red, green, blue)



if (ledDelay.millisDelay(200)){

  FastLED.show();    // trying this on every loop to see if it works more smoothly

  
}


delay(1000);


}
