// C++ code
//

const int sensorPin = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop()
{
  int value = analogRead(sensorPin);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  Serial.print(celsius);
  Serial.println(" ºC");
  delay(1000);
  float Fah = (celsius * 1.8) + 32;
  Serial.print(Fah);
  Serial.println(" ºF");
  delay(1000);
}
