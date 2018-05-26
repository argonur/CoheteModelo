  /*####################################################
  # Cohete Modelo - Circuito de activación a distancia #
  # Web: www.argonur.com                               # 
  # Autor: Arturo Gonzalez                             #
  # Fecha: 24/05/2018                                  #
  ####################################################*/

void leerEntradas (void){
  
    statusBotonInicio = digitalRead(botonInicio);
    statusParoEmergencia = digitalRead(paroEmergencia);

}

void alarma(void) {

  if ( (cuenta <= 12) && (cuenta >= 6) ) 
  {
    tone(bocina, 2000, 100);
    return;
  }

  if ( cuenta == 5 ) 
  {
    tone(bocina, 2000, 300);
    return;
  }

  if ( cuenta == 4 ) 
  {
    tone(bocina, 2000, 400);
    return;
  }

  if ( cuenta == 3 ) 
  {
    tone(bocina, 2000, 600);
    return;
  }

  if ( cuenta == 2 ) 
  {
    tone(bocina, 2000, 2000);
    return;
  }
   
}

void lanzador(EstadoLanzador estado) {

  if (estado == activar){
    digitalWrite(salidaLanzador, HIGH);
  }

  if (estado == desactivar){
    digitalWrite(salidaLanzador, LOW);
  }

}
