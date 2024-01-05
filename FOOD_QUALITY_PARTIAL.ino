  
#include<LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int lm35_pin = A1; 
float a; 
void setup() {
   pinMode(5, OUTPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600); 
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.println("FOOD QUAlITY");
  lcd.setCursor(0, 1);
  lcd.println("MONITORING");
  delay(2000);
  lcd.clear();

}

void loop() {
  
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  
  temp_val = (temp_adc_val * 4.88); 
  temp_val = (temp_val/80); 
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  lcd.setCursor(0, 0);
  lcd.print("TEMPERATURE:");
  lcd.println(temp_val);
  delay(2000);
  lcd.clear();
  Serial.print(" Degree Celsius\n");
  delay(1000);

  a=analogRead(A5);
  Serial.print("SMELLING: ");
  Serial.println(a);
  lcd.setCursor(0, 0);
  lcd.print("SMELLING::");
  lcd.println(a);
  delay(2000);
  lcd.clear();
    
 
  if (a>=600)
  {
     Serial.print("FOOD DAMAGE ");
     lcd.setCursor(0, 0);
    lcd.print("FOOD DAMAGE:");
    digitalWrite(5, HIGH); 
  delay(1000);
    
  }
  else
  {
    Serial.print("FOOD OK ");
    digitalWrite(5, LOW); 
  delay(1000);
}
if  (temp_val<=28)
{
  Serial.print("FOOD DAMAGE ");
     lcd.setCursor(0, 0);
    lcd.print("FOOD DAMAGE:");
    digitalWrite(5, HIGH); 
  delay(1000);
    
  }
  else
  {
    Serial.print("FOOD OK ");
    digitalWrite(5, LOW); 
  delay(1000);

  }
}
