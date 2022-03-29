// C++ code
//
int LDR = A0;
int led = 6;

float ldr;
float valor_base = 0.8;
float umbral = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(LDR, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  ldr = analogRead(LDR);
  ldr = ldr * 5 / 1023;

  if (ldr > umbral + valor_base ) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  Serial.print(ldr);
  Serial.println("");
  //delay(200);
}
