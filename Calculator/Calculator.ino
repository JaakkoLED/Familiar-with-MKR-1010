#include <WiFiNINA.h> 

void setup() {
  Serial.begin(9600); // Speed for the data transfer
  while (!Serial);
  Serial.println("Arduino Calculator ready. Enter the calculation (e.g. 50*2):");
}


void loop() {
  
if (Serial.available() > 0)
{
  String input = Serial.readStringUntil('\n');
  input.trim();
  
  if (input.length() == 0)
  {
    return; 
  }

  Serial.print("Syöte: ");
  Serial.println(input);
    
  char operaattori = ' ';
  int operaattoriIndex = -1;

   
  if (input.indexOf('+') != -1)
  {
    operaattori = '+';
    operaattoriIndex = input.indexOf('+');
  }
    
  else if (input.indexOf('-') != -1)
  {
    operaattori = '-';
    operaattoriIndex = input.indexOf('-');
  }

  else if (input.indexOf('*') != -1)
  {
    operaattori = '*';
    operaattoriIndex = input.indexOf('*');
  }

  else if (input.indexOf('/') != -1)
  {
    operaattori = '/';
    operaattoriIndex = input.indexOf('/');
  }

  if (operaattoriIndex != -1)
  {
     
      String luku1Str = input.substring(0, operaattoriIndex);
      String luku2Str = input.substring(operaattoriIndex + 1); 
      
      
      float luku1 = luku1Str.toFloat();
      float luku2 = luku2Str.toFloat();
      float tulos = 0.0;

      
      switch (operaattori)
      {
        case '+':
          tulos = luku1 + luku2;
          break;
        case '-':
          tulos = luku1 - luku2;
          break;
        case '*':
          tulos = luku1 * luku2;
          break;
        case '/':
          if (luku2 != 0) //chechks that the denominator isnt 0
          { 
            tulos = luku1 / luku2; 
          }
          else
          {
            Serial.println("❌ Error: Division by zero is not allowed..");
            Serial.println("Enter a new calculation:");
            return;
          }
          break;
      }
      
      
      Serial.print("Tulos: ");
      Serial.println(tulos, 2);
      
    }
    
    else
    {
      Serial.println("❌ Error: Coudln't find the right operation (+, -, *, /).");
    }
    
    Serial.println("Enter a new calculation:");
  }
}
