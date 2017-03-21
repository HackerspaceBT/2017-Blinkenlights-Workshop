void setup() {
  pinmode(13, OUTPUT);
}

void loop() {
  digitalwrite(13, HIGH);
  delay(1000);
  digitalwrite(13, HIGH);
  delay(1000);
}
