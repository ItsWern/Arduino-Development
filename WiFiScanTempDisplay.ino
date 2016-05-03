/*
 *  This sketch is for initial testing of the ESP8266. 
 *  including WiFi testing and I2C devices (BME280 and SSD1306)
 */
#include "ESP8266WiFi.h"
#include <Adafruit_BME280.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SEALEVELPRESSURE_HPA (1013.25)

#define OLED_RESET 3
Adafruit_SSD1306 display(OLED_RESET);


Adafruit_BME280 bme; // I2C


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
  delay(2000);
  // Clear the buffer.
  display.clearDisplay();

  Serial.println("Setup done");
}

void loop() {

  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
    }
  }
  Serial.println("");

  
  // Wait a bit before scanning again
  delay(1000);

  displayHeader();
  displayTemp();
  delay(1000);
  display.clearDisplay();

  displayHeader();
  displayHumidity();
  delay(1000);
  display.clearDisplay();

  displayHeader();
  displayPressure();
  delay(1000);
  display.clearDisplay();

  displayHeader();
  displayAltitude();
  delay(1000);
  display.clearDisplay();

}

void displayHeader()
{
  display.setCursor(0,0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println("Currently");
}

void displayTemp()
{
  float degreesF;

  display.println("Temp: ");
  degreesF = (bme.readTemperature()* 9)/ 5 + 32;
  display.print(degreesF);
  display.println(" F");

  display.display();
}

void displayPressure()
{
  display.println("Pressure: ");
  display.print(bme.readPressure() / 100.0F);
  display.println(" hPa");

  display.display();
}

void displayHumidity()
{
  display.println("Humidity: ");
  display.print(bme.readHumidity());
  display.println(" %");

  display.display();
}

void displayAltitude()
{
    display.println("Altitude: ");
    display.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    display.println(" m");

    display.display();
}

