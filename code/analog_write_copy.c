void setup() {
    pinMode(3, OUTPUT);
}
void loop() {
    // Teile durch 4, um den
    // Wertebereich anzupassen
    int value = analogRead(A0) / 4;
    analogWrite(3, value);
}
