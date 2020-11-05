


void printArora(uint32_t animationDelay = 500 ) {


  for (int j = 6; j > 0 ; j--) {


    countdownClock.setDigit(countdownClock.A, 6 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.r, 5 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.o, 4 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.r, 3 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.A, 2 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)
    countdownClock.setDigit(countdownClock.blank, 1 - j, 0, 130, 255); // Passed Arguments (digitSeg.bitarray, digitNumber, red, green, blue)

    Serial.printf("Set Digit %i 8" , j);
    Serial.println("");
    FastLED.show();
    delay(animationDelay);
  }


}
