char ssid[] = "Wifi Name";
char pass[] = "Password";
String Name = "Name";
String Post = "Post";
String status_string = "N/A";
int Door_out_pin = 19;
int Lights_out_pin = 21;
int LCD_pin = 22;
int extra_pin = 23;



#define BLYNK_TEMPLATE_ID ""
#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;
int IN[7] = {0, 0, 0, 0, 0, 0, 0};
BlynkTimer timer;
BLYNK_WRITE(V0)
{
  IN[0] = param.asInt();
  Blynk.virtualWrite(V0, IN[0]);
  Serial.println("I am here 0");

}
BLYNK_WRITE(V1)
{
  IN[1] = param.asInt();
  Blynk.virtualWrite(V1, IN[1]);
}
BLYNK_WRITE(V2)
{
  if (V2 == 1)
  {
    Blynk.virtualWrite(V2, V2);
    Blynk.virtualWrite(V4, 0);
    Blynk.virtualWrite(V5, 0);
    Blynk.virtualWrite(V6, 0);
    Blynk.virtualWrite(V7, 0);
    Blynk.virtualWrite(V10, 0);
    status_string = "Available";
  }
  else
  {
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V4, 0);
    Blynk.virtualWrite(V5, 0);
    Blynk.virtualWrite(V6, 0);
    Blynk.virtualWrite(V7, 0);
    Blynk.virtualWrite(V10, 0);
    status_string = "Not Available";
  }
}
BLYNK_WRITE(V7)
{
  Blynk.virtualWrite(V7, V7);
  Blynk.virtualWrite(V2, 0);
  Blynk.virtualWrite(V4, 0);
  Blynk.virtualWrite(V5, 0);
  Blynk.virtualWrite(V6, 0);
  Blynk.virtualWrite(V10, 0);
  status_string = "In Meeting";
}
BLYNK_WRITE(V4)
{
  Blynk.virtualWrite(V7, 0);
  Blynk.virtualWrite(V2, 0);
  Blynk.virtualWrite(V4, V4);
  Blynk.virtualWrite(V5, 0);
  Blynk.virtualWrite(V6, 0);
  Blynk.virtualWrite(V10, 0);
  status_string = "Busy";
}
BLYNK_WRITE(V5)
{
  Blynk.virtualWrite(V7, 0);
  Blynk.virtualWrite(V2, 0);
  Blynk.virtualWrite(V4, 0);
  Blynk.virtualWrite(V5, V5);
  Blynk.virtualWrite(V6, 0);
  Blynk.virtualWrite(V10, 0);
  status_string = "Break";
}
BLYNK_WRITE(V6)
{
  Blynk.virtualWrite(V7, 0);
  Blynk.virtualWrite(V2, 0);
  Blynk.virtualWrite(V4, 0);
  Blynk.virtualWrite(V5, 0);
  Blynk.virtualWrite(V10, 0);
  Blynk.virtualWrite(V6, V6);
  status_string = "On Leave";
}
BLYNK_WRITE(V8)
{
  IN[2] = param.asInt();
  Blynk.virtualWrite(V8, IN[2]);
}
BLYNK_WRITE(V9)
{
  IN[3] = param.asInt();
  Blynk.virtualWrite(V9, IN[3]);
}
BLYNK_CONNECTED()
{
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  //Blynk.virtualWrite(V2, millis() / 1000);
}
void Setup_Blynk()
{
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, myTimerEvent);
}
void Read_Switch()
{
  Blynk.run();
  timer.run();
}




void set_IO_Pins()
{
  if (IN[0] == 1) //Lights
  {
    digitalWrite(Door_out_pin, HIGH);
  }
  else if (IN[0] == 0)
  {
    digitalWrite(Door_out_pin, LOW);
  }
  if (IN[1] == 1) //Lights
  {
    digitalWrite(Lights_out_pin, HIGH);
  }
  else if (IN[1] == 0)
  {
    digitalWrite(Lights_out_pin, LOW);
  }
  if (IN[2] == 1) //LCD
  {
    digitalWrite(LCD_pin, HIGH);
  }
  else if (IN[2] == 0)
  {
    digitalWrite(LCD_pin, LOW);
  }
  if (IN[3] == 1) //Extra
  {
    digitalWrite(extra_pin, HIGH);
  }
  else if (IN[3] == 0)
  {
    digitalWrite(extra_pin, LOW);
  }
}
#include <GPxMatrix.h>
#include "smileytongue24.h"

#define P_A    32
#define P_B    17
#define P_C    33
#define P_D    16
#define P_E    5
#define P_CLK  0
#define P_LAT  2
#define P_OE   4

//GPxMatrix *matrix = new GPxMatrix(P_A, P_B, P_C, P_D, P_CLK, P_LAT, P_OE, true, 64, listrgbpins);

GPxMatrix *matrix = new GPxMatrix(P_A, P_B, P_C, P_D, P_CLK, P_LAT, P_OE, true, 64);
#define clear()          fillScreen(0)
#define show()           swapBuffers(true)
#define Color(x,y,z)     Color888(x,y,z)

// Define matrix width and height.
#define mw 64
#define mh 16
#define LED_BLACK           0
#define LED_RED_VERYLOW    (3 <<  11)
#define LED_RED_LOW        (7 <<  11)
#define LED_RED_MEDIUM     (15 << 11)
#define LED_RED_HIGH       (31 << 11)
#define LED_GREEN_VERYLOW  (1 <<  5)
#define LED_GREEN_LOW      (15 << 5)
#define LED_GREEN_MEDIUM   (31 << 5)
#define LED_GREEN_HIGH     (63 << 5)
#define LED_BLUE_VERYLOW     3
#define LED_BLUE_LOW         7
#define LED_BLUE_MEDIUM     15
#define LED_BLUE_HIGH       31
#define LED_ORANGE_VERYLOW (LED_RED_VERYLOW + LED_GREEN_VERYLOW)
#define LED_ORANGE_LOW     (LED_RED_LOW     + LED_GREEN_LOW)
#define LED_ORANGE_MEDIUM  (LED_RED_MEDIUM  + LED_GREEN_MEDIUM)
#define LED_ORANGE_HIGH    (LED_RED_HIGH    + LED_GREEN_HIGH)
#define LED_PURPLE_VERYLOW (LED_RED_VERYLOW + LED_BLUE_VERYLOW)
#define LED_PURPLE_LOW     (LED_RED_LOW     + LED_BLUE_LOW)
#define LED_PURPLE_MEDIUM  (LED_RED_MEDIUM  + LED_BLUE_MEDIUM)
#define LED_PURPLE_HIGH    (LED_RED_HIGH    + LED_BLUE_HIGH)
#define LED_CYAN_VERYLOW   (LED_GREEN_VERYLOW + LED_BLUE_VERYLOW)
#define LED_CYAN_LOW       (LED_GREEN_LOW     + LED_BLUE_LOW)
#define LED_CYAN_MEDIUM    (LED_GREEN_MEDIUM  + LED_BLUE_MEDIUM)
#define LED_CYAN_HIGH      (LED_GREEN_HIGH    + LED_BLUE_HIGH)
#define LED_WHITE_VERYLOW  (LED_RED_VERYLOW + LED_GREEN_VERYLOW + LED_BLUE_VERYLOW)
#define LED_WHITE_LOW      (LED_RED_LOW     + LED_GREEN_LOW     + LED_BLUE_LOW)
#define LED_WHITE_MEDIUM   (LED_RED_MEDIUM  + LED_GREEN_MEDIUM  + LED_BLUE_MEDIUM)
#define LED_WHITE_HIGH     (LED_RED_HIGH    + LED_GREEN_HIGH    + LED_BLUE_HIGH)
static const uint8_t PROGMEM
mono_bmp[][8] =
{
  { B10101010, // 0: checkered 1
    B01010101,
    B10101010,
    B01010101,
    B10101010,
    B01010101,
    B10101010,
    B01010101
  },
  { B01010101, // 1: checkered 2
    B10101010,
    B01010101,
    B10101010,
    B01010101,
    B10101010,
    B01010101,
    B10101010
  },
  { B00111100, // 2: smiley
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100
  },
  { B00111100, // 3: neutral
    B01000010,
    B10100101,
    B10000001,
    B10111101,
    B10000001,
    B01000010,
    B00111100
  },
  { B00111100, // 4; frowny
    B01000010,
    B10100101,
    B10000001,
    B10011001,
    B10100101,
    B01000010,
    B00111100
  },
};

static const uint16_t PROGMEM
RGB_bmp[][64] = {
  // 00: blue, blue/red, red, red/green, green, green/blue, blue, white
  { 0x100, 0x200, 0x300, 0x400, 0x600, 0x800, 0xA00, 0xF00,
    0x101, 0x202, 0x303, 0x404, 0x606, 0x808, 0xA0A, 0xF0F,
    0x001, 0x002, 0x003, 0x004, 0x006, 0x008, 0x00A, 0x00F,
    0x011, 0x022, 0x033, 0x044, 0x066, 0x088, 0x0AA, 0x0FF,
    0x010, 0x020, 0x030, 0x040, 0x060, 0x080, 0x0A0, 0x0F0,
    0x110, 0x220, 0x330, 0x440, 0x660, 0x880, 0xAA0, 0xFF0,
    0x100, 0x200, 0x300, 0x400, 0x600, 0x800, 0xA00, 0xF00,
    0x111, 0x222, 0x333, 0x444, 0x666, 0x888, 0xAAA, 0xFFF,
  },

  // 01: grey to white
  { 0x111, 0x222, 0x333, 0x555, 0x777, 0x999, 0xAAA, 0xFFF,
    0x222, 0x222, 0x333, 0x555, 0x777, 0x999, 0xAAA, 0xFFF,
    0x333, 0x333, 0x333, 0x555, 0x777, 0x999, 0xAAA, 0xFFF,
    0x555, 0x555, 0x555, 0x555, 0x777, 0x999, 0xAAA, 0xFFF,
    0x777, 0x777, 0x777, 0x777, 0x777, 0x999, 0xAAA, 0xFFF,
    0x999, 0x999, 0x999, 0x999, 0x999, 0x999, 0xAAA, 0xFFF,
    0xAAA, 0xAAA, 0xAAA, 0xAAA, 0xAAA, 0xAAA, 0xAAA, 0xFFF,
    0xFFF, 0xFFF, 0xFFF, 0xFFF, 0xFFF, 0xFFF, 0xFFF, 0xFFF,
  },

  // 02: low red to high red
  { 0x001, 0x002, 0x003, 0x005, 0x007, 0x009, 0x00A, 0x00F,
    0x002, 0x002, 0x003, 0x005, 0x007, 0x009, 0x00A, 0x00F,
    0x003, 0x003, 0x003, 0x005, 0x007, 0x009, 0x00A, 0x00F,
    0x005, 0x005, 0x005, 0x005, 0x007, 0x009, 0x00A, 0x00F,
    0x007, 0x007, 0x007, 0x007, 0x007, 0x009, 0x00A, 0x00F,
    0x009, 0x009, 0x009, 0x009, 0x009, 0x009, 0x00A, 0x00F,
    0x00A, 0x00A, 0x00A, 0x00A, 0x00A, 0x00A, 0x00A, 0x00F,
    0x00F, 0x00F, 0x00F, 0x00F, 0x00F, 0x00F, 0x00F, 0x00F,
  },

  // 03: low green to high green
  { 0x010, 0x020, 0x030, 0x050, 0x070, 0x090, 0x0A0, 0x0F0,
    0x020, 0x020, 0x030, 0x050, 0x070, 0x090, 0x0A0, 0x0F0,
    0x030, 0x030, 0x030, 0x050, 0x070, 0x090, 0x0A0, 0x0F0,
    0x050, 0x050, 0x050, 0x050, 0x070, 0x090, 0x0A0, 0x0F0,
    0x070, 0x070, 0x070, 0x070, 0x070, 0x090, 0x0A0, 0x0F0,
    0x090, 0x090, 0x090, 0x090, 0x090, 0x090, 0x0A0, 0x0F0,
    0x0A0, 0x0A0, 0x0A0, 0x0A0, 0x0A0, 0x0A0, 0x0A0, 0x0F0,
    0x0F0, 0x0F0, 0x0F0, 0x0F0, 0x0F0, 0x0F0, 0x0F0, 0x0F0,
  },

  // 04: low blue to high blue
  { 0x100, 0x200, 0x300, 0x500, 0x700, 0x900, 0xA00, 0xF00,
    0x200, 0x200, 0x300, 0x500, 0x700, 0x900, 0xA00, 0xF00,
    0x300, 0x300, 0x300, 0x500, 0x700, 0x900, 0xA00, 0xF00,
    0x500, 0x500, 0x500, 0x500, 0x700, 0x900, 0xA00, 0xF00,
    0x700, 0x700, 0x700, 0x700, 0x700, 0x900, 0xA00, 0xF00,
    0x900, 0x900, 0x900, 0x900, 0x900, 0x900, 0xA00, 0xF00,
    0xA00, 0xA00, 0xA00, 0xA00, 0xA00, 0xA00, 0xA00, 0xF00,
    0xF00, 0xF00, 0xF00, 0xF00, 0xF00, 0xF00, 0xF00, 0xF00,
  },

  // 05: 1 black, 2R, 2O, 2G, 1B with 4 blue lines rising right
  { 0x000, 0x200, 0x000, 0x400, 0x000, 0x800, 0x000, 0xF00,
    0x000, 0x201, 0x002, 0x403, 0x004, 0x805, 0x006, 0xF07,
    0x008, 0x209, 0x00A, 0x40B, 0x00C, 0x80D, 0x00E, 0xF0F,
    0x000, 0x211, 0x022, 0x433, 0x044, 0x855, 0x066, 0xF77,
    0x088, 0x299, 0x0AA, 0x4BB, 0x0CC, 0x8DD, 0x0EE, 0xFFF,
    0x000, 0x210, 0x020, 0x430, 0x040, 0x850, 0x060, 0xF70,
    0x080, 0x290, 0x0A0, 0x4B0, 0x0C0, 0x8D0, 0x0E0, 0xFF0,
    0x000, 0x200, 0x000, 0x500, 0x000, 0x800, 0x000, 0xF00,
  },

  // 06: 4 lines of increasing red and then green
  { 0x000, 0x000, 0x001, 0x001, 0x002, 0x002, 0x003, 0x003,
    0x004, 0x004, 0x005, 0x005, 0x006, 0x006, 0x007, 0x007,
    0x008, 0x008, 0x009, 0x009, 0x00A, 0x00A, 0x00B, 0x00B,
    0x00C, 0x00C, 0x00D, 0x00D, 0x00E, 0x00E, 0x00F, 0x00F,
    0x000, 0x000, 0x010, 0x010, 0x020, 0x020, 0x030, 0x030,
    0x040, 0x040, 0x050, 0x050, 0x060, 0x060, 0x070, 0x070,
    0x080, 0x080, 0x090, 0x090, 0x0A0, 0x0A0, 0x0B0, 0x0B0,
    0x0C0, 0x0C0, 0x0D0, 0x0D0, 0x0E0, 0x0E0, 0x0F0, 0x0F0,
  },

  // 07: 4 lines of increasing red and then blue
  { 0x000, 0x000, 0x001, 0x001, 0x002, 0x002, 0x003, 0x003,
    0x004, 0x004, 0x005, 0x005, 0x006, 0x006, 0x007, 0x007,
    0x008, 0x008, 0x009, 0x009, 0x00A, 0x00A, 0x00B, 0x00B,
    0x00C, 0x00C, 0x00D, 0x00D, 0x00E, 0x00E, 0x00F, 0x00F,
    0x000, 0x000, 0x100, 0x100, 0x200, 0x200, 0x300, 0x300,
    0x400, 0x400, 0x500, 0x500, 0x600, 0x600, 0x700, 0x700,
    0x800, 0x800, 0x900, 0x900, 0xA00, 0xA00, 0xB00, 0xB00,
    0xC00, 0xC00, 0xD00, 0xD00, 0xE00, 0xE00, 0xF00, 0xF00,
  },

  // 08: criss cross of green and red with diagonal blue.
  { 0xF00, 0x001, 0x003, 0x005, 0x007, 0x00A, 0x00F, 0x000,
    0x020, 0xF21, 0x023, 0x025, 0x027, 0x02A, 0x02F, 0x020,
    0x040, 0x041, 0xF43, 0x045, 0x047, 0x04A, 0x04F, 0x040,
    0x060, 0x061, 0x063, 0xF65, 0x067, 0x06A, 0x06F, 0x060,
    0x080, 0x081, 0x083, 0x085, 0xF87, 0x08A, 0x08F, 0x080,
    0x0A0, 0x0A1, 0x0A3, 0x0A5, 0x0A7, 0xFAA, 0x0AF, 0x0A0,
    0x0F0, 0x0F1, 0x0F3, 0x0F5, 0x0F7, 0x0FA, 0xFFF, 0x0F0,
    0x000, 0x001, 0x003, 0x005, 0x007, 0x00A, 0x00F, 0xF00,
  },

  // 09: 2 lines of green, 2 red, 2 orange, 2 green
  { 0x0F0, 0x0F0, 0x0FF, 0x0FF, 0x00F, 0x00F, 0x0F0, 0x0F0,
    0x0F0, 0x0F0, 0x0FF, 0x0FF, 0x00F, 0x00F, 0x0F0, 0x0F0,
    0x0F0, 0x0F0, 0x0FF, 0x0FF, 0x00F, 0x00F, 0x0F0, 0x0F0,
    0x0F0, 0x0F0, 0x0FF, 0x0FF, 0x00F, 0x00F, 0x0F0, 0x0F0,
    0x0F0, 0x0F0, 0x0FF, 0x0FF, 0x00F, 0x00F, 0x0F0, 0x0F0,
    0x0F0, 0x0F0, 0x0FF, 0x0FF, 0x00F, 0x00F, 0x0F0, 0x0F0,
    0x0F0, 0x0F0, 0x0FF, 0x0FF, 0x00F, 0x00F, 0x0F0, 0x0F0,
    0x0F0, 0x0F0, 0x0FF, 0x0FF, 0x00F, 0x00F, 0x0F0, 0x0F0,
  },

  // 10: multicolor smiley face
  { 0x000, 0x000, 0x00F, 0x00F, 0x00F, 0x00F, 0x000, 0x000,
    0x000, 0x00F, 0x000, 0x000, 0x000, 0x000, 0x00F, 0x000,
    0x00F, 0x000, 0xF00, 0x000, 0x000, 0xF00, 0x000, 0x00F,
    0x00F, 0x000, 0x000, 0x000, 0x000, 0x000, 0x000, 0x00F,
    0x00F, 0x000, 0x0F0, 0x000, 0x000, 0x0F0, 0x000, 0x00F,
    0x00F, 0x000, 0x000, 0x0F4, 0x0F3, 0x000, 0x000, 0x00F,
    0x000, 0x00F, 0x000, 0x000, 0x000, 0x000, 0x00F, 0x000,
    0x000, 0x000, 0x00F, 0x00F, 0x00F, 0x00F, 0x000, 0x000,
  },
};


// Convert a BGR 4/4/4 bitmap to RGB 5/6/5 used by Adafruit_GFX
void fixdrawRGBBitmap(int16_t x, int16_t y, const uint16_t *bitmap, int16_t w, int16_t h) {
  uint16_t RGB_bmp_fixed[w * h];
  for (uint16_t pixel = 0; pixel < w * h; pixel++) {
    uint8_t r, g, b;
    uint16_t color = pgm_read_word(bitmap + pixel);
    b = (color & 0xF00) >> 8;
    g = (color & 0x0F0) >> 4;
    r = color & 0x00F;
    b = map(b, 0, 15, 0, 31);
    g = map(g, 0, 15, 0, 63);
    r = map(r, 0, 15, 0, 31);
    RGB_bmp_fixed[pixel] = (r << 11) + (g << 5) + b;
  }
  matrix->drawRGBBitmap(x, y, RGB_bmp_fixed, w, h);
}
// Fill the screen with multiple levels of white to gauge the quality
void display_four_white() {
  matrix->clear();
  matrix->fillRect(0, 0, mw, mh, LED_WHITE_HIGH);
  matrix->drawRect(1, 1, mw - 2, mh - 2, LED_WHITE_MEDIUM);
  matrix->drawRect(2, 2, mw - 4, mh - 4, LED_WHITE_LOW);
  matrix->drawRect(3, 3, mw - 6, mh - 6, LED_WHITE_VERYLOW);
  matrix->show();
}
void display_bitmap(uint8_t bmp_num, uint16_t color) {
  static uint16_t bmx, bmy;
  // Clear the space under the bitmap that will be drawn as
  // drawing a single color pixmap does not write over pixels
  // that are nul, and leaves the data that was underneath
  matrix->fillRect(bmx, bmy, bmx + 8, bmy + 8, LED_BLACK);
  matrix->drawBitmap(bmx, bmy, mono_bmp[bmp_num], 8, 8, color);
  bmx += 8;
  if (bmx >= mw) bmx = 0;
  if (!bmx) bmy += 8;
  if (bmy >= mh) bmy = 0;
  matrix->show();
}
void display_rgbBitmap(uint8_t bmp_num) {
  static uint16_t bmx, bmy;
  fixdrawRGBBitmap(bmx, bmy, RGB_bmp[bmp_num], 8, 8);
  bmx += 8;
  if (bmx >= mw) bmx = 0;
  if (!bmx) bmy += 8;
  if (bmy >= mh) bmy = 0;
  matrix->show();
}


void display_scrollText(String s)
{
  matrix->clear();
  matrix->setTextWrap(false);  // we don't wrap text so it scrolls nicely
  matrix->setTextSize(2);
  matrix->setRotation(0);
  for (int8_t x = 64; x >= -127; x--)
  {
    matrix->clear();
    matrix->setCursor(x, 0);
    matrix->setTextColor(LED_RED_HIGH);
    matrix->print(s);
    matrix->show();
    delay(60);
  }
}
void Set_Status()
{
  matrix->clear();
  matrix->setTextWrap(false);  // we don't wrap text so it scrolls nicely
  matrix->setTextSize(1);
  matrix->setRotation(0);
  for (int8_t x = 64; x >= -127; x--)
  {
    Read_Switch();
    set_IO_Pins();
    matrix->clear();
    matrix->setCursor(3, 0);
    matrix->setTextColor(LED_ORANGE_HIGH);
    matrix->print(Name);
    matrix->setCursor(x, 9);
    matrix->setTextColor(LED_GREEN_HIGH);
    matrix->print(Post);
    matrix->show();
    delay(40);
  }
  for (int8_t x = 64; x >= -80; x--)
  {
    Read_Switch();
    set_IO_Pins();
    matrix->clear();
    matrix->setCursor(3, 0);
    matrix->setTextColor(LED_ORANGE_HIGH);
    matrix->print(Name);
    matrix->setCursor(x, 8);
    matrix->setTextColor(LED_RED_HIGH);
    matrix->print(status_string);
    matrix->show();
    if(status_string.length()<13 && x==3)
    delay(3000);
    delay(40);
  }
  matrix->setRotation(0);
  matrix->setCursor(0, 0);
  matrix->show();
}
void setup()
{
  Serial.begin(115200);
  Setup_Blynk();
  matrix->begin();
  matrix->setTextWrap(false);
  matrix->fillScreen(LED_WHITE_HIGH);
  matrix->show();
  delay(1000);
  matrix->clear();
  pinMode(Lights_out_pin, OUTPUT);
  pinMode(Door_out_pin, OUTPUT);
  pinMode(extra_pin, OUTPUT);
  pinMode(LCD_pin, OUTPUT);
  display_scrollText("Developedby:RAAS   ");
}
void loop()
{

  Read_Switch();
  set_IO_Pins();
  //static uint8_t pixmap_count = ((mw + 7) / 8) * ((mh + 7) / 8);
  Set_Status();
}
