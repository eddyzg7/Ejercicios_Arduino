#include <Arduino_FreeRTOS.h>

// Definimos las dos tareas
void asterisco( void *pvParameters );
void barra( void *pvParameters );
void dolar( void *pvParameters );

void setup() {

  Serial.begin(9600);

  // Ahora configuramos dos tareas para que se ejecuten de forma independiente.
  xTaskCreate(
    asterisco
    ,  "asterisco"  // Nombre
    ,  128  // Tamaño
    ,  NULL //Parametros para la tarea
    ,  1  // Prioridad
    ,  NULL ); //Identificador de tareas

  xTaskCreate(
    barra
    ,  "barra" // Nombre
    ,  128  // Tamaño
    ,  NULL //Parametros para la tarea
    ,  1  // Prioridad
    ,  NULL ); //Identificador de tareas

  xTaskCreate(
    dolar
    ,  "dolar" // Nombre
    ,  128  // Tamaño
    ,  NULL //Parametros para la tarea
    ,  1  // Prioridad
    ,  NULL ); //Identificador de tareas
}

void loop()
{
  // Vacío. Las cosas se hacen en Tareas.
}

void asterisco( void *pvParameters )  // Tarea1
{
  for (;;) // Bucle infinito
  {
    Serial.println("*");
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}

void barra( void *pvParameters )  // Tarea 2
{
  for (;;)
  {
    Serial.println("/");
    vTaskDelay(15000 / portTICK_PERIOD_MS);
  }
}

void dolar( void *pvParameters )  // Tarea 3
{
  for (;;)
  {
    Serial.println("$");
    vTaskDelay(60000 / portTICK_PERIOD_MS);
  }
}
