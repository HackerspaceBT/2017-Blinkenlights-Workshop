// Set up pins for R, G, B channels
const int pin_led_r = 3;
const int pin_led_g = 5;
const int pin_led_b = 6;
const int pin_gnd = 4;

// Pin to which our button is connected, with a pull-down
const int pin_button = A0;

// Potentiometer pin
const int pin_poti = A1;

// When was the last time the button got pressed?
unsigned long button_time = 0;

// Which colour is being modified?
char selected_color = 0;

// What was the start value of the potentiometer when we switched to
// the current colour?
int analog_start_value;

// Are we modifying the colour?
bool analog_locked = false;

// Stores the current colour
unsigned char r = 0, g = 0, b = 0;


void setup() {
    // LED pins as output
    pinMode(pin_led_r, OUTPUT);
    pinMode(pin_led_g, OUTPUT);
    pinMode(pin_led_b, OUTPUT);
    pinMode(pin_gnd, OUTPUT);
    pinMode(pin_button, INPUT_PULLUP);
}


void loop() {

    // Only read the button after 100 ms - simple debouncing
    if(millis() - button_time > 100  &&  digitalRead(pin_button) == LOW) {

        // Select the next colour channel
        selected_color += 1;

        // There's no fourth channel
        if(selected_color == 3) {
            selected_color = 0;
        }

        // Get the start value, and prevent color changes for the moment
        // (otherwise we would change the selected color immediately)
        analog_start_value = analogRead(pin_poti);
        analog_locked = true;
    }

    // Get the current potentiometer value
    int v = analogRead(pin_poti);

    // Only allow color changes, if the knob has been turned a little.
    if(analog_locked && abs(v - analog_start_value) > 20) {
        analog_locked = false;
    }

    // If color changes are allowed
    if(!analog_locked ) {
        // Change the current colour channel
        // analogRead values are 0-1023, so divide by four to get 0-255
        if(selected_color == 0)      r = v / 4;
        else if(selected_color == 1) g = v / 4;
        else                         b = v / 4;

        // Write new values to LED
        analogWrite(pin_led_r, r);
        analogWrite(pin_led_g, g);
        analogWrite(pin_led_b, b);
    }
}

