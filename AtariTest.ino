/*
 *  This sketch demonstrates how to scan WiFi networks. 
 *  The API is almost the same as with the WiFi Shield library, 
 *  the most obvious difference being the different file you need to include:
 */
#include "ESP8266WiFi.h"
#include <Adafruit_BME280.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Space_Invaders.h>
#define SEALEVELPRESSURE_HPA (1013.25)

#define OLED_RESET 3
Adafruit_SSD1306 display(OLED_RESET);


Adafruit_BME280 bme; // I2C

#define NUMFLAKES 3
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 8 
#define LOGO16_GLCD_WIDTH  8 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

static const unsigned char PROGMEM oneup16_glcd_bmp[] =
{ 0x0f, 0xf0,
  0x19, 0x98,
  0x31, 0x8c,
  0x73, 0xce,
  0x5f, 0xfa,
  0xcc, 0x33,
  0x88, 0x11,
  0x88, 0x11,
  0x98, 0x19,
  0xfc, 0x3f,
  0xff, 0xff,
  0xf2, 0x4f,
  0x62, 0x46,
  0x20, 0x04,
  0x30, 0x0c,
  0x1f, 0xf8 };
  
void setup() {
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  
    if (!bme.begin()) {
      Serial.println("Could not find a valid BME280 sensor, check wiring!");
      Serial.print("Looking for BME280 at:");
      Serial.println(bme.readi2caddr());
      Serial.print("SDA: ");
      Serial.print(SDA);
      Serial.print("   SCL: ");
      Serial.println(SCL);
    while (1);
    }

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);
  // Clear the buffer.
  display.clearDisplay();

  Serial.println("Setup done");
}

void loop() {

  // draw a bitmap icon and 'animate' movement
  testdrawbitmap(alien_b, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);
}


void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) 
{
  const uint8_t *pBitmap;
  uint8_t icons[NUMFLAKES][3];
  
  // initialize
  for (uint8_t f=0; f< NUMFLAKES; f++) 
  {
    icons[f][XPOS] = 0;
    icons[f][YPOS] = random(16, (display.height()-16));
    icons[f][DELTAY] = random(5) + 1;
  }

  while (1) 
  {
    for (uint8_t offset=0; offset<2; offset++)
    {
      // draw each icon
      for (uint8_t f=0; f< NUMFLAKES; f++) 
      {
        pBitmap = aliens[f] + offset*8;
        display.drawBitmap(icons[f][XPOS], icons[f][YPOS], pBitmap, w, h, WHITE);
      }
      display.display();
      delay(200);
      
      // then erase it + move it
      for (uint8_t f=0; f< NUMFLAKES; f++) 
      {
        pBitmap = aliens[f] + offset*8;
        display.drawBitmap(icons[f][XPOS], icons[f][YPOS], pBitmap, w, h, BLACK);
        // move it
        icons[f][XPOS] += icons[f][DELTAY];
        
        // if its gone, reinit
        if (icons[f][XPOS] > display.width()) 
        {
          icons[f][XPOS] = 0;
          icons[f][YPOS] = random(16, (display.height()-16));
          icons[f][DELTAY] = random(5) + 1;
        }
      }
     }
  }
}

