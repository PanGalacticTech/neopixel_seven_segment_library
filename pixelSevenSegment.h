/* ~~~~** Neopixel **~~~~** Seven Segment Display Library **~~~~~
   pixleSevenSegment.h

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




#ifndef pixelSevenSegment_h
#define pixelSevenSegment_h

#if (ARDUINO >=100)
#include <Arduino.h>
#else
#include <wProgram.h>
#endif


#include <FastLED.h>
//#include "globals.h"


FASTLED_USING_NAMESPACE      // This line defines which template is used from the library for constructor or setup


#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif



#define DATA_PIN    2                   // Data pin connection to LED string
//#define CLK_PIN   4                      // Not required for 3 pin LED strings
#define LED_TYPE    WS2812B                // This must be set to match the specific LED driver used

//#define LED_TYPE WS2811_400               //

#define COLOR_ORDER GRB

#define NUM_LEDS 126                             //Number of LEDS in 6 digits (will add more for the sign and dots later  need at least 7 for +- and 4 for dots  

#define NUM_DIGITS 6
#define LED_PER_SEG 3
#define ADDITIONAL_LEDS 21

#define TOTAL_LEDS 147      //((number_digits * leds_per_segment * 7)+extra_leds);

#define MAX_BRIGHTNESS 20






class pixelSevenSegment {

  public:

    CRGBArray<TOTAL_LEDS> ledString;

    //Constructor

    pixelSevenSegment(int number_digits = 6, int leds_per_segment = 3, int extra_leds = 21):


      total_leds((number_digits * leds_per_segment) + extra_leds),
      ledString()
      // tell FastLED about the LED strip configuration

    {
    }



    //::::::::::::::::::::::::::::::::::::::::::::::::::::::: Neopixel to Seven Segment Variables :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
    // The following data structures are intended to make the neopixles function effectivly like a traditional 7 segment display.


    struct digitSeg {                                // Data Structure to contain the data for "characters" divided up into 7 segments. Each segment can be on or off.
      uint8_t A;                                       // Segments mirror the wiring of traditional 7 segment display
      uint8_t B;
      uint8_t C;
      uint8_t D;
      uint8_t E;
      uint8_t F;
      uint8_t G;
    };



    void sevenSegSetup();

    void setDigit (digitSeg current, int8_t digitNumber, uint8_t red, uint8_t green, uint8_t blue );

    void setDots(uint8_t red, uint8_t green, uint8_t blue);

    int total_leds;


    // These values are passed bit arrays to print specific digits to each character in the display

    digitSeg seconds0;                                          // Holds the current displayed least significant seconds figure
    digitSeg seconds1;                                           // holds the current displayed most significant seconds figure

    digitSeg minutes2;                                          // Holds the current displayed least significant minuitesfigure
    digitSeg minutes3;                                           // holds the current displayed most significant minuites figure

    digitSeg hours4;                                          // Holds the current displayed least significant hours figure
    digitSeg hours5;                                           // holds the current displayed most significant hours figure

    digitSeg plusminus;                                       // Holds the positive or negative (might be a better way of doing this as it only requires 2 bytes of data, not 7
    digitSeg dots;                                             // holds the values for the dots (also could be done differently, as it only needs one bit for control, but 4 LED id's


    digitSeg displayedDigits[6] = {seconds0, seconds1, minutes2, minutes3, hours4, hours5};   // holds the data values above in an array making referencing in functions and loops easier.





    // these constant data structures hold the arrays for each unique character. Bits mirror the segments of a typical 7 segment display. Other letters and Characters can be added by adding arrays

    const digitSeg zero    = {1, 1, 1, 1, 1, 1, 0};
    const digitSeg one     = {0, 1, 1, 0, 0, 0, 0};
    const digitSeg two     = {1, 1, 0, 1, 1, 0, 1};
    const digitSeg three   = {1, 1, 1, 1, 0, 0, 1};
    const digitSeg four    = {0, 1, 1, 0, 0, 1, 1};
    const digitSeg five    = {1, 0, 1, 1, 0, 1, 1};
    const digitSeg six     = {1, 0, 1, 1, 1, 1, 1};
    const digitSeg seven   = {1, 1, 1, 0, 0, 0, 0};
    const digitSeg eight   = {1, 1, 1, 1, 1, 1, 1};
    const digitSeg nine    = {1, 1, 1, 0, 0, 1, 1};


    digitSeg alldigits[10] = {zero, one, two, three, four, five, six, seven, eight, nine};   // array to hold data structures above. Array number matches the character being recalled.

    const digitSeg blank = {0, 0, 0, 0, 0, 0, 0};

    // This can be accessed as:

    //alldigits[0];   // contains the display data for the character 0
    //alldigits[1];   // Contains the display data for the character 1
    // et al

    //Other Letters and characters that could be easily printed (needs arrays to be filled in);

    digitSeg A   = {1, 1, 1, 0, 1, 1, 1};
    digitSeg E   = {1, 0, 0, 1, 1, 1, 1};
    digitSeg i   = {0, 0, 1, 0, 0, 0, 0};
    digitSeg o   = {0, 0, 1, 1, 1, 0, 1};
    digitSeg U   = {0, 1, 1, 1, 1, 1, 0};
    digitSeg u   = {0, 0, 1, 1, 1, 0, 0};

    digitSeg B;
    digitSeg C;
    digitSeg F;
    digitSeg H;
    digitSeg J;

    digitSeg P;
    digitSeg S;



    digitSeg b;
    digitSeg c;
    digitSeg d;
    digitSeg g;
    digitSeg h;
    digitSeg l;
    digitSeg n;
    digitSeg p;
    digitSeg qu;
    digitSeg r;
    digitSeg t;
    digitSeg y;
    //::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





  private:










};




#endif
