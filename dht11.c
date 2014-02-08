#include "dht11.h"

void iniDHT11(){
  DDRX = OUTPUT;
  PORTX = HIGH; 
  delay_ms(1000);       
}
void resetWire(){
  DDRX = OUTPUT;
  PORTX = HIGH; 
}
char readDHT11(char mode) {
   long poc=0;
   int j,i;
   char data[5];
   for(i=0;i<5;i++) data[i] = 0;
//startovaci signal pre prenos
  PORTX = LOW;
  delay_ms(20);
  PORTX = HIGH;
  delay_us(1);
  DDRX = INPUT;
  //test komunikacie od dht11
  TCNT0 = 0;
  while(PINX == 1)      if(TCNT0 > 50){   resetWire();  return DHT11_ERROR;}
  TCNT0 = 0;
  while(PINX == 0)      if(TCNT0 > 180){  resetWire();  return DHT11_ERROR;}
  TCNT0 = 0;
  while(PINX == 1)      if(TCNT0 > 180){  resetWire();  return DHT11_ERROR;}
  //--------------------------
  for(i=0;i<5;i++){
        for(j=7;j>=0;j--){
                TCNT0 = 0;
                while(PINX == 0)      if(TCNT0 > 120){  resetWire();   return DHT11_ERROR; }
                TCNT0 = 0;
                while(PINX == 1)      if(TCNT0 > 180){  resetWire();   return DHT11_ERROR;}
                if(TCNT0 > 90) data[i]|=1<<j;        
        }
  }
  resetWire();
  if((data[0]+data[1]+data[2]+data[3]) != data[4])return DHT11_ERROR;
  if (mode == 't')      return data[2];
  else                  return data[0];
}