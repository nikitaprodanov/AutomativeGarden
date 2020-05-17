// Arduino Automatic Watering System for your desk flower

//Constants 
const int waterPump = 9;    //Air pump motor with npn transistor at pin 9 of Arduino
const int hygrometer = A0;  //Hygrometer sensor analog pin output at pin A0 of Arduino

//Variables 
int value;
void setup()
{
  pinMode(waterPump,OUTPUT);
}

void loop()
{
  // When the plant is watered well the sensor will read a value 380~400, I will keep the 400 
  // value but if you want you can change it below. 
  
  value = analogRead(hygrometer);   //Read analog value 
  value = constrain(value,400,1023);  //Keep the ranges!
  value = map(value,400,1023,100,0);  //Map value : 400 will be 100 and 1023 will be 0
  
  //Start the watering if humidity decrease down of 20%
  if (value < 20){
    digitalWrite(waterPump,HIGH);
  }
  else {
      digitalWrite(waterPump,LOW);
  }
  delay(150); //small delay
}
