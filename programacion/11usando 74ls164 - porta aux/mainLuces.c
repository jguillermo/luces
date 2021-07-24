#INCLUDE "C:\Archivos de programa\PICC\Devices\16f877a.h"
#FUSES HS,NOWDT,NOLVP,PUT,NOPROTECT
#USE delay(clock=20000000)
#BYTE PORTC=0x07 
#BYTE PORTB=0x06 
#BYTE PORTD=0x08 

#BIT RC0=0x07.0
#BIT RC1=0x07.1
#BIT RC2=0x07.2
#BIT RC3=0x07.3
#BIT RC4=0x07.4

#BIT RB0=0x06.0
#BIT RB1=0x06.1
#BIT RB2=0x06.2
#BIT RB3=0x06.3
#BIT RB4=0x06.4
#BIT RB5=0x06.5
#BIT RB6=0x06.6

#BIT RD0=0x08.0//data
#BIT RD1=0x08.1//clock
#BIT RD2=0x08.2//reset

int i,apaga=1,prende=0;
int letpos[16]={0,1,2,3,4,0,1,2,3,4,0,1,2,3,4,0};
int const lether[5][7]={
{0x00,0x00,0x00,0x00,0x00,0x00,0x00},  //  	vacio
{0x12,0x12,0x12,0x1E,0x12,0x12,0x12},  //  H
{0x0C,0x12,0x12,0x12,0x12,0x12,0x0C},  //  O
{0x1E,0x10,0x10,0x10,0x10,0x10,0x10},  //  L
{0x00,0x0E,0x11,0x04,0x00,0x0A,0x00},  //  
};

//void waitjg();
//void waitletra();
void waitjg(){delay_us(2);}//delay_us(2)
void waitletra(){delay_ms(100);}//delay_us(500)
long useg1=8;
//void set0();
//void set1();
void reset();
void set01();
void fila(int let,int nu);
void letrero();

void main(void)
{
    long nh=0;
	//long useg1=50;
	int aux,iaux;
	set_tris_b(0x00);  // PORTA_TRIS = 0b11000000; //1=ENTRADA, 0=SALIDA 
	set_tris_d(0x00); 
	set_tris_c(0x00);
    PORTB=0;
    PORTC=0;
	PORTD=1;
	reset();

	while(TRUE)
    {	
			nh++;	
	 	if (nh<=useg1)
	   	    letrero();
     	else   
      	   {nh=0;
	      	aux=letpos[0];
	      	for(iaux=0;iaux<16;iaux++)
	      		{ aux++;
	      	 	  if (aux==5)aux=0;
			      letpos[iaux]=aux;		      	
	      	    }      	    	 
      	   }
     }      	
	 			
}


/*  

*/

void fila(int nu){
   //  reset();
   for  (i=0;i<16;i++)
    {
     PORTC=lether[letpos[i]][nu];
	RD0=RC4;set01();	
	RD0=RC3;set01();
	RD0=RC2;set01();
	RD0=RC1;set01();
	RD0=RC0;set01();
				
		
    }
}

void set01(){
 
 waitjg();
 RD1=0;//clock
 waitjg();
 RD1=1;//clock
}
void letrero(){

     RB6=apaga;
     fila(0);
     RB0=prende;
     waitletra();
	   
	 RB0=apaga;
     fila(1);
     RB1=prende;
     waitletra();
	   
	 RB1=apaga;
     fila(2);
     RB2=prende;
     waitletra();
	   
	 RB2=apaga;
     fila(3);
     RB3=prende;
     waitletra();
	   
	 RB3=apaga;
     fila(4);
     RB4=prende;
     waitletra();
	   
	 RB4=apaga;
     fila(5);
     RB5=prende;
     waitletra();
	   
	 RB5=apaga;
     fila(6);
     RB6=prende;
     waitletra(); 
     
}
/*
void set0(void){
 RD0=0;//data
 waitjg();
 RD1=0;//clock
 waitjg();
 RD1=1;//clock
}
void set1(void){
 RD0=1;//data
 waitjg();
 RD1=0;//clock
 waitjg();
 RD1=1;//clock
}

*/
void reset(void){
 //for (irst=0;irst<20;irst++)set0();
 RD2=0;//data
 waitjg();
 RD2=1;//clock	
}



/*
	 RB0=0;
	 RB1=0;
	 RB2=0;
	 RB3=0;
	 RB4=0;
	 RB5=0;
	 RB6=0;
  RD0=1;//data
  RD1=1;//clock
  RD2=1;//reset

//	PORTA_TRIS = 0b11000000; //1=ENTRADA, 0=SALIDA 
//    PORTB_TRIS = 0b00000000; //1=ENTRADA, 0=SALIDA 


*/
