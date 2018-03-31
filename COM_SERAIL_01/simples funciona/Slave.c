#include <16f628A.h>
#use delay(clock=4000000)
#fuses HS,NOWDT,PROTECT,NOLVP
#use rs232(baud=9600, xmit=PIN_B2,rcv=PIN_B1)
#include <regs_16f87x.h>

#byte portb = 0x06

void main()
{
   char dado;
   
   set_tris_b(0b00000010);
   portb = 0x00;

   while (true)
   {
      if (kbhit())
      {
         dado = getc();
         
         if(dado == '1')
            output_high(pin_B6);
            
         if(dado == '2')
            output_high(pin_B7);                        
      }
   }
}
       
