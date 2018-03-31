#include <16f628A.h>
#use delay(clock=4000000)
#fuses HS,NOWDT,PROTECT,NOLVP
#use rs232(baud=9600, xmit=PIN_B2,rcv=PIN_B1)
#include <stdlib.h>

#byte portb = 0x06

#INT_RDA
void SerialDataReceive() 
{  
   char i, dado[3];
   int32 valor;
   
   for(i=0; i<4; i++)
   {
      do{
         dado[i]=getc();
      }while(kbhit());
   }
       
   valor = atoi32(dado);      
         
   if(valor == 7376)
      output_high(pin_B6);
      
   if(valor == 7673)
      output_low(pin_B6);      
}

void main()
{
   char a=0;
   
   char dado[3];
   int32 valor;
   
   set_tris_b(0b00000010);
   portb = 0x00;
   
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
      
   while (true)
   {
      if(a == 0)
      {
         output_high(pin_B5);
         delay_ms(500);
         a=1;
      }
      else
      {
         output_low(pin_B5);
         delay_ms(500);
         a=0;
      }      
   }
}
       
