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

// pines de botones, LEDs, salidas, etc.
const int paroEmergencia = 6;
const int botonInicio = 7;
const int bocina = 8;
const int salidaLanzador = 13;

//variables
LiquidCrystal lcd(rs, enable, d4, d5, d6, d7);

bool statusBotonInicio = false;
bool statusParoEmergencia = true;

int tiempoInicio = 0;
int cuenta = 0;

//Estados de la máquina de estados
enum Estado{Inicio, Paro, Listo, Conteo, Lanzado};
Estado estadoActual = Inicio;
Estado estadoPrevio = estadoActual;

//Ordenes para la salida activadora
enum EstadoLanzador{activar, desactivar};

void setup() {
  
  lcd.begin(columnas, renglones);

  pinMode(paroEmergencia, INPUT);
  pinMode(botonInicio, INPUT);
  pinMode(salidaLanzador, OUTPUT);  

  lcd.print("www.argonur.com");
  lcd.setCursor(0,1);
  lcd.print("Cohete Modelo");

  delay(3000);
  
  configurarEstado();
}

void loop() {

  leerEntradas();
  
  if (estadoPrevio != estadoActual) {
    configurarEstado();  
  }
  estadoPrevio = estadoActual;
  
  //máquina de estados
  switch(estadoActual){

    case Inicio:
      estadoInicio();
      break;
    
    case Paro:
      estadoParo();
      break;
    
    case Listo:
      estadoListo();
      break;
    
    case Conteo:
      estadoConteo();
      break;
    
    case Lanzado:
      estadoLanzado();
      break;

    //default:
      //no debe suceder nunca
    
  }
      
}



