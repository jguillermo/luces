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
#BIT RC5=0x07.5
#BIT RC6=0x07.6

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

int useg1=8,useg2=20;
int aux,iaux,auxportb,apbi,intsb=0;
int i,apaga=0,prende=1;
int num=5,num2=0,posled2=1;
int letpos[6]={0,1,2,3,4,5};
int const lether[13][7]={
{0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F},  //  	vacio
{0x0E,0x0E,0x0E,0x0E,0x0A,0x04,0x0E},  //  M
{0x0E,0x0E,0x0E,0x00,0x0E,0x0E,0x11},  //  A
{0x0E,0x0E,0x0C,0x0A,0x06,0x0E,0x0E},  //  N
{0x11,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E},  //  U
{0x0E,0x0E,0x0E,0x00,0x0E,0x0E,0x11},  //  A
{0x00,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F},  //  L
{0x00,0x1B,0x1B,0x1B,0x1B,0x1B,0x00},  //  I
{0x01,0x16,0x16,0x16,0x16,0x16,0x01},  //  D
{0x0E,0x0E,0x0E,0x00,0x0E,0x0E,0x11},  //  A
{0x01,0x16,0x16,0x16,0x16,0x16,0x01},  //  D 
{0x00,0x0F,0x0F,0x03,0x0F,0x0F,0x00},  //  E
{0x01,0x1E,0x1E,0x11,0x0F,0x0F,0x10},  //  S
};
void waitletra(){delay_ms(1);}//delay_us(500)
void reset();
void set01();
void fila(int nu);
void letrero();
void letrero2();
void letrero3();
void pausaletrero();
void intercambianumletra();
void main(void)
{
    int nh=0;
   int cmde=0,csc=0;
	//long useg1=50;
	set_tris_b(0x00);  // PORTA_TRIS = 0b11000000; //1=ENTRADA, 0=SALIDA 
	set_tris_d(0x00); 
	set_tris_c(0x00);
    PORTB=0;
    PORTC=0;
	PORTD=1;
	reset();

	while(TRUE)
    {	nh++;
		switch (cmde) 
				{
			    case 0:
						
						if (nh<=useg1)
	   	    				letrero();
     					else   
      	   					{nh=0;num2++;
						     if (num2>=6){intercambianumletra();num2=0;}
						     num=5-num2;csc++;
							 if (csc>=80) {cmde=1;csc=0;nh=0;pausaletrero();}
							}
						
           				break;


    			case 1:
						if (nh<=useg2)
	   	    				letrero2();
     					else   
      	   					{nh=0;
							 if (intsb==0)
							 	{posled2++;}
							 else
								{posled2=posled2-1;}
							 if (posled2>=8)
									{intsb=1;}
						     if (intsb==1)
								{if (posled2==0 )
									{intsb=0;cmde=0;pausaletrero();}
								}	
							}
						break;

				
				 }

     }      	
	 			
}


/*  

*/

void fila(int nu){
   //  reset();
  PORTC=lether[letpos[0]][nu];
if (num>=5){	RD0=RC4;set01();   }
if (num>=4){	RD0=RC3;set01();   }
if (num>=3){	RD0=RC2;set01();   }
if (num>=2){	RD0=RC1;set01();   }
if (num>=1){	RD0=RC0;set01();   }
RD0=1;set01();
    for  (i=1;i<5;i++)
    {
    PORTC=lether[letpos[i]][nu];
	RD0=RC4;set01();	
	RD0=RC3;set01();
	RD0=RC2;set01();
	RD0=RC1;set01();
	RD0=RC0;set01();
	RD0=1;set01();				
    }
 PORTC=lether[letpos[5]][nu];
if (num2>=1){	RD0=RC4;set01();   }
if (num2>=2){	RD0=RC3;set01();   }
if (num2>=3){	RD0=RC2;set01();   }
if (num2>=4){	RD0=RC1;set01();   }
if (num2>=5){	RD0=RC0;set01();   }

}
void intercambianumletra(){

			aux=letpos[0];
	      	for(iaux=0;iaux<6;iaux++)
	      		{ aux++;
	      	 	  if (aux==13)aux=0;
			      letpos[iaux]=aux;		      	
	      	    }
 }
void set01(){
 
 delay_us(2);
 RD1=0;//clock
 delay_us(2);
 RD1=1;//clock
}
void letrero(){
 /*
PORTB=0X00;
fila(0);
PORTB=0X01;
delay_ms(1);

for(apbi=1;apbi<7;apbi++)
	{ 

auxportb=PORTB;
PORTB=0X00;
fila(apbi);
PORTB=auxportb*2;
delay_ms(1);	 		      	
    }

  
 
auxportb,apbi; */
	 RB6=apaga;
     fila(0);
     RB0=prende;
     delay_ms(1);

	 RB0=apaga;
     fila(1);
     RB1=prende;
     delay_ms(1);

	 RB1=apaga;
   fila(2);
     RB2=prende;
     delay_ms(1);
	   
	 RB2=apaga;
   fila(3);
     RB3=prende;
     delay_ms(1);
	   
	 RB3=apaga;
  fila(4);
     RB4=prende;
     delay_ms(1);
	   
	 RB4=apaga;
   fila(5);
     RB5=prende;
     delay_ms(1);
	   
	 RB5=apaga;
   fila(6);
     RB6=prende;
     delay_ms(1);

    
}

void letrero2(){
 /*
PORTB=0X00;
fila(0);
PORTB=0X01;
delay_ms(1);

for(apbi=1;apbi<7;apbi++)
	{ 

auxportb=PORTB;
PORTB=0X00;
fila(apbi);
PORTB=auxportb*2;
delay_ms(1);	 		      	
    }

  
 
auxportb,apbi; posled2*/
	 PORTB=0X00;
	 fila(0);
     PORTC=0b0000001;
     PORTB=PORTC<<posled2;
	 delay_ms(1);

	  PORTB=0X00;
	  fila(1);
     PORTC=0b0000010;
     PORTB=PORTC<<posled2;
	 delay_ms(1);

	  PORTB=0X00;
   fila(2);
     PORTC=0b0000100;
     PORTB=PORTC<<posled2;
	 delay_ms(1);
	   
	  PORTB=0X00;
   fila(3);
     PORTC=0b0001000;
     PORTB=PORTC<<posled2;
	 delay_ms(1);
	   
	 PORTB=0X00;
  fila(4);
     PORTC=0b00010000;
     PORTB=PORTC<<posled2;
	 delay_ms(1);
	   
	  PORTB=0X00;
   fila(5);
     PORTC=0b00100000;
     PORTB=PORTC<<posled2;
	 delay_ms(1);
	   
	 PORTB=0X00;
   fila(6);
     PORTC=0b01000000;
     PORTB=PORTC<<posled2;
	 delay_ms(1);

    
}

void letrero3(){
 /*
PORTB=0X00;
fila(0);
PORTB=0X01;
delay_ms(1);

for(apbi=1;apbi<7;apbi++)
	{ 

auxportb=PORTB;
PORTB=0X00;
fila(apbi);
PORTB=auxportb*2;
delay_ms(1);	 		      	
    }

  
 
auxportb,apbi; posled2*/
	 PORTB=0X00;
	 fila(0);
     PORTC=0b0000001;
     PORTB=PORTC>>posled2;
	 delay_ms(1);

	  PORTB=0X00;
	  fila(1);
     PORTC=0b0000010;
     PORTB=PORTC>>posled2;
	 delay_ms(1);

	  PORTB=0X00;
   fila(2);
     PORTC=0b0000100;
     PORTB=PORTC>>posled2;
	 delay_ms(1);
	   
	  PORTB=0X00;
   fila(3);
     PORTC=0b0001000;
     PORTB=PORTC>>posled2;
	 delay_ms(1);
	   
	 PORTB=0X00;
  fila(4);
     PORTC=0b00010000;
     PORTB=PORTC>>posled2;
	 delay_ms(1);
	   
	  PORTB=0X00;
   fila(5);
     PORTC=0b00100000;
     PORTB=PORTC>>posled2;
	 delay_ms(1);
	   
	 PORTB=0X00;
   fila(6);
     PORTC=0b01000000;
     PORTB=PORTC>>posled2;
	 delay_ms(1);

    
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
 delay_us(2);
 RD2=1;//clock	
}

void pausaletrero(void){
for(apbi=1;apbi<200;apbi++)
	{ 
letrero();	 		      	
    }

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
