// C++ code
//
int cny = 2;
int bocina = 6;
int estado;

void setup()
{
  Serial.begin(9600);
  pinMode(cny, INPUT);
  pinMode(bocina, OUTPUT);

}

void loop()
{
  estado = digitalRead(cny); 
  
  if (estado == 1) {
    digitalWrite(bocina, HIGH);
  } else {
    digitalWrite(bocina, LOW);
  }

  Serial.println(estado);
}
