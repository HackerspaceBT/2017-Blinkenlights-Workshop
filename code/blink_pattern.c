void setup() {
  pinmode(13, OUTPUT);
}

void loop() {
  digitalwrite(13, HIGH);
  delay(2000);
  digitalwrite(13, LOW);
  delay(500);
}
