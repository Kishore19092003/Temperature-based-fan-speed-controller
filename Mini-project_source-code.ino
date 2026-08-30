#include <LiquidCrystal.h> 
#include <OneWire.h> 
#include <DallasTemperature.h> 
#define ONE_WIRE_BUS 14  
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire); 
float temperature; 
#include <SoftwareSerial.h> 
int rs=13,en=12,d4=8,d5=9,d6=10,d7=11; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); 
int fan=7; 
void setup()  
{ 
pinMode(fan,OUTPUT); 
digitalWrite(fan,LOW); 
Serial.begin(9600); 
lcd.begin(16, 2); 
lcd.clear(); 
lcd.print("TEMPERATURE "); 
lcd.setCursor(0, 1); 
lcd.print("CONTROLLED FAN"); 
delay(1000); 
}
void loop()  
{ 
HUMIDITY_MEASUREMENT(); 
} 
void HUMIDITY_MEASUREMENT() 
{ 
sensors.requestTemperatures();  
temperature = sensors.getTempCByIndex(0);
Serial.print("$Temperature: "); 
Serial.print(temperature); 
Serial.println("#"); 
lcd.clear(); 
lcd.print("TEMP: "); 
lcd.setCursor(6, 0); 
lcd.print(temperature); 
delay(1000);     
if (temperature>30) 
{ 
digitalWrite(fan,HIGH); 
lcd.clear(); 
lcd.print("MORE TEMPERATURE "); 
lcd.setCursor(0, 1); 
lcd.print(" FAN ON"); 
delay(1000); 
// voltage(); 
} 
else 
{ 
digitalWrite(fan,LOW); 
lcd.clear(); 
lcd.print("LESS TEMPERATURE "); 
lcd.setCursor(0, 1); 
lcd.print(" FAN OFF"); 
delay(1000); 
} 
}
