#include <16F877a.h> 
#fuses HS,NOWDT,NOPROTECT,NOLVP 
#use delay(clock=4000000) 
#include <flex_lcd.c> 

signed char enc_states[] = {0,-1,1,0,0,0,0,0,0,0,0,0,0,0,0,0}; //1 pulsos por deslocamento
//signed char enc_states[] = {0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0}; //4 pulsos por deslocamento
int16 enc_position = 0; 
signed int16 enc_value = 0; 
int16 old_enc_value = 0; 

void encoder0Loop(void) 
{ 
      enc_position <<= 2;
      enc_position |= (input_b() & 0x03);
      enc_value += enc_states[(enc_position & 0x0F)];
      
      if(enc_value == old_enc_value) 
         return; 

      if(enc_value <= 0)
         enc_value = 0; 

      if(enc_value >= 400)
         enc_value = 400; 
      
      printf(lcd_putc,"\nEncoder= %03Ld",enc_value); 
      old_enc_value = enc_value; 
}

void main(void) 
{ 
   lcd_init(); 
   port_b_pullups(true); 
   setup_adc_ports(NO_ANALOGS); 

   printf(lcd_putc,"\fRotary Encoder"); 

   while (true) 
   { 
      encoder0Loop(); 
   }
}
