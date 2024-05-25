#include <Arduino.h>
const int adcPin = A0;
  
// calculate your own m using ph_calibrate.ino
// When using the buffer solution of pH4 for calibration, m can be derived as:
 // m = (pH7 - pH4) / (Vph7 - Vph4)
const float m = -6.0994; 

void setup()
{
   Serial.begin(115200);
}

void loop() 
{
   float Po = analogRead(adcPin) * 5.0 / 1024;
   float phValue = 7.2 - (2.622 - Po) * m;
   Serial.print("p h value = "); 
   Serial.println(phValue);
   delay(5000);
}
