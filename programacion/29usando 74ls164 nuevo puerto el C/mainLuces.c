#INCLUDE "C:\Archivos de programa\PICC\Devices\16f877a.h"
#FUSES HS,NOWDT,NOLVP,PUT,NOPROTECT
#USE delay(clock=4000000)
#BYTE PORTC=0x07
#BYTE PORTD=0x08 

#BIT RD0=0x08.0//data
#BIT RD1=0x08.1//clock
#BIT RD2=0x08.2//reset

int useg1=5,useg2=20;
int aux,iaux,apbi,apbi2,intsb=0,auxfila;
int i,iselect=0;
int num=5,num2=0,posled2=1;
int letpos[6]={0,1,2,3,4,5},portprende[7]={0x01,0x02,0x04,0x08,0x10,0x20,0x40};


int frace[34]={1,9,11,15,0,20,5,0,22,5,14,4,5,0,12,15,19,0,13,5,10,15,18,5,19,0,18,5,7,1,12,15,19,0};
long nufra=34,tamletra=204;



int const lether[28][7]={
{0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F},  //  	vacio
{0x0E,0x0E,0x0E,0x00,0x0E,0x0E,0x11},  //  A
{0x01,0x0E,0x0E,0x01,0x0E,0x0E,0x01},  //  B
{0x10,0x0F,0x0F,0x0F,0x0F,0x0F,0x10},  //  C
{0x01,0x16,0x16,0x16,0x16,0x16,0x01},  //  D
{0x00,0x0F,0x0F,0x01,0x0F,0x0F,0x00},  //  E
{0x0F,0x0F,0x0F,0x03,0x0F,0x0F,0x00},  //  F
{0x11,0x0E,0x0E,0x0C,0x0F,0x0E,0x11},  //  G
{0x0E,0x0E,0x0E,0x00,0x0E,0x0E,0x0E},  //  H
{0x00,0x1B,0x1B,0x1B,0x1B,0x1B,0x00},  //  I
{0x13,0x0B,0x1B,0x1B,0x1B,0x1B,0x00},  //  J
{0x0E,0x0D,0x0B,0x07,0x0B,0x0D,0x0E},  //  K
{0x00,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F},  //  L
{0x0E,0x0E,0x0E,0x0E,0x0A,0x04,0x0E},  //  M
{0x0E,0x0E,0x0C,0x0A,0x06,0x0E,0x0E},  //  N
{0x11,0x0E,0x0E,0x0E,0x0E,0x0E,0x11},  //  O
{0x0F,0x0F,0x0F,0x01,0x0E,0x0E,0x01},  //  P
{0x12,0x0D,0x0D,0x0D,0x0D,0x0D,0x13},  //  Q
{0x0E,0x0D,0x0B,0x01,0x0E,0x0E,0x01},  //  R
{0x11,0x0E,0x1E,0x11,0x0F,0x0E,0x11},  //  S
{0x1B,0x1B,0x1B,0x1B,0x1B,0x1B,0x00},  //  T
{0x11,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E},  //  U
{0x1B,0x1B,0x15,0x15,0x0E,0x0E,0x0E},  //  V
{0x15,0x15,0x0A,0x0A,0x0E,0x0F,0x0E},  //  W
{0x0E,0x0E,0x15,0x1B,0x15,0x0E,0x0E},  //  X
{0x1B,0x1B,0x1B,0x1B,0x15,0x0E,0x0E},  //  Y
{0x00,0x0F,0x17,0x1B,0x1D,0x1E,0x00},  //  Z
{0x0E,0x0E,0x0C,0x0A,0x06,0x0F,0x08},  //  Ñ
/*
{0x12,0x0C,0x0C,0x0C,0x12,0x1F,0x1F},  //  a
{0x09,0x06,0x06,0x06,0x09,0x0F,0x0F},  //  b
{0x10,0x0F,0x0F,0x0F,0x10,0x1F,0x1F},  //  c
{0x12,0x0C,0x0C,0x0C,0x12,0x1E,0x1E},  //  d
{0x10,0x0F,0x00,0x0E,0x11,0x1F,0x1F},  //  e
{0x17,0x17,0x17,0x03,0x16,0x16,0x19},  //  f
{0x11,0x1E,0x10,0x0E,0x11,0x1F,0x1F},  //  g
{0x0E,0x0E,0x0E,0x06,0x09,0x0F,0x0F},  //  h
*/
         };

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
	int cmde=0;
	long csc=0;
	set_tris_c(0x00);  // 1=ENTRADA, 0=SALIDA 
	set_tris_d(0x00); 
    PORTC=0;
	PORTD=1;
	reset();
	pausaletrero();
	pausaletrero();
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
							 if (csc>=tamletra) 
								{
									csc=0;nh=0;
									iselect++;
									cmde=iselect;
									if (iselect==2) iselect=0;
									pausaletrero();
								}
							}
						
           				break;


    			case 1:
						if (nh<=useg2) letrero2();
     					else   
      	   					{nh=0;
							 if (intsb==0) posled2++;else posled2--;
							 if (posled2>=8) intsb=1;
						     if (intsb==1)
								{if (posled2==0 )
									{intsb=0;cmde=0;pausaletrero();}
								}	
							}
						break;	
			   	case 2:
						if (nh<=useg2) letrero3();
     					else   
      	   					{nh=0;
							 if (intsb==0) posled2++;else posled2--;
							 if (posled2>=8) intsb=1;
						     if (intsb==1)
								{if (posled2==0 )
									{intsb=0;cmde=0;pausaletrero();}
								}	
							}
						break;		
				 }
     }      	
}
void fila(int nu)
{   
	auxfila=lether[frace[letpos[0]]][nu];
	if (num>=5){	RD0=bit_test(auxfila,4) ;set01();    }
	if (num>=4){	RD0=bit_test(auxfila,3) ;set01();    }
	if (num>=3){	RD0=bit_test(auxfila,2) ;set01();    }
	if (num>=2){	RD0=bit_test(auxfila,1) ;set01();    }
	if (num>=1){	RD0=bit_test(auxfila,0) ;set01();    }
	RD0=1;set01();
    for  (i=1;i<5;i++)
    	{
    		auxfila=lether[frace[letpos[i]]][nu];
			RD0=bit_test(auxfila,4) ;set01(); 	
			RD0=bit_test(auxfila,3) ;set01(); 
			RD0=bit_test(auxfila,2) ;set01(); 
			RD0=bit_test(auxfila,1) ;set01(); 
			RD0=bit_test(auxfila,0) ;set01(); 
			RD0=1;set01();				
   		 }
	auxfila=lether[frace[letpos[5]]][nu];
	if (num2>=1){	RD0=bit_test(auxfila,4) ;set01();   }
	if (num2>=2){	RD0=bit_test(auxfila,3) ;set01();   }
	if (num2>=3){	RD0=bit_test(auxfila,2) ;set01();   }
	if (num2>=4){	RD0=bit_test(auxfila,1) ;set01();   }
	if (num2>=5){	RD0=bit_test(auxfila,0) ;set01();   }
}
void intercambianumletra()
{
	aux=letpos[0];
	for(iaux=0;iaux<6;iaux++)
		{
			aux++;
			if (aux==nufra) aux=0;
			letpos[iaux]=aux;		      	
		}
}
void set01()
{
 	delay_us(2);
 	RD1=0;//clock
 	delay_us(2);
 	RD1=1;//clock
}
void letrero()
{
	for(apbi=0;apbi<7;apbi++)
		{ 
			PORTC=0X00;
			fila(apbi);
			PORTC=portprende[apbi];
			delay_ms(1);	 		      	
    	}
}

void letrero2()
{
	for(apbi=0;apbi<7;apbi++)
		{ 
			PORTC=0X00;
			fila(apbi);
			PORTC=portprende[apbi]<<posled2;	
			delay_ms(1);	 		      	
    	}
}
void letrero3()
{
	for(apbi=0;apbi<7;apbi++)
		{ 
			PORTC=0X00;
			fila(apbi);
			PORTC=portprende[apbi]>>posled2;	
			delay_ms(1);	 		      	
    	}
}
void reset(void)
{
 	RD2=0;//data
 	delay_us(2);
 	RD2=1;//clock	
}

void pausaletrero(void)
{
	for(apbi2=1;apbi2<100;apbi2++) 
			letrero();
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
