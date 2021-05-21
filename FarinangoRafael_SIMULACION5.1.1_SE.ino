/*
 *CAPITULO V: FUNCIONES ESPECIALES
 *CODIGO 19.1: LECTURA Y ESCRITURA DE DATOS EN LA EEPROM
 *OBJETIVO: ALAMACENAR 10 VALORES DEL CAD Y LUEGO VIZUALIZARLOS
 *NOMBRE: RAFAEL FARINANGO
 */

#include <EEPROM.h>

const int led1 = 13;
const int sw = 7; 

 
void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(sw,INPUT);
  if(digitalRead(sw) == 0){
    Serial.println("Lectura de Memoria:");
    for(int i=0; i<10 ; i++){
      Serial.println(EEPROM.read(i));
      delay(100);
    }
  }
  else{
    Serial.println("Almacenando 10 Datos:");
    for(int j=0; j<10; j++){
      digitalWrite(led1,HIGH);
      delay(100);
      digitalWrite(led1,LOW);
      delay(100);
      digitalWrite(led1,HIGH);
      delay(100);
      int dato = analogRead(A0);
      dato = map(dato,0,1023,0,255);
      EEPROM.write(j,dato);
      Serial.println(dato);
      digitalWrite(led1,LOW);
      delay(500);
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:

}
