#include <dht11.h> //DHT library for using the sensor

dht11 DHT11; //Initializing the dht sensor

//Constants:

#define LED 9 //Pin to control the led strip
#define DHT_PIN 7 //Pin to read the value of the dht sensor 
#define FAN 3 //Pin that controls the dc fan
#define tooHot 26 //Constant temperature value
#define waterPump 5; //Pin that controls the water pump
const int hygrometer = A0; //Pin that reads the output of the soil humidity sensor

int humidity_value; //Variable that saves the value that was read by the soil humidity sensor

//Setting up the pins
void setup(){
  pinMode(FAN, OUTPUT); //Setting the fan pin in output mode
  pinMode(waterPump,OUTPUT); //Setting the water pump pin in output mode
  pinMode(LED, OUTPUT); //Setting the led strip pin in output mode
}

//Main loop
void loop()
{
  digitalWrite(LED, HIGH); //Turning on the led strip

  DHT11.read(DHT_PIN); //Reading from the dht sensor

  //Checking if the temperature value from the sensor is higher than 26 C
  if(DHT11.temperature > tooHot) {
    digitalWrite(FAN, HIGH); //If true turn on the dc fan
  }
  else {
    digitalWrite(FAN, LOW);  //Else turn it off
  }

  //Mapping the soil humidity value to percentage:
  value = analogRead(hygrometer); //Reading the value from the sensor
  value = constrain(value,400,1023); //Constraining the values in the 400-1023 range
  value = map(value,400,1023,100,0); //Mapping the 400-1023 range to new 0-100 range that will represent the 

  //Checking if the soil humidity is lower than 20%
  if (value < 20){
    digitalWrite(waterPump,HIGH); //If true turn on the water pump
  }
  else {
      digitalWrite(waterPump,LOW); //Else turn the water pump off
  }

  delay(150); //Small delay before the next iteration
}