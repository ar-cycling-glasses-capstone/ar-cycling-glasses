/**************************************************************************
 *
 * Interfacing ESP8266 NodeMCU with ST7789 TFT display (240x240 pixel).
 * Graphics test example.
 * This is a free software with NO WARRANTY.
 * https://simple-circuit.com/
 *
 *************************************************************************/
/**************************************************************************
  This is a library for several Adafruit displays based on ST77* drivers.

  Works with the Adafruit 1.8" TFT Breakout w/SD card
    ----> http://www.adafruit.com/products/358
  The 1.8" TFT shield
    ----> https://www.adafruit.com/product/802
  The 1.44" TFT breakout
    ----> https://www.adafruit.com/product/2088
  as well as Adafruit raw 1.8" TFT display
    ----> http://www.adafruit.com/products/618

  Check out the links above for our tutorials and wiring diagrams.
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional).

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 *************************************************************************/

#include <Adafruit_GFX.h> // Core graphics library
// #include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <TFT_eSPI.h>

#include "lum.h"

// ST7789 TFT module connections
#define TFT_DC D1  // TFT DC  pin is connected to NodeMCU pin D1 (GPIO5)
#define TFT_RST D2 // TFT RST pin is connected to NodeMCU pin D2 (GPIO4)
#define TFT_CS D8  // TFT CS  pin is connected to NodeMCU pin D8 (GPIO15)
// initialize ST7789 TFT library with hardware SPI module
// SCK (CLK) ---> NodeMCU pin D5 (GPIO14)
// MOSI(DIN) ---> NodeMCU pin D7 (GPIO13)
// Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
TFT_eSPI tft = TFT_eSPI();

// float p = 3.1415926;

void setup(void)
{
    Serial.begin(9600);
    Serial.print("ST7789 TFT Bitmap Test");

    tft.begin(); // initialize a ST7789 chip
    // tft.setSwapBytes(true);                      // swap the byte order for pushImage() - corrects endianness

    tft.setRotation(2);
    tft.fillScreen(TFT_BLACK);
    tft.pushImage(0, 0, 240, 240, lum);
}

void loop()
{
    tft.invertDisplay(true);
    delay(500);
    tft.invertDisplay(false);
    delay(500);
}
