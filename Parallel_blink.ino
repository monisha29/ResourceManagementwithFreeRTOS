#include <Arduino_FreeRTOS.h>
//red
int redPin_2 = 8;
//green
int redPin_3 = 4;

void Task2( void *pvParameters );
void Task3( void *pvParameters );

void setup() {
      Serial.begin(9600);

  Serial.println("********************Parallel Execution**************");
  pinMode(redPin_2, OUTPUT);
  pinMode(redPin_3, OUTPUT);
  xTaskCreate(
    Task2
    , (const portCHAR *)"Task2"
    , 128
    , NULL
    , 1
    , NULL );

  xTaskCreate(
    Task3
    , (const portCHAR *)"Task3"
    , 128
    , NULL
    , 1
    , NULL );
}
void loop() {
  // put your main code here, to run repeatedly:
}

void Task2(void *pvParamaters) {
  (void) pvParamaters;
  //loop here
  for (;;) {
    Serial.println("RED LED Blinking");
    setColor_led2();
    delay(500);
  }
  vTaskDelete( NULL );
}

void Task3(void *pvParamaters) {
  (void) pvParamaters;
  //loop here
  for (;;) {
    Serial.println("GREEN LED Blinking");
    setColor_led3();
    delay(500);
  }
  vTaskDelete( NULL );
}

void setColor_led2() {
  digitalWrite(redPin_2, HIGH);
  delay(2000);
  digitalWrite(redPin_2, LOW);
}
void setColor_led3() {
  digitalWrite(redPin_3, HIGH);
  delay(2000);
  digitalWrite(redPin_3, LOW);
}
