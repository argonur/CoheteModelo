/*####################################################
# Cohete Modelo - Circuito de activación a distancia #
# Web: www.argonur.com                               # 
# Autor: Arturo Gonzalez                             #
# Fecha: 16/05/2018                                  #
####################################################*/

#include <LiquidCrystal.h>

// lineas de control del LCD
const int rs = 12;
const int enable = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// parametros del LCD
const int renglones = 2;
const int columnas = 16;

// pines de botones, LEDs, etc.
const int emergencyStop = 6;
const int startButton = 7;
const int buzzer = 8;
const int greenLED = 13;

//variables
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  
  lcd.begin(columnas, renglones);

  pinMode(emergencyStop, INPUT);
  pinMode(startButton, INPUT);
  pinMode(greenLED, OUTPUT);  

  lcd.print("www.argonur.com");
  lcd.setCursor(0,1);
  lcd.print("Cohete Modelo");

}

void loop() {
  switchState = digitalRead(startButton);

  digitalWrite(greenLED, switchState);
  
  if(switchState != prevSwitchState){
      if(switchState == LOW){


        
        reply = random(4);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Estado:");
        lcd.setCursor(0, 1);

        switch(reply){
          case 0:
          lcd.print("Listo");
          break;
          case 1:
          lcd.print("Paro emergencia");
          break;
          case 2:
          lcd.print("Conteo: 10");
          break;
          case 3:
          lcd.print("Cohete lanzado");
          break;
          }

          tone(buzzer, 2000, 500);
      }
    }
    prevSwitchState = switchState;
}

