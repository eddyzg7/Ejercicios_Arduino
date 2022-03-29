// C++ code
//

int Led_1 = 3;
int Led_2 = 4;
int Led_3 = 5;
int Led_4 = 6;
int Led_5 = 7;

int estado = 1;
int tmax = 300;
int tmin = 200;
int tresta = 50;
int tbocina = 3000;

volatile int tiempo = 300;
volatile int aux = 0;

int Bocina = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
  pinMode(Led_5, OUTPUT);
  pinMode(Bocina, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), Pulsante, RISING);
}

void loop()
{
  switch (estado) {
    case 1:
      digitalWrite(Led_1, HIGH);
      delay(tiempo);
      digitalWrite(Led_1, LOW);
      delay(tiempo);
      estado = 2;
      break;
    case 2:
      digitalWrite(Led_2, HIGH);
      delay(tiempo);
      digitalWrite(Led_2, LOW);
      delay(tiempo);
      estado = 3;
      break;
    case 3:
      digitalWrite(Led_3, HIGH);
      delay(tiempo);
      digitalWrite(Led_3, LOW);
      delay(tiempo);
      estado = 4;
      break;
    case 4:
      digitalWrite(Led_4, HIGH);
      delay(tiempo);
      digitalWrite(Led_4, LOW);
      delay(tiempo);
      estado = 5;
      break;
    case 5:
      digitalWrite(Led_5, HIGH);
      delay(tiempo);
      digitalWrite(Led_5, LOW);
      delay(tiempo);
      estado = 1;
      break;
    case 6:
      digitalWrite(Bocina, HIGH);
      delay(tbocina);
      digitalWrite(Bocina, LOW);
      estado = 1;
      tiempo = tmax;
      aux = 0;
      break;
  }

  if (aux != 0) {
    estado = 6;
  }

  Serial.println(estado);
  Serial.println(tiempo);
  Serial.println("------");

}

void Pulsante () {

  if (estado == 1 ) {
    tiempo = tiempo - tresta;
    if (tiempo == tmin) {
      aux = 1;
    }
  } else {
    tiempo = tmax;
  }

}
