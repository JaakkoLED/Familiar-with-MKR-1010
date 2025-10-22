#include <WiFiNINA.h>
// char = a,b,c,d ...
// int = 1,2,3,4...
//float = 1.2 , 2.5, 2.5...
// uint8_t = 0-255



#include <WiFiNINA.h>
int i;
void setup()
{
Serial.begin(9600);
}

void loop()
{

if (WiFi.status() == WL_NO_MODULE)
{
Serial.println("WiFi module not found!");
}

Serial.println("Scanning available networks...");
int numNetworks = WiFi.scanNetworks();

for (i = 0; i < numNetworks; i++)
{
  Serial.print("Network: ");
  Serial.print(WiFi.SSID(i));
  Serial.print(" | Signal Strength: ");
  Serial.print(WiFi.RSSI(i));
  Serial.print(" dBm | Encryption: ");
  Serial.println(WiFi.encryptionType(i));
}

delay(3000);

}