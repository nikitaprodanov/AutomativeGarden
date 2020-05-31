#include <dht11.h> //DHT library for using the sensor

dht11 DHT11; //Initializing the dht sensor

//Constants:

#define DHT_PIN 4 //Pin to read the value of the dht sensor 
#define FAN 3 //Pin that controls the dc fan
#define tooHot 26 //Constant temperature value
#define waterPump 5; //Pin that controls the water pump
const int hygrometer = A0; //Pin that reads the output of the soil humidity sensor

int humidity_value; //Variable that saves the value that was read by the soil humidity sensor

//Setting up the pins
void setup(){
  pinMode(FAN, OUTPUT); //Setting the fan pin in output mode
  pinMode(waterPump,OUTPUT); //Setting the water pump pin in output mode
}

void loop()
{
  DHT11.read(DHT_PIN);

  if(DHT11.temperature > tooHot) {
    digitalWrite(FAN, HIGH);
  }
  else {
    digitalWrite(FAN, LOW);  
  }

  value = analogRead(hygrometer);
  value = constrain(value,400,1023);
  value = map(value,400,1023,100,0);

  if (value < 20){
    digitalWrite(waterPump,HIGH);
  }
  else {
      digitalWrite(waterPump,LOW);
  }
  delay(150);
}