#include <16f628A.h>
#use delay(clock=4000000)
#fuses HS,NOWDT,PROTECT,NOLVP
#use rs232(baud=9600, xmit=PIN_B2,rcv=PIN_B1)
#include <regs_16f87x.h>

#byte portb = 0x06

#INT_RDA 
void SerialDataReceive() 
{ 
   char dado;
   
   dado = getc();
         
   if(dado == '1')
      output_high(pin_B6);
            
   if(dado == '2')
      output_high(pin_B7);  
} 

void main()
{
   char a=0;
   
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
       
