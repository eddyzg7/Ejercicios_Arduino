
// Include Arduino FreeRTOS library
#include <Arduino_FreeRTOS.h>

// Include semaphore supoport
#include <semphr.h>

/* 
 * Declaring a global variable of type SemaphoreHandle_t 
 * 
 */
SemaphoreHandle_t interruptSemaphore;

void setup() {

  Serial.begin(9600);

  // Configure pin 2 as an input with a  pull-down resistor
  pinMode(2, INPUT);

 // Create task for Arduino button
  xTaskCreate(BotonPulsado, // Task function
              "BotonPulsado", // Task name
              128, // Stack size 
              NULL, 
              0, // Priority
              NULL );

  /**
   * Create a binary semaphore.
   * https://www.freertos.org/xSemaphoreCreateBinary.html
   */
  interruptSemaphore = xSemaphoreCreateBinary();
  if (interruptSemaphore != NULL) {
    // Attach interrupt for Arduino digital pin 2
    attachInterrupt(digitalPinToInterrupt(2), interruptHandler, RISING);
  }

  
}

void loop() {}

void interruptHandler() {
  /**
   * Give semaphore in the interrupt handler
   * https://www.freertos.org/a00124.html
   */
  
  xSemaphoreGiveFromISR(interruptSemaphore, NULL);
}

void BotonPulsado(void *pvParameters)
{
  (void) pvParameters;

  for (;;) {
    
    /**
     * Take the semaphore.
     * https://www.freertos.org/a00122.html
     */
    if (xSemaphoreTake(interruptSemaphore, portMAX_DELAY) == pdPASS) {
      Serial.println("Boton pulsado");
    }
    vTaskDelay(10);
  }
}
