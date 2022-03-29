#include <Arduino_FreeRTOS.h>

// Definimos las dos tareas
void abecedario( void *pvParameters );
void numeros( void *pvParameters );

void setup() {

  Serial.begin(9600);

  // Ahora configuramos dos tareas para que se ejecuten de forma independiente.
  xTaskCreate(
    abecedario
    ,  "abecedario"  // Nombre
    ,  128  // Tamaño
    ,  NULL //Parametros para la tarea
    ,  2  // Prioridad
    ,  NULL ); //Identificador de tareas

  xTaskCreate(
    numeros
    ,  "numeros" // Nombre
    ,  128  // Tamaño
    ,  NULL //Parametros para la tarea
    ,  1  // Prioridad
    ,  NULL ); //Identificador de tareas
}

void loop()
{
  // Vacío. Las cosas se hacen en Tareas.
}


void abecedario( void *pvParameters )  // Tarea1
{

  for (;;) // Bucle infinito
  {
    for (byte index = 0; index < 26; index++) {
      Serial.write('A' + index);
      Serial.println(F(""));
    }
  }
}

void numeros( void *pvParameters )  // Tarea 2
{

  for (;;)
  {
    for (int index = 0; index < 10; index++) {
      Serial.println(index);
    }

  }
}
