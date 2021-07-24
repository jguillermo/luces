#INCLUDE "C:\Archivos de programa\PICC\Devices\16f877a.h"
#FUSES HS,NOWDT,NOLVP,PUT,NOPROTECT
#USE delay(clock=4000000)
#BYTE PORTC=0x07
#BYTE PORTD=0x08 

#BIT RD0=0x08.0//data
#BIT RD1=0x08.1//clock
#BIT RD2=0x08.2//reset

int useg1=50;
int aux,iaux,apbi,apbi2,intsb=0,auxfila,nufra;
int i,j,iselect=0;
int num=5,num2=0,posled2=1;
int portprende[7]={0x01,0x02,0x04,0x08,0x10,0x20,0x40};
int letras,nu1,nu2;
int tl2;


int const  vacio[7]={0x7F,0x7F,0x7F,0x7F,0x7F,0x7F,0x7F};  //  0
int const  A[5]={0x01,0x76,0x76,0x76,0x01};  //  1
int const  B[6]={0x00,0x00,0x36,0x36,0x36,0x49};  //  2
int const  C[6]={0x00,0x00,0x3E,0x3E,0x3E,0x3E};  //  3
int const  D[7]={0x3E,0x00,0x00,0x3E,0x3E,0x3E,0x41};  //4  
int const  E[7]={0x3E,0x00,0x00,0x36,0x36,0x36,0x3E};  // 5 
int const  apos[1]={0x7C};  //   6


int tamletra[13]={7,7,6,6,6,6,7,7,7,7,1,1,7};
   int frace[13]={1,1,2,2,3,3,4,4,5,5,6,6,0}; 
int posletra[13]={0,1,2,3,4,5,6,7,8,9,10,11,12};

void intercambialetras();
void reset();
void set01();
void letrero();
void recargadatos();
void llenafila(int nu,int letra, int ini, int fin);
void fila(int nu);

void main(void)
{
    int nh=0;
	set_tris_c(0x00);  // 1=ENTRADA, 0=SALIDA 
	set_tris_d(0x00); 
    PORTC=0;
	PORTD=1;
	reset();
	nu1=0;
	nu2=0;
	letras=1;
	recargadatos();
	while(TRUE)
    {	nh++;
		
						
						if (nh<=useg1)
	   	    				letrero();
     					else   
      	   					{nh=0;recargadatos();}
							
           			
     }      	
}



void llenafila(int nu,int letra, int ini, int fin)
{
			switch (letra) 
				{
			    case 0:	for(i=ini;i<=fin;i++){RD0=bit_test(vacio[i],nu) ;set01();}break;
    			case 1: for(i=ini;i<fin;i++){RD0=bit_test(A[i],nu) ;set01();}break;	
			   	case 2: for(i=ini;i<=fin;i++){RD0=bit_test(B[i],nu) ;set01();}break;	
				case 3: for(i=ini;i<=fin;i++){RD0=bit_test(C[i],nu) ;set01();}break;
    			case 4: for(i=ini;i<=fin;i++){RD0=bit_test(D[i],nu) ;set01();}break;
			   	case 5: for(i=ini;i<=fin;i++){RD0=bit_test(E[i],nu) ;set01();}break;
				case 6: for(i=ini;i<=fin;i++){RD0=bit_test(apos[i],nu) ;set01();}break;	
				 }
}

void fila(int nu)
{   
	llenafila(nu,frace[posletra[0]],nu1,tamletra[posletra[0]]);RD0=1; set01();
	for(j=1;j< letras;j++)
	{	
		llenafila(nu,frace[posletra[j]],1,tamletra[posletra[j]]);
		RD0=1; set01();
	}
	llenafila(nu,frace[posletra[letras]],1,nu2);
		
}

void intercambialetras(){
nu1=1;aux=posletra[0];
for(iaux=0;iaux<13;iaux++)
		{
			aux++;
			if (aux==13) aux=0;
			posletra[iaux]=aux;		      	
		}
}
void recargadatos()
{
nu1++;
if (nu1 == tamletra[posletra[0]])intercambialetras();

	tl2=tamletra[posletra[0]]-nu1+1;
	for(iaux=0;iaux<20;iaux++)
		{
			
			if (tl2>=30) {}		      	
		}
letras=0;
while (tl2<=30)
{letras++;
tl2=tl2+tamletra[posletra[letras]]+1;
}
iaux=tl2-30;
nu2=tamletra[posletra[letras]]-iaux;
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

void reset(void)
{
 	RD2=0;//data
 	delay_us(2);
 	RD2=1;//clock	
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
