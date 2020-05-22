#include <dht11.h>

dht11 DHT11;

#define DHT_PIN 4
#define FAN 9
#define tooHot 10

void setup(){
  pinMode(FAN, OUTPUT);
}

void loop()
{
  DHT11.read(DHT_PIN);

  if(DHT11.temperature < tooHot) {
    digitalWrite(FAN, HIGH);
  }
  else {
    digitalWrite(FAN, LOW);  
  }
    
  delay(2000);
}

