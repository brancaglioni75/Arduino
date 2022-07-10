const int analogPin = A0; // Pino conectado ao potenciômetro
const int nrLeds = 9; // Número de LEDs
int ledPins[] = {2,3,4,5,6,7,8,9,10}; // Pinos conectados aos LEDs

void setup() {
  for (int thisLed = 0; thisLed < nrLeds; thisLed++){
    pinMode(ledPins[thisLed], OUTPUT); // Definir os pinos dos LEDs como saída
  }
}

// Iniciar um loop
void loop() {
  int sensorReading = analogRead(analogPin); // Entrada analógica
  int ledLevel = map(sensorReading, 0, 1023, 0, nrLeds);
  for(int thisLed = 0; thisLed < nrLeds; thisLed++){
    if(thisLed < ledLevel){// Acende os LEDs em sequência
      digitalWrite(ledPins[thisLed], HIGH);
    }
    else{// Apaga os LEDs em sequência
      digitalWrite(ledPins[thisLed], LOW);
    }
  }
}
