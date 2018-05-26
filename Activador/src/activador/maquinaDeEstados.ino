  /*####################################################
  # Cohete Modelo - Circuito de activación a distancia #
  # Web: www.argonur.com                               # 
  # Autor: Arturo Gonzalez                             #
  # Fecha: 24/05/2018                                  #
  ####################################################*/

void estadoInicio(void){
  
  if (statusParoEmergencia) {
      estadoActual = Paro;  
    } else {
      estadoActual = Listo;
    }
    
}

void estadoListo(void){

  if (statusBotonInicio && (!statusParoEmergencia)) {    
      estadoActual = Conteo;    
    }
  
  if (statusParoEmergencia) {
      estadoActual = Paro;  
    }

}

void estadoParo(void){
  
  if (!statusParoEmergencia) {
      estadoActual = Listo;  
    }

}

void estadoConteo(void){


  cuentaRegresiva();

  if (statusParoEmergencia && (cuenta >= 2)) {
      estadoActual = Paro;
      return;  
  }

  if (cuenta == 2){
      lanzador(activar);
  }

  if (cuenta == 0){
    lanzador(desactivar);
    estadoActual = Lanzado;  
  }
  
}

void estadoLanzado(void){


}

void configurarEstado(void){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estado:");
  lcd.setCursor(0, 1);

  switch(estadoActual){

    case Inicio:
      lcd.print("Inicio");
      //delay(2000);
      break;
    
    case Paro:
      lcd.print("Paro emergencia");
      break;
    
    case Listo:
      lcd.print("Listo");
      break;
    
    case Conteo:
      tiempoInicio = millis();
      cuenta = 12;
      alarma();
      mostrarConteo(cuenta - 2);
      break;
    
    case Lanzado:
      lcd.print("Cohete lanzado");
      break;

    default:
      lcd.print("Falla");
  }  
    
}

void cuentaRegresiva(void){

  int tiempo = millis();
  if ((tiempo - tiempoInicio) > 1000) {
    cuenta--;
    tiempoInicio = tiempo;

    alarma();
    
    mostrarConteo(cuenta - 2);    
  }

}

void mostrarConteo( int numero ) {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Cuenta regresiva");
  lcd.setCursor(0, 1);

  if ( numero >= 0 ) 
  {
    lcd.print( numero );
  }
}

