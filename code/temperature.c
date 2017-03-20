void setup() {
  Serial.begin(115200);
  // Temperaturmessung einrichten:
  ADMUX = (_BV(REFS1) | _BV(REFS0) | _BV(MUX3));
  ADCSRA |= _BV(ADEN);
}
void loop() {
  ADCSRA |= _BV(ADSC); // Messung starten
  while(ADCSRA & _BV(ADSC)) { } // Warte
  Serial.println(ADCW); // Wert ausgeben
}
