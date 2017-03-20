unsigned long button_time = 0;
bool running = false;
void setup() {}
void loop() {
  if(digitalRead(button_pin) == HIGH) {
    running = true;
    button_time = millis();
  }
  if(running) {
    running = do_stuff(millis() - start_time);
  }
}

bool do_stuff(unsigned long time_point)
  if(time_point < 100) {
    digitalWrite(led_pin, HIGH);
  } else if(time_point < 200) {
    digitalWrite(led_pin, LOW);
  } else if(time_point < 1000) {
    digitalWrite(led_pin, HIGH);
  } else {
    return false;
  }
  return true;
}
