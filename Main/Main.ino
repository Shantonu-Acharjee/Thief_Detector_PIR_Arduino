const int led = A3;   
const int Alerm = A4; 
const int StatusLed = 7; 
const int Pir_Pin = A0;  
const int Push_Button_Pin = A2;
int SensorState = 0;
int ButtonValue = 0;
int ButtonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Pir_Pin, INPUT);
  pinMode(Push_Button_Pin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(Alerm, OUTPUT);
  pinMode(StatusLed, OUTPUT);

}

void loop() {
  SensorState = analogRead(Pir_Pin);
  ButtonValue = analogRead(Push_Button_Pin);
  //Serial.println(SensorState);
  //Serial.println(ButtonValue);
  Serial.println(ButtonState);

  if(SensorState > 300 && ButtonState == 1){
    digitalWrite(Alerm, 1);
  }


  else if (SensorState > 300 && ButtonState == 0){
    digitalWrite(led, 1);
  }

  

  else if(ButtonValue > 300 && ButtonState == 0){
    ButtonState = 1;
    digitalWrite(StatusLed, 1);
    delay(500);
  }

  else if(ButtonValue > 300 && ButtonState == 1){
    ButtonState = 0;
    digitalWrite(StatusLed, 0);
    delay(500);
  }
  
  else{
    digitalWrite(led, 0);
    digitalWrite(Alerm, 0);
  }


}

