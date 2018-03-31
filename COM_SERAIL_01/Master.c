#include <16f876A.h>
#use delay(clock=4000000)
#fuses HS,NOWDT,PROTECT,NOLVP
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, stream = COM1)
#include <LCD_PORTB.C>

void main()
{
   char str[3];
   int16 x = 7376;
   
   set_tris_b(0b00000000);
   set_tris_c(0b01000011);
   
   lcd_init();
   
   while (true)
   {
      if(input(PIN_C0) == 0)
      {
         delay_ms(10);
         do{
         }while (input(PIN_C0) == 0);
         
         printf(lcd_putc,"\f7376");
         
         x = 7376;
         fprintf(COM1, "%04lu", x);
      }
      if(input(PIN_C1) == 0)
      {
         delay_ms(10);
         do{
         }while (input(PIN_C1) == 0);
         
         printf(lcd_putc,"\f7673");
         
         x = 7673;
         fprintf(COM1, "%04lu", x);
      }      
   }
}
