// Set up pins for R, G, B channels
const int led_r = 3;
const int led_g = 5;
const int led_b = 6;

// Pin to which our button is connected, with a pull-down
const int button = 7;

// Potentiometer pin
const int poti = A0;

// When was the last time the button got pressed?
unsigned long button_time = 0;

// Which colour is being modified?
char modifying = 0;

// What was the start value of the potentiometer when we switched to
// the current colour?
int analog_start_value;

// Are we modifying the colour?
bool analog_locked = false;

// Stores the current colour
unsigned char rgb[3];

void setup() {
    // LED pins as output
    pinMode(led_r, OUTPUT);
    pinMode(led_g, OUTPUT);
    pinMode(led_b, OUTPUT);

    // Set colour to black
    rgb[0] = 0;
    rgb[1] = 0;
    rgb[2] = 0;
}

void loop() {
    // Only read the button after 100 ms - simple debouncing
    if(millis() - button_time > 100 &&
       digitalRead(button) == HIGH) {
        // Modify the next colour channel
        modifying += 1;
        // There's no fourth channel
        if(modifying == 3) {
            modifying = 0;
        }

        // Get the start value, and prevent writes
        analog_start_value = analogRead(poti);
        analog_locked = true;
    }

    // Get the current potentiometer value
    int v = analogRead(poti);

    // If we're not allowing writes yet, but are turning the knob,
    // allow writes
    if(analog_locked && abs(v - analog_start_value) > 20) {
        analog_locked = false;
    }

    // If writes are allowed
    if(!analog_locked ) {
        // Change the current colour channel
        // 
        // analogRead values are 0-1023, so divide by four to get
        // 0-255
        rgb[modifying] = v / 4;

        // Write new values to LED
        analogWrite(led_r, rgb[0]);
        analogWrite(led_g, rgb[1]);
        analogWrite(led_b, rgb[2]);
    }
}
