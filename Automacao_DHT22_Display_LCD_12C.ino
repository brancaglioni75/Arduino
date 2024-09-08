/* Projeto: Sistema de Automação por Temperatura e Umidade 
Enfatiza o uso de sensores para automação.
Name: Wilson Brancaglioni
Modificado: 08/09/2024*/

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Definições de pinos
#define DHTPIN    2 //Pino do DHT22
#define RELE_TEMP 3 //Pino do relé para controle pela temperatura
#define RELE_UMID 4 //Pino do relé para controle pela umidade

#define DHTTIPO DHT22  // Tipo de sensor DHT

// Inicializa o sensor DHT
DHT dht(DHTPIN, DHTTIPO);

// Inicializa o display LCD (endereço I2C 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);

  // Inicializa o sensor DHT
  dht.begin();

  // Inicializa o LCD
  lcd.init();
  lcd.backlight();

  // Configura os pinos dos relés como saída
  pinMode(RELE_TEMP, OUTPUT);
  pinMode(RELE_UMID, OUTPUT);

  // Inicialmente desliga os relés
  digitalWrite(RELE_TEMP, HIGH);
  digitalWrite(RELE_UMID, HIGH);
}

void loop() {
  // Lê a temperatura e a umidade
  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  // Verifica se a leitura falhou
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Falha ao ler do sensor DHT!");
    return;
  }

  // Exibe as leituras no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C");
  Serial.print(" | Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");

  // Exibe as leituras no LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(umidade);
  lcd.print(" %");

  // Controle do relé pela temperatura
  if (temperatura > 25) {
    digitalWrite(RELE_TEMP, LOW);  // Liga a tomada
  } else {
    digitalWrite(RELE_TEMP, HIGH); // Desliga a tomada
  }

  // Controle do relé pela umidade
  if (umidade < 70) {
    digitalWrite(RELE_UMID, LOW);  // Liga a tomada
  } else {
    digitalWrite(RELE_UMID, HIGH); // Desliga a tomada
  }

  // Aguarda 2 segundos antes de repetir
  delay(2000);
}
