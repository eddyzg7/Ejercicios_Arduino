// C++ code

#include <MsTimer2.h>

int bocina = 6;

static boolean output = HIGH;

void flash()
{
  digitalWrite(bocina, output);
  output = !output;
}

void setup()
{
  Serial.begin(9600);
  pinMode(bocina, OUTPUT);

  MsTimer2::set(2000, flash); // 500ms period
  MsTimer2::start();
}

void loop()
{
  Serial.println(output);
}
