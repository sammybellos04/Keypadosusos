#include <BleKeyboard.h>
#define led 14
BleKeyboard bleKeyboard;
int buttonStates = 0;
int buttonStated = 0;
void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if(bleKeyboard.isConnected()) {
  digitalWrite(13, HIGH);
  buttonStates = digitalRead(12);
  buttonStated = digitalRead(14); 
  Serial.print("Stato del bottone...");
  Serial.println(buttonStates);
  Serial.println(buttonStated);
  
    if(buttonStates==HIGH){
      Serial.println("HO PREMUTO S");
      bleKeyboard.press('s');
    } 

   if(buttonStated==HIGH){
     Serial.println("HO PREMUTO D");
     bleKeyboard.press('d');
    } 

    if(buttonStates==LOW){
        bleKeyboard.releaseAll();
        Serial.println('s');   
    }

   if(buttonStated==LOW){
        bleKeyboard.release('d');
       Serial.println("RILASCIATO");   
    }
  }
}
