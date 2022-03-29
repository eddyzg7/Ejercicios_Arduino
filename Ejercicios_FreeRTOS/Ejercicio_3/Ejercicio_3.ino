#include <Arduino_FreeRTOS.h>

static const char *pcTextForTask1 = "0";
static const char *pcTextForTask2 = "1";

void vTaskFuction( void *pvParameters );

void setup() {
  Serial.begin(9600);
  xTaskCreate(vTaskFuction,"Abecedario",128,(void *)pcTextForTask1,1,NULL);
  xTaskCreate(vTaskFuction,"Numeros",128,(void *)pcTextForTask2,1,NULL);             
}

void loop() {
}

void Abecedario() {    //Funcion Abecedario
  for (byte index = 0; index < 26; index++) {
    Serial.write('A' + index);
    Serial.println(F(""));
  }
}
void Numeros() {    //Funcion Numeros
  for (int counter = 0; counter < 10; counter++) {
    Serial.write('0' + counter);
    Serial.println(F(""));
  }
}

void vTaskFuction(void * pvParameters) {
  char * pcTaskName;
  pcTaskName =  ( char *) pvParameters;
  for (;;) { //Bucle infinito
    if (pcTaskName == "0") {
      Abecedario();
    } else if (pcTaskName == "1") {
      Numeros();
    } else {
      Serial.print("Llega esto: ");
      Serial.println(pcTaskName);
      }
  }
}
