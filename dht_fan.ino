#include <dht.h>

dht DHT;

#define DHT_PIN 4
#define FAN 9
#define tooHot 10

void setup(){
  pinMode(FAN, OUTPUT);
}

void loop()
{
  DHT.read11(DHT_PIN);

  if(DHT.temperature < tooHot) {
    digitalWrite(FAN, HIGH);
  }
  else {
    digitalWrite(FAN, LOW);  
  }
    
  delay(2000);
}

