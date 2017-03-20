#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(144, 13, NEO_GRB + NEO_KHZ800);
uint32_t colors[144];
int i = 0;
void setup() {
  strip.begin();
  for(i = 0; i < 48; i++) {
    unsigned char v = i*255/48;
    colors[i]    = strip.Color(255-v, v, 0);
    colors[i+48] = strip.Color(0, 255-v, v);
    colors[i+96] = strip.Color(v, 0, 255-v);
  }
}
void loop() {
  for(int j = i; j < 144-i; j++)
    strip.setPixelColor(i+j,     colors[j]);
  for(int j = 144-i; j < 144; j++)
    strip.setPixelColor(i+j-144, colors[j]);
  strip.show();
  i++;
  if(i == 144) i = 0;
}
