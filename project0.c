#include "lib/include.h"

unsigned long Led;

void Delay(void){unsigned long volatile time;
  time = 1333333;
  while(time){
		time--;
  }
}

int main(void){

  SYSCTL->RCGCGPIO |=(1<<5); //Activar reloj puerto F
  GPIOF ->LOCK = 0x4C4F434B; //Desbloquear el puerto F
  GPIOF->CR = (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0); //Cambios del PF4
  GPIOF->AMSEL = 0x00; // ) Desabilitar analogco en PF
  GPIOF->PCTL = 0x00000000;   // ) PCTL GPIO on PF4-0
  GPIOF->DIR = 0x0E; // ) PF4,PF0 entrada, PF3-1 salida
  GPIOF->AFSEL =  0x00;   // ) Desabiltar la funcion Alt en PF7-0
  GPIOF->PUR = 0x11;   //Habilitar pull-up en PF0 and PF4
  GPIOF->DEN = (1<<4) | (1<<3) | (1<<2) | (1<<1) | (1<<0);  // ) Habilitar Entrada/Salida digital en PF4-0
  //SYSCTL->RCGC2 |= 0x00000020;
 // SYSCTL_RCGC2_R |= 0x00000020;     // 1) Activar reloj para el puerto F
   while(1){
   //if(PF4 == 0x0) {
    Led = 0x02;            // Valor inverso del LED
    GPIOF->DATA = Led;   // Escribir valor en el registro de datos del PORTF, alternar LED
    Delay();
    Led = 0x04;            // Valor inverso del LED
     GPIOF->DATA = Led;   // Escribir valor en el registro de datos del PORTF, alternar LED
    Delay();
    Led = 0x08;            // Valor inverso del LED
     GPIOF->DATA = Led;   // Escribir valor en el registro de datos del PORTF, alternar LED
    Delay();
    Led = 0x0A;            // Valor inverso del LED
     GPIOF->DATA = Led;   // Escribir valor en el registro de datos del PORTF, alternar LED
    Delay();
   // }
  }
}
