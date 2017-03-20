void setup() {
  pinmode(13, output);
}

void loop() {
  digitalwrite(13, high);
  delay(2000);
  digitalwrite(13, low);
  delay(500);
}
