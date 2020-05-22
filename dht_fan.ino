#include <dht11.h>

dht11 DHT11;

#define DHT_PIN 4
#define FAN 9
#define tooHot 10

void setup(){
  pinMode(FAN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  DHT11.read(DHT_PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);

  if(DHT11.temperature < tooHot) {
    digitalWrite(FAN, HIGH);
  }
  else {
    digitalWrite(FAN, LOW);  
  }
    
  delay(2000);
}

