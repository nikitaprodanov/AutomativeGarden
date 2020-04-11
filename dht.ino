#include <dht.h>

dht DHT;

#define DHT11_PIN 4
#define LED 2

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);

  if(DHT.humidity < 50) {
    digitalWrite(LED, HIGH);
    delay(300);
    digitalWrite(LED, LOW);
    delay(300);
    digitalWrite(LED, HIGH);  
  }
  else {
    digitalWrite(LED, LOW);  
  }
    
  delay(2000);
}

