/*------------------------------------------------------------------------
  An Arduino library for the ESP8266 WiFi-serial bridge

  https://www.adafruit.com/product/2282

  The ESP8266 is a 3.3V device.  Safe operation with 5V devices (most
  Arduino boards) requires a logic-level shifter for TX and RX signals.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried and Phil Burgess for Adafruit Industries.
  MIT license, all text above must be included in any redistribution.
  ------------------------------------------------------------------------*/

#ifndef _SPACE_INVADERS_H_
#define _SPACE_INVADERS_H_

// Animation data 

static const unsigned char PROGMEM alien_a[] = {
  B00011000, 
  B00111100, 
  B01111110, 
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B10100101,

  B00011000, // This is the second frame for alien #1
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};

static const unsigned char PROGMEM alien_b[] = {

  B00000000, // First frame for alien #2
  B00111100,
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00100100,
  B11000011,

  B00111100, // Second frame for alien #2
  B01111110,
  B11011011,
  B11011011,
  B01111110,
  B00100100,
  B00100100,
  B00100100
};

static const unsigned char PROGMEM alien_c[] = {
  B00100100, // First frame for alien #3
  B00100100,
  B01111110,
  B11011011,
  B11111111,
  B11111111,
  B10100101,
  B00100100,

  B00100100, // Second frame for alien #3
  B10100101,
  B11111111,
  B11011011,
  B11111111,
  B01111110,
  B00100100,
  B01000010
};

static const unsigned char PROGMEM alien_d[] = {
  B00111100, // First frame for alien #4
  B01111110,
  B00110011,
  B01111110,
  B00111100,
  B00000000,
  B00001000,
  B00000000,

  B00111100, // Second frame for alien #4
  B01111110,
  B10011001,
  B01111110,
  B00111100,
  B00000000,
  B00001000,
  B00001000,

  B00111100, // Third frame for alien #4 (NOT a repeat of frame 1)
  B01111110,
  B11001100,
  B01111110,
  B00111100,
  B00000000,
  B00000000,
  B00001000,

  B00111100, // Fourth frame for alien #4 (NOT a repeat of frame 2)
  B01111110,
  B01100110,
  B01111110,
  B00111100,
  B00000000,
  B00000000,
  B00000000
};

static const unsigned char *aliens[] = {
	alien_a,
	alien_b,
	alien_c,
	alien_d
}; 

class animation  {
 public:
  animation();

  private:
  int16_t xpos, ypos, height, width, imageSize;
};

#endif // _ADAFRUIT_ESP8266_H_
