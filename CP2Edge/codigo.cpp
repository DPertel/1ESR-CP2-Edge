#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int buzzer = 9; // sinais sonoros
int ledRed = 6; // LED Vermelho
int ledYellow = 7; // LED Amarelo
int ledGreen = 8; // LED Verde

int fotorresistor = A3; // Pino do fotorresistor

int tempSensorPin = A0; // pino do sensor de temperatura
int lightSensorPin = A1; // pino do sensor de luz
int potPin = A2; // pino do potenciômetro

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);

  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(tempSensorPin, INPUT);
  pinMode(lightSensorPin, INPUT);
  pinMode(potPin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  // ler os valores dos sensores
  float tempLido = analogRead(tempSensorPin); // convertendo para Celsius
  float tempC = ((tempLido * (5.0 / 1023.0)) - 0.5) * 100.0;
  int lightValue = analogRead(lightSensorPin);
  int potValue = analogRead(potPin);
  
  int valorLido = analogRead(fotorresistor); // Ler valor do fotorresistor
  Serial.println(valorLido); // Imprimir valor lido na porta serial
  delay(100); // Aguardar 100ms antes de ler o próximo valor
  Serial.println(tempC);

  if (potValue < 100)
  {
    potValue = 100;
  }
  else if (potValue > 900)
  {
    potValue = 900;
  }

  int brightness = map(potValue, 100, 900, 0, 255);

  if (valorLido < 42.5)
  {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, LOW);
    
    lcd.clear();
  }
  else if (valorLido >= 42.5 && valorLido <= 127.5)
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, LOW);
    
    lcd.setCursor(0, 0);
    lcd.print("Ambiente a meia");
    lcd.setCursor(0, 1);
    lcd.print("luz       ");
  }
  else
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(buzzer, HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("Ambiente muito    ");
    lcd.setCursor(0, 1);
    lcd.print("CLARO      ");
  }
  
   delay(5000);
   lcd.clear();
  
   if (lightValue < 1023*0.5) 
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(buzzer, HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("Umidade BAIXA");
    lcd.setCursor(0, 1);
    lcd.print("Umidade = ");
    lcd.print((lightValue)/10);
    lcd.print("%");
  }
  else if (lightValue >= 1023*0.5 && lightValue <= 1023*0.7) 
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, LOW);
    
    lcd.setCursor(0, 0);
    lcd.print("Umidade OK");
    lcd.setCursor(0, 1);
    lcd.print("Umidade = ");
    lcd.print((lightValue)/10);
    lcd.print("%");
  } else 
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, HIGH);
    digitalWrite(buzzer, HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("Umidade ALTA");
    lcd.setCursor(0, 1);
    lcd.print("Umidade = ");
    lcd.print((lightValue)/10);
    lcd.print("%");
  }
  delay(5000);
  lcd.clear();
  
  if (tempC >= 10 && tempC <= 15) 
  {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, LOW);
    
    lcd.setCursor(0, 0);
    lcd.print("Temperatura OK");
    lcd.setCursor(0, 1);
    lcd.print("Temp. = ");
    lcd.print(tempC,1);
    lcd.print("C");
  }
  else if (tempC > 15)
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("Temp. ALTA");
    lcd.setCursor(0, 1);
    lcd.print("Temp. = ");
    lcd.print(tempC,1);
    lcd.print("C"); 
  }
  else 
  {
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledRed, LOW);
    digitalWrite(buzzer, HIGH);
    
    lcd.setCursor(0, 0);
    lcd.print("Temp. BAIXA");
    lcd.setCursor(0, 1);
    lcd.print("Temp. = ");
    lcd.print(tempC,1);
    lcd.print("C"); 
  }
  delay(5000);
  lcd.clear();
}
