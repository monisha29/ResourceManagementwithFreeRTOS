
//led 2
int redPin_2 = 8;

//led 3
int redPin_3 = 4;


void setup() {
 Serial.begin(9600);
 Serial.println("********************Serial Execution**************");
  pinMode(redPin_2, OUTPUT);
  //led 3
  pinMode(redPin_3, OUTPUT);
}

void loop() {
  Serial.println("Green LED Blinking");
  setColor_led2();
  delay(1000);
  Serial.println("RED LED Blinking");
  setColor_led3();
  delay(1000);
}

void setColor_led2(){
  digitalWrite(redPin_2,HIGH);

  delay(2000);
  digitalWrite(redPin_2,LOW);

}
void setColor_led3(){
  digitalWrite(redPin_3,HIGH);

  delay(2000);
  digitalWrite(redPin_3,LOW);

}
