
#include <BleKeyboard.h>
#define led 14
BleKeyboard bleKeyboard;
int buttonState = 0;
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
  buttonState = digitalRead(12); 
  Serial.print("Stato del bottone...");
  Serial.println(buttonState);
  
  if(buttonState==HIGH){
    Serial.println("HO PREMUTO S");
    bleKeyboard.press('s');
    digitalWrite(led, HIGH);
  } 
  if(buttonState==LOW){
      bleKeyboard.releaseAll();
      Serial.println("RILASCIATO");
      digitalWrite(led, LOW);
      //OZ merda
  }}}
