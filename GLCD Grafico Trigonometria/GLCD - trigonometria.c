//============================================================================//
//                       PROGRAMA PARA PLOTAR VALORES                         //
//                            EM UM LCD GRÁFICO                               //
// ESTAGIÁRIO: Tiago Fernandes da Silva Costa                                 //
// ORIENTADOR DE ESTÁGIO: Eng. Fabrício de Lima Ribeiro                       //
//                               08/11/2013                                   //
//============================================================================//

#include <18F4550.h>
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN,NOPBADEN
#use delay(clock=48000000)

#include <GLCD_T.c>
#include <MATH.h>

void main ()
{
   glcd_init(ON);

   char n;
   int16 i;
   float x, y;
   
   glcd_line(0,31,127,31,ON);
   glcd_line(63,0,63,63,ON);
   
   n=1;
   
   for(i=0; i<(360*n); i++)
   {
      x=(pi/180)*i;
      y=31.5+32*sin(-x);
      x=(0.355*i)/n;
      glcd_pixel(x,y,ON);
   }

   while (TRUE)
   {
      
   }
}      


