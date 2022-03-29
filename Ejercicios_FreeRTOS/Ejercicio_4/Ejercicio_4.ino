// Include Arduino FreeRTOS library
#include <Arduino_FreeRTOS.h>

// Include queue support
#include <queue.h>

/* 
 * Declaring a global variable of type QueueHandle_t 
 * 
 */
QueueHandle_t integerQueue;

void setup() {

  //Creamos la cola
  integerQueue = xQueueCreate(4, // Queue length
                              sizeof(int) // Queue item size
                              );
  
  if (integerQueue != NULL) {
    
    // Create task that consumes the queue if it was created.
    xTaskCreate(TaskSerial, // Task function
                "Serial", // A name just for humans
                128,  // This stack size can be checked & adjusted by reading the Stack Highwater
                NULL, 
                2, // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
                NULL);


    // Create task that publish data in the queue if it was created.
    xTaskCreate(Task1, // Task function
                "Task1", // Task name
                128,  // Stack size
                NULL, 
                1, // Priority
                NULL);
    
    // Create task that publish data in the queue if it was created.
    xTaskCreate(Task2, // Task function
                "Task2", // Task name
                128,  // Stack size
                NULL, 
                1, // Priority
                NULL);
    
    // Create task that publish data in the queue if it was created.
    xTaskCreate(Task3, // Task function
                "Task3", // Task name
                128,  // Stack size
                NULL, 
                1, // Priority
                NULL);
    
    // Create task that publish data in the queue if it was created.
    xTaskCreate(Task4, // Task function
                "Task4", // Task name
                128,  // Stack size
                NULL, 
                1, // Priority
                NULL);
  }
}




void loop() {}


void Task1(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;)
  {
    // definimos el valor que mostraremos
    int valor = 1;

    /**
     * Post an item on a queue.
     * https://www.freertos.org/a00117.html
     */
    xQueueSend(integerQueue, &valor, portMAX_DELAY);

    // One tick delay (15ms) in between reads for stability
    vTaskDelay(1);
  }
}

void Task2(void *pvParameters){
  (void) pvParameters;
  
  for (;;)
  {
    //  definimos el valor que mostraremos
    int valor = 2;

    /**
     * Post an item on a queue.
     * https://www.freertos.org/a00117.html
     */
    xQueueSend(integerQueue, &valor, portMAX_DELAY);

    // One tick delay (15ms) in between reads for stability
    vTaskDelay(1);
  }
}

void Task3(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;)
  {
    //  definimos el valor que mostraremos
    int valor = 3;

    /**
     * Post an item on a queue.
     * https://www.freertos.org/a00117.html
     */
    xQueueSend(integerQueue, &valor, portMAX_DELAY);

    // One tick delay (15ms) in between reads for stability
    vTaskDelay(1);
  }
}

void Task4(void *pvParameters)
{
  (void) pvParameters;
  
  for (;;)
  {
    // definimos el valor que mostraremos
    int valor = 4;

    /**
     * Post an item on a queue.
     * https://www.freertos.org/a00117.html
     */
    xQueueSend(integerQueue, &valor, portMAX_DELAY);

    // One tick delay (15ms) in between reads for stability
    vTaskDelay(1);
  }
}

/**
 * Serial task.
 * Prints the received items from the queue to the serial monitor.
 */
void TaskSerial(void * pvParameters) {
  (void) pvParameters;

  // Init Arduino serial
  Serial.begin(9600);

  // Wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  while (!Serial) {
    vTaskDelay(1);
  }

  int valueFromQueue = 0;

  for (;;) 
  {

    /**
     * Read an item from a queue.
     * https://www.freertos.org/a00118.html
     */
    if (xQueueReceive(integerQueue, &valueFromQueue, portMAX_DELAY) == pdPASS) {
      Serial.println(valueFromQueue);
    }
  }
}

