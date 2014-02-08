#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define DHT11_ERROR 255
#define PINX PIND.3
#define PORTX PORTD.3
#define DDRX  DDRD.3
#define OUTPUT 1
#define INPUT 0
#define LOW 0
#define HIGH 1
//potrebuje timer nastaveny na 2000khz
void iniDHT11();
char readDHT11(char mode);//mode t =temperature, mode h=humidity