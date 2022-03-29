// C++ code
//
int LDR = A0;
float ldr;

void setup()
{
  Serial.begin(9600);
  pinMode(LDR, INPUT);
}

void loop()
{
  ldr = analogRead(LDR);
  ldr = ldr*5/1023;
  Serial.print(ldr);
  Serial.println("");
  //delay(200);
}
