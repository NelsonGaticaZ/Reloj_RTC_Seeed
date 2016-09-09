//Creado por: Nelson Gatica | Fecha: 2016-09-01
//Modificado por: Nelson Gatica | Fecha: 2016-09-09
//Este es el código de la rama de prueba1
#include <DS1337.h>
#include <Wire.h>

DS1337 RTC;

void setup(){                
  Serial.begin(9600);//Se cambio la velocidad serial
  RTC.start(); // ensure RTC oscillator is running, if not already
}

void loop()                     
{
  Serial.flush();
  Serial.println ("\nRTC Library Tests \n 1) Basic (read and write time)");

  while(!Serial.available()){}
  
  switch(Serial.read())
  {
    case '1':
      test_basic();
      break;
    default:
      break;   
  }
}

void test_basic()
{
  // Test basic functions (time read and write)
  Serial.print("The current time is (anterior) ");
  RTC.readTime(); // update RTC library's buffers from chip
  printTime(0);//Si "0" Imprime la fecha, Si "1" Imprime solo la hora
    
    //Seteo Usando hora y fecha  
    RTC.setSeconds(01);
    RTC.setMinutes(21);
    RTC.setHours(15);
    RTC.setDays(29);
    RTC.setMonths(8);
    RTC.setYears(2016); // 2-digit or 4-digit years are supported
    RTC.writeTime();
    delay(500);  
     
    //Serial.println("Setting time using epoch seconds:");
    //RTC.writeTime(1471875228);
    delay(500);  
    RTC.readTime();    
    Serial.print("The current time is (ahora)");
    printTime(0);//Si "0" Imprime la fecha, Si "1" Imprime solo la hora
 }

void printTime(byte type)
{
  if(!type)
  {
    Serial.print("  ");
    Serial.print(int(RTC.getMonths()));
    Serial.print("/");  
    Serial.print(int(RTC.getDays()));
    Serial.print("/");  
    Serial.print(RTC.getYears());
  }
  
  Serial.print("  ");
  Serial.print(int(RTC.getHours()));
  Serial.print(":");
  Serial.print(int(RTC.getMinutes()));
  Serial.print(":");
  Serial.print(int(RTC.getSeconds()));  
}
