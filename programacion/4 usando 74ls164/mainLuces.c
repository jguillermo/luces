#INCLUDE "C:\Archivos de programa\PICC\Devices\16f877a.h"
#FUSES HS,NOWDT,NOLVP,PUT,NOPROTECT
#USE delay(clock=20000000)
#BYTE PORTB=0x06 
#BYTE PORTD=0x08 

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

int i,j,apaga=1,prende=0;
int letpos[3]={0,1,2};
int const lether[5][7][5]={
{{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},   //  vacio	
{{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,1,1,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0}},   //   H
{{0,1,1,0,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,0,0}},   //   O
{{1,1,1,1,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0}},   //   L
{{1,0,0,1,0},{1,0,0,1,0},{1,0,0,1,0},{1,1,1,1,0},{1,0,0,1,0},{1,0,0,1,0},{0,1,1,0,0}}   //   A 
};
void waitjg();
void waitletra();
void set0();
void set1();
void reset();
void fila(int let,int nu);
void letrero();

void main(void)
{
    long nh=0;
	long useg1=50;
	int aux;
	set_tris_b(0x00);  // PORTA_TRIS = 0b11000000; //1=ENTRADA, 0=SALIDA 
	set_tris_d(0x00); 
    PORTB=0;
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
	      	     if (aux==0)
	      	     	letpos[0]=1,letpos[1]=2,letpos[2]=3;
	      	     else if (aux==1)
	      	     	letpos[0]=2,letpos[1]=3,letpos[2]=4;
	      	     else if (aux==2)
	      	     	letpos[0]=3,letpos[1]=4,letpos[2]=0;
	             else if (aux==3)
	      	     	letpos[0]=4,letpos[1]=0,letpos[2]=1; 
	      	     else
	      	     	letpos[0]=0,letpos[1]=1,letpos[2]=2; 	 
      	   }
     }      	
	 			
}


/*  

*/

void fila(int nu){
   //  reset();
   for  (i=0;i<3;i++)
    {
     for (j=0;j<5;j++)
		{
			if (lether[letpos[i]][nu][j]==0)
			set0();
			else
			set1();
		}
    }
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
void reset(void){
 //for (irst=0;irst<20;irst++)set0();
 RD2=0;//data
 waitjg();
 RD2=1;//clock	
}
void waitjg(){delay_us(2);}//delay_us(2)
void waitletra(){delay_ms(1);}//delay_us(500)


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
