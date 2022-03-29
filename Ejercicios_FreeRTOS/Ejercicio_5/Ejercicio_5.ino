//Incluimos las librerías necesarias para funcionar con FreeRTOS
#include <Arduino_FreeRTOS.h>
#include "task.h"
#include "timers.h"

//Creamos dos variables globales para los temporizadores
TimerHandle_t xAutoReloadTimer, xOneShotTimer;

//Creamos las dos tareas de temporización
void oneShotTimerCallback(TimerHandle_t xTimer); //esta tarea se ejecutará 1 vez
void autoReloadTimerCallback(TimerHandle_t xTimer); //esta tarea se ejecutará 2 veces
 
void setup() {

  //inicializamos la comunicación serie
  Serial.begin(9600);
  
  //definimos los dos temporizadores
  xOneShotTimer    = xTimerCreate("OneShot", pdMS_TO_TICKS(60000), pdFALSE, 0, oneShotTimerCallback);
  xAutoReloadTimer = xTimerCreate("Reload" , pdMS_TO_TICKS(5000), pdTRUE , 0, autoReloadTimerCallback);
 
  //Si los dos temporizadores están apagados, encendemos ambos
  if((xOneShotTimer != NULL) && (xAutoReloadTimer != NULL)){
    xTimerStart(xOneShotTimer, 0);
    xTimerStart(xAutoReloadTimer, 0);
  }

}
 
void loop() {

}

//imprimimos el asterisco
void oneShotTimerCallback(TimerHandle_t xTimer){
  Serial.println("*");
}

//imprimimos el porcentaje
void autoReloadTimerCallback(TimerHandle_t xTimer){
  Serial.println("%");
}

