#include <SHT1x.h>
#define dataPin 11
#define clockPin 12
SHT1x sht1x(dataPin, clockPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World!");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  float tempC = sht1x.readTemperatureC();
  delay(1000);  
  Serial.println(String("tempC: ") + String(tempC, 2));
  float humidity = sht1x.readHumidity();   
  Serial.println(String("hum: ") + String(humidity, 2));
}
