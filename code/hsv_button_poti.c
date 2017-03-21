// Set up pins for R, G, B channels
const int pin_led_r = 3;
const int pin_led_g = 5;
const int pin_led_b = 6;
const int pin_gnd = 4;

// Potentiometer pin
const int pin_poti = A1;


// Stores the current colour
unsigned char r = 0, g = 0, b = 0;


void setup() {
    // LED pins as output
    pinMode(pin_led_r, OUTPUT);
    pinMode(pin_led_g, OUTPUT);
    pinMode(pin_led_b, OUTPUT);
    pinMode(pin_gnd, OUTPUT);
}


void loop() {

    // Get the current potentiometer value
    int ain = analogRead(pin_poti);

    hsv_to_rgb( ain/4, 255, 255, &r, &g, &b );

    // Write new values to LED
    analogWrite(pin_led_r, r);
    analogWrite(pin_led_g, g);
    analogWrite(pin_led_b, b);
}


// 8-bit scale for all values
void hsv_to_rgb( byte h, byte s, byte v, byte *r, byte *g, byte *b)
{ 
  if (s==0) {
    *r = *g = *b = v;
   return; 
  }
  
  const byte  hi = h/43;
  const unsigned short  f = (h - (hi * 43)) * 6;
  const byte  p = (v * (256 - s)) >> 8;
  const byte  q = (v * (256 - ((s * f) >> 8))) >> 8;
  const byte  t = (v * (256 - ((s * (256 - f)) >> 8))) >> 8;
  
  switch ( hi ) {
    case 0: *r = v; *g = t; *b = p; return;
    case 1: *r = q; *g = v; *b = p; return;
    case 2: *r = p; *g = v; *b = t; return;
    case 3: *r = p; *g = q; *b = v; return;
    case 4: *r = t; *g = p; *b = v; return;
    case 5: *r = v; *g = p; *b = q; return;
    default: *r = *g = *b = 0; return;  // invalid hue
  }
  
}


