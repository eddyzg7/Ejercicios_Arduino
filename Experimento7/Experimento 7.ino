// C++ code
//
int pulsador = 2;
int bocina = 6;
volatile int estado = 0;
volatile int c = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pulsador, INPUT);
  pinMode(bocina, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(2), interruptor, RISING);
}

void loop()
{

  if (estado == 1) {
    digitalWrite(bocina, HIGH);
  } else {
    digitalWrite(bocina, LOW);
  }

  Serial.println(c);
}

void interruptor(){
  estado = !estado;
  c = c + 1;
  }
