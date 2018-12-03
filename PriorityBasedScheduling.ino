#include <Arduino_FreeRTOS.h>

TaskHandle_t LPT_TaskHandle;
TaskHandle_t HPT_TaskHandle;

SemaphoreHandle_t binSemaphore_A = NULL;

void setup()
{  
  Serial.println("********************Priority Based Execution**************");
    Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(8, OUTPUT);
  //  Serial.println(F("In Setup function, Creating Binary Semaphore"));

    vSemaphoreCreateBinary(binSemaphore_A);  /* Create binary semaphore */

    if(binSemaphore_A != NULL)
    {
       // Serial.println(F("Creating low priority task"));
        xTaskCreate(LPT_Task, "LPT_Task", 128, NULL, 1, &LPT_TaskHandle);
    }
    else
    {
        Serial.println(F("Failed to create Semaphore"));
    }
}


void loop()
{ // Hooked to Idle Task, will run when CPU is Idle
   //Serial.println(F("Loop function"));
    //delay(50);
}


/*LPT: Low priority task*/
void LPT_Task(void* pvParameters)
{
    
    //xSemaphoreTake(binSemaphore_A,portMAX_DELAY);
Serial.println("LPT_Task Acquiring semaphore"); 
    //Serial.println("LPT_Task Creating HPT"); 
    xTaskCreate(HPT_Task, "HPT_Task", 128, NULL, 3, &HPT_TaskHandle); 
    Serial.println("Lower Priority RED LED Blinking");
    digitalWrite(8, HIGH);
  delay(5000);
  digitalWrite(8, LOW);
   Serial.println("LPT_Task Releasing the semaphore");
   // xSemaphoreGive(binSemaphore_A);

    //printMsg(LPT_TaskHandle,"LPT_Task Finally Exiting");
    vTaskDelete(LPT_TaskHandle);
}



/*HPT: High priority task*/
void HPT_Task(void* pvParameters)
{
    //Serial.println("HPT_Task Trying to Acquire the semaphore");
   // xSemaphoreTake(binSemaphore_A,portMAX_DELAY);
Serial.println("HPT_Task Acquiring semaphore"); 
    //printMsg(HPT_TaskHandle,"HPT_Task Acquired the semaphore");    
     digitalWrite(4, HIGH);
     Serial.println("Higher Priority Green LED Blinking");
//  digitalWrite(bluePin_2, HIGH);
//  digitalWrite(greenPin_2, LOW);
  delay(5000);
  digitalWrite(4, LOW);
    //printMsg(HPT_TaskHandle,"HPT_Task Releasing the semaphore");
    //xSemaphoreGive(binSemaphore_A);    

   Serial.println("HPT_Task About to Exit");
    vTaskDelete(HPT_TaskHandle);
}
