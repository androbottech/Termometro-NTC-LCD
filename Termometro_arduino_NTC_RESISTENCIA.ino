#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// the value of the 'other' resistor
#define SERIESRESISTOR 10000    
 
// What pin to connect the sensor to
#define THERMISTORPIN A0 

void setup() 
{
 lcd.begin(16, 2);
}

void loop() 
{
    float reading;
   
    reading = analogRead(THERMISTORPIN);
   
    //Serial.print("Analog reading "); 
    //Serial.println(reading);
   
    // convert the value to resistance
    reading = (1023 / reading)  - 1;     // (1023/ADC - 1) 
    reading = SERIESRESISTOR / reading;  // 10K / (1023/ADC - 1)
   lcd.clear();
   lcd.home();
   lcd.print("Thermistor R =");
   lcd.setCursor(4,1);
   lcd.print(reading);
   delay(1000);
}
