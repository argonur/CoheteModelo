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
      //lanzar cohete
      digitalWrite(ledAmarillo, HIGH);
  }

  if (cuenta == 0){
    digitalWrite(ledAmarillo, LOW);
    estadoActual = Lanzado;  
  }
  
}

void estadoLanzado(void){


}


void cuentaRegresiva(void){

  int tiempo = millis();
  if ((tiempo - tiempoInicio) > 1000) {
    cuenta--;
    tiempoInicio = tiempo;
  }
   
}



