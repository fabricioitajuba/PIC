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

void lcd_symbols1()  
{ 
   lcd_send_byte(0x00, 0x40);
   lcd_send_byte(0x01, 0b00000000);
   lcd_send_byte(0x01, 0b00001010);
   lcd_send_byte(0x01, 0b00001010);
   lcd_send_byte(0x01, 0b00000000);
   lcd_send_byte(0x01, 0b00010001);
   lcd_send_byte(0x01, 0b00001110);
   lcd_send_byte(0x01, 0b00000000);
} 

void lcd_symbols2()  
{ 
   lcd_send_byte(0x01, 0x40);
   lcd_send_byte(0x01, 0b00000000);
   lcd_send_byte(0x01, 0b00001010);
   lcd_send_byte(0x01, 0b00001010);
   lcd_send_byte(0x01, 0b00000000);
   lcd_send_byte(0x01, 0b00001110);
   lcd_send_byte(0x01, 0b00010001);
   lcd_send_byte(0x01, 0b00000000);
}

void lcd_symbols3()  
{ 
   lcd_send_byte(0x02, 0x40);
   lcd_send_byte(0x01, 0b00000000);
   lcd_send_byte(0x01, 0b00001010);
   lcd_send_byte(0x01, 0b00001010);
   lcd_send_byte(0x01, 0b00000000);
   lcd_send_byte(0x01, 0b00001110);
   lcd_send_byte(0x01, 0b00010001);
   lcd_send_byte(0x01, 0b00000000);
}

void main()
{
   set_tris_b(0b00000000);
   
   lcd_init();
   lcd_symbols1();
   lcd_symbols2();
   //lcd_symbols3();

   //lcd_send_byte(0x00, 0x83); 
   //lcd_putc(0);
   //lcd_putc(1);
   //lcd_putc(2);
   
   while(TRUE)
   {
      lcd_send_byte(0x00, 0x80); 
      lcd_putc(0);
      delay_ms(1000);
      lcd_send_byte(0x00, 0x80); 
      lcd_putc(1);
      delay_ms(1000);
   }
}


