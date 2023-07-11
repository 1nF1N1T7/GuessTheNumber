#include <Keypad.h>
#include <LiquidCrystal.h>

char Keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[4] = {9, 8, 7, 6}; //connectedPinsR
byte colPins[4] = {5, 4, 3, 2}; //connectedPinsC

//class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(Keys), rowPins, colPins, 4, 4); 

//Class LCD
const int rs = 51, en = 49, d4 = 47, d5 = 45, d6 = 43, d7 = 41;//connectedPinsLCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2); 
  randomSeed(analogRead(0));
}

void Win(int n){
  lcd.setCursor(0,0);
  lcd.print("You Won With");
  lcd.setCursor(0,1);
  lcd.print(n);
  lcd.setCursor(6,1);
  lcd.print("Mistakes!!");
  delay(5000);
  loop();
}
void Easy(){
  char Key = customKeypad.getKey();
  String randNumber = String(random(1,10));
  float p = (100/10);
  int guesses = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Win Probability: ");
  lcd.setCursor(3,1);
  lcd.print(p);
  lcd.setCursor(8,1);
  lcd.print("%");
  delay(3000);
  lcd.clear();
  Serial.print(randNumber);
  lcd.print("Guess A Number");
  lcd.setCursor(0,1);
  lcd.print("Between: 1-10    ");
  
  while(1){
    if(Key){
    if(String(Key) == randNumber){
      lcd.clear();
      Win(guesses);
    }
    if(String(Key) > randNumber){
      guesses++;
      lcd.clear();
      lcd.setCursor(8,0);
      lcd.print(Key);
      lcd.setCursor(5,1);
      lcd.print("Smaller!!!");
    }
    if(String(Key) < randNumber){
      guesses++;
      lcd.clear();
      lcd.setCursor(8,0);
      lcd.print(Key);
      lcd.setCursor(5,1);
      lcd.print("Bigger!!!");
    }
   }
    Key = customKeypad.getKey();
    
 }  
}


void loop(){
  char Key = customKeypad.getKey();
  while(Key == 0){
    lcd.setCursor(0,0);
    lcd.print("Guess The Number");
    delay(500);
    lcd.setCursor(0,1);
    lcd.print("[Press Any Key]");
    delay(600);
    lcd.clear();
    Key = customKeypad.getKey();
  }
   Easy();
  
  
}








 
