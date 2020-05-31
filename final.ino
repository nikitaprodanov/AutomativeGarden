#include <dht11.h> //DHT library for using the sensor

dht11 DHT11; //Initializing the dht sensor

//Constants:

#define LED 5 //Pin to control the led strip
#define DHT_PIN 12 //Pin to read the value of the dht sensor 
#define FAN 9 //Pin that controls the dc fan
#define tooHot 26 //Constant temperature value
#define waterPump 3; //Pin that controls the water pump
const int hygrometer = A0; //Pin that reads the output of the soil humidity sensor

//Variables:

int humidity_value; //Variable that saves the value that was read by the soil humidity sensor
bool isDay = 1; //This bool tells if it is daytime
bool isNight = 0; //This bool tells if it is nighttime
int timer = 0; //This variable imitates the behaviour of a timer
#define day_hours 32400;
#define night_hours 54000;

//Setting up the pins
void setup(){
  pinMode(FAN, OUTPUT); //Setting the fan pin in output mode
  pinMode(waterPump,OUTPUT); //Setting the water pump pin in output mode
  pinMode(LED, OUTPUT); //Setting the led strip pin in output mode
}

//Main loop
void loop()
{
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

  delay(2000); //Small delay before the next iteration

  //Led strip day and night routine
  if (isDay && timer < day_hours) { //If it is day and the strip hasn't been on for 9hours
    digitalWrite(LED, HIGH) //Led strip is on
    timer += 2; //Timer increases with 2 (representing seconds)
    isNight = 0; //It is not night
  }
  else if (isDay && timer >= day_hours) { //If it is day and the strip has been working more than 9hours
    digitalWrite(LED, LOW); //Turning off the led strip
    isNight = 1; //It is now night
    isDay = 0; //It's no longer day
    timer = 0; //Reset the timer to start counting the 15 hours of no light
  }
  else if (isNight && timer < night_hours) { //If it is night and the strip has't been working for less than 15 hours
    digitalWrite(LED, LOW); //Strip is off
    timer += 2; //Timer increases with 2 (representing seconds)
    isDay = 0; //It's not day
  }
  else if (isNight && timer >= night_hours) { //If it is night and the strip has not been working for more than 15 hours
    digitalWrite(LED, HIGH); //Led strip should turn on
    timer = 0; //Reset the timer to count the 9 hours of day
    isDay = 1; //It is now day
    isNight = 0; //It is no longer night
  }
}