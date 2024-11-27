#include "DHT.h"
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
const int PINDHT= 2;
const int DHTTYPE = DHT11;
DHT dht(PINDHT,DHTTYPE);
int i;
LiquidCrystal_I2C lcd(0x3F,16,2);
Adafruit_BMP085 bmp;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  //lcd.begin(16,2);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
 if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  float doam = dht.readHumidity();
  float nhietdo = dht.readTemperature();
  int value = analogRead(A3);
  Serial.print("nhiet do la ");
  Serial.print(nhietdo);
  Serial.println(" *c");
  Serial.print("do am la ");
  Serial.print(doam);
  Serial.println(" %");
  Serial.print("luong mua la ");
  Serial.print(value);
  Serial.println();
  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");
  Serial.print("Altitude = ");
  Serial.print(bmp.readAltitude());
  Serial.println(" meters");
  Serial.print("Pressure at sealevel (calculated) = ");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");
  Serial.print("Real altitude = ");
  Serial.print(bmp.readAltitude(101500));
  Serial.println(" meters");
  Serial.println();
  delay(500);
  Serial.print("Value : ");
  Serial.print(value);
  lcd.setCursor(0,0);
  lcd.print("do am:");
  lcd.setCursor(6,0);
  lcd.print(doam);
  lcd.setCursor(0,1);
  lcd.print("nhiet do:");
  lcd.setCursor(9,1);
  lcd.print(nhietdo);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("luong mua la ");
  lcd.setCursor(0,1);
  lcd.print(value);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pressure = ");
  lcd.setCursor(0,1);
  lcd.print(bmp.readPressure());
  lcd.setCursor(5,1);
  lcd.print("PA");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Altitude = ");
  lcd.setCursor(0,1);
  lcd.print(bmp.readAltitude());
  lcd.setCursor(4, 1);
  lcd.print("m");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Pressure at sealevel (calculated) = ");
  lcd.setCursor(0, 1);
  lcd.print(bmp.readSealevelPressure());
  lcd.setCursor(4, 1);
  lcd.print("m");
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Real altitude = ");
  lcd.setCursor(0, 1);
  lcd.print(bmp.readAltitude(101500));
  lcd.setCursor(4, 1);
  lcd.print("m");
  delay(1000);
  lcd.clear();
}
