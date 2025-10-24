//12- BIT ADC muunnin
// 2^12 = 4096 (0-4095)
//analogRead(A1);

int analogValue = 0;

void setup()
{
  pinMode(1, OUTPUT);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
}

void loop()
{
  digitalWrite(4, HIGH);
  analogValue = analogRead(A1);

  Serial.print("The value of the potentiometer: ");
  Serial.println(analogValue);

  digitalWrite(1, HIGH);
  delay(1000);
  digitalWrite(1, LOW);
  delay(1000);
}
