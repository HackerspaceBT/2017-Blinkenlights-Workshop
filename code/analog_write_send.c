void setup() {
  Serial.begin(115200);
}
void loop() {
  Serial.print("Aktueller Wert: ");
  Serial.println(analogRead(A0));
}
