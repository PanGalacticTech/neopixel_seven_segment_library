


void displaySetup(){
 Serial.println("Clock Initializing...");

  countdownClock.sevenSegSetup();

  Serial.println("Seven Seg Setup");
  

  CURRENT_COLOUR = countdownClock.pureWhite;

  
  // Preset the starting LED colour, can be changed later in program
  delay(100);
  countdownClock.setDigitsBlank();   // Set all digits to blank
  delay (200);
  FastLED.show();
  Serial.println("||    ~~Set Digits Blank~~    ||");


  delay(500);

  for (int j = 0; j < 6 ; j++) {
    countdownClock.setDigit(countdownClock.alldigits[8], j, CURRENT_COLOUR.r, CURRENT_COLOUR.g, CURRENT_COLOUR.b);  // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    Serial.printf("Set Digit %i 8" , j);
    Serial.println("");
    FastLED.show();
    delay(100);
  }



  delay(1000);
  countdownClock.setDigitsBlank();   // Set all digits to blank
  delay(100);
  FastLED.show();
  Serial.println("Setting Digits Blank");
  delay(500);

  //countdownClock.setAllDigitsX(countdownClock.H, 255, 255, 255);

  printArora();
  delay(100);
  FastLED.show();
  Serial.println("Setup Complete, Clock Starting:");

  delay(2000);
  countdownClock.setDigitsBlank();   // Set all digits to blank
  delay(100);
  FastLED.show();

}
