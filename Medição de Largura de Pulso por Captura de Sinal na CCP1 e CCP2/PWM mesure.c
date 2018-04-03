///////////////////////////////////////////////////////////////////////////////
/////                Programa para obter o tempo de um pulso              /////
/////                aplicado as portas CCP1 e CPP2 através               /////
/////                da sensibiização do rise e fall do pulso,            /////
/////                com a interrupção ocorrendo na fall.                 /////
/////                O tempo é contado a partir do rise, pelo             /////
/////                Timer 1, que é lido na fall.                         /////
/////                                                                     /////
///////////////////////////////////////////////////////////////////////////////

#include <16F877.h>
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)

#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <lcd.c>

long rise,fall,pulse_width;

#int_ccp2
void isr()
{
   rise = CCP_1;
   fall = CCP_2;
   pulse_width = fall - rise;
   printf(lcd_putc,"\fSample Time\n %lu us", pulse_width/5 );
}


void main()
{
   set_tris_b(0b00000000);
   set_tris_c(0b00000110);
      
   lcd_init();

   setup_ccp1(CCP_CAPTURE_RE);
   setup_ccp2(CCP_CAPTURE_FE);
   setup_timer_1(T1_INTERNAL);
   set_timer1(0);

   enable_interrupts(INT_CCP2);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      
   }
}
