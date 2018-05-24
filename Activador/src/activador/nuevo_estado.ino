  /*####################################################
  # Cohete Modelo - Circuito de activación a distancia #
  # Web: www.argonur.com                               # 
  # Autor: Arturo Gonzalez                             #
  # Fecha: 24/05/2018                                  #
  ####################################################*/



      
void nuevoEstado(void){

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
      lcd.print("Conteo:");
      break;
    
    case Lanzado:
      lcd.print("Cohete lanzado");
      break;

    default:
      lcd.print("Falla");
  }  
    
}
