// C++ code
//
int pulsador = 2;
int bocina = 6;
int estado;

void setup()
{
  Serial.begin(9600);
  pinMode(pulsador, INPUT);
  pinMode(bocina, OUTPUT);
}

void loop()
{
  estado = digitalRead(pulsador);

  if (estado == 1) {
    digitalWrite(bocina, HIGH);
  } else {
    digitalWrite(bocina, LOW);
  }

  Serial.println(estado);
}
