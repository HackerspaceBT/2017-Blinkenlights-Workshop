int const led_pin = 11;
void setup() {
  pinMode(led_pin, OUTPUT);
}
void loop() {
  // Zeit seit Beginn des Programms
  unsigned long time = millis();
  // Berechne eine Sägezahn mit 0.1 Hz
  int value = 255 * time / 4000;
  // Verwende den Wert als Schwellwert
  analogWrite(led_pin, value);
}
