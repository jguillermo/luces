#INCLUDE "C:\Archivos de programa\PICC\Devices\16f877a.h"
#FUSES HS,NOWDT,NOLVP,PUT,NOPROTECT
#USE delay(clock=4000000)
#BYTE PORTB=0x06 
#BYTE PORTD=0x08
#BIT RB0=0x06.0
#BIT RB1=0x06.1
#BIT RB2=0x06.2
#BIT RB3=0x06.3
#BIT RB4=0x06.4
#BIT RB5=0x06.5
#BIT RB6=0x06.6

int apaga=0,prende=1;
void waitletra(){delay_ms(1000);}//delay_us(500)

void fila(){delay_ms(1);}//delay_us(500)

void letrero(){

     RB6=apaga;
     fila();
     RB0=prende;
     waitletra();
	   
	 RB0=apaga;
     fila();
     RB1=prende;
     waitletra();
	   
	 RB1=apaga;
     fila();
     RB2=prende;
     waitletra();
	   
	 RB2=apaga;
     fila();
     RB3=prende;
     waitletra();
	   
	 RB3=apaga;
     fila();
     RB4=prende;
     waitletra();
	   
	 RB4=apaga;
     fila();
     RB5=prende;
     waitletra();
	   
	 RB5=apaga;
     fila();
     RB6=prende;
     waitletra(); 
     
}


void main(void)
{
set_tris_b(0x00); 
set_tris_d(0x00); 
    PORTB=0;
   PORTD=0;
	while(TRUE)
    {	
	   	    //letrero();
PORTD=0x01;
 waitletra();
PORTD=PORTD * 2;
 waitletra();
PORTD=PORTD * 2;
 waitletra();
PORTD=PORTD * 2;
 waitletra();
PORTD=PORTD * 2;
 waitletra();
PORTD=PORTD * 2;
 waitletra();
PORTD=PORTD * 2;
 waitletra();
PORTD=PORTD * 2;
 waitletra();
    	
     }      	
	 			
}


