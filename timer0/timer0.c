/////////////////////////////////////////////////////////////
////  Zilocchi Eletrônica                                ////
////                                                     ////
////  Programa para trabalhar com o PIC em linguagem  C  ////
////  Projeto: Eng. Fabrício de Lima Ribeiro             ////
////  11/06/2014                                         ////
/////////////////////////////////////////////////////////////

#include <16F876.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=4194304)

#include <LCD_PORTB.C>

unsigned int16 C=0;

#int_timer0
void trata_t0 ()
{     
   static int conta;
   conta++;
   if (conta == 16)
   {
      conta=0;      
      C++;
      lcd_send_byte(0x00, 0xC0);
      printf(lcd_putc,"%Lu",C);
      set_timer0(0);
   } 
}

void main()
{
   set_tris_b(0b00000000);
   set_tris_c(0b11111111);
   
   lcd_init();
 
   printf(lcd_putc,"\fContagem:");
   lcd_send_byte(0x00, 0xC0);
   printf(lcd_putc,"%Lu",C);
   
   setup_timer_0(T0_INTERNAL | T0_DIV_256);
 
   enable_interrupts(global);
   enable_interrupts(int_timer0);

   set_timer0(0);
   
   while(TRUE)
   {

   }
}


