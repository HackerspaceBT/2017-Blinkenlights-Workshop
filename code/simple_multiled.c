#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(144, 13,
                        NEO_GRB + NEO_KHZ800);
int i = 0;
void setup() { strip.begin(); }
void loop() {
  strip.setPixelColor(i, 255, 0, 0);
  strip.show();
  delay(10);
  strip.setPixelColor(i, 0, 0, 0);
  i++;
  if(i == 144) i = 0;
}
