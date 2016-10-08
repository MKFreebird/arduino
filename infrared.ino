#include <IRremote.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int recvPin = 10;
IRrecv irrecv(recvPin);
decode_results results;

void setup()
{
  lcd.begin(16, 2);
  lcd.print("Infrared Reader");
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results))
    {
     //lcd.clear();
     //Serial.println(results.value, HEX);
     lcd.setCursor(0, 1);
     lcd.print(results.value, HEX);
     irrecv.resume(); // Receive the next value
    }
}

