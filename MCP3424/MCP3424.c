/////////////////////////////////////////////////////////////
////  Zilocchi Eletrônica                                ////
////                                                     ////
////  Programa para trabalhar com o PIC em linguagem  C  ////
////  Projeto: Eng. Fabrício de Lima Ribeiro             ////
////  05/01/2016                                         ////
/////////////////////////////////////////////////////////////

#include <16F876A.h>
#fuses HS,NOWDT,PROTECT,NOLVP
#use delay(clock=4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

#include <stdio.h>
#include <MCP342X.c>

int32 flo=0; 
float U;

void main() 
{

   //setup_spi(SPI_SS_DISABLED); 
    
   adc_init(); 
   printf("\f\ninicio"); 
   
   While(TRUE)
   {
      set_adc_channel_mcp(0);
      flo=read_adc_mcp();
      printf("\r\n 1: %ld",flo);//Exibir 
      delay_ms(1000);
      set_adc_channel_mcp(1); 
      flo=read_adc_mcp(); 
      printf("\r\n 2: %ld",flo);//Exibir 
      delay_ms(1000); 
      set_adc_channel_mcp(2); 
      flo=read_adc_mcp(); 
      printf("\r\n 3: %ld",flo);//Exibir 
      delay_ms(1000); 
      set_adc_channel_mcp(3); 
      flo=read_adc_mcp(); 
      printf("\r\n 4: %ld",flo);//Exibir 
      delay_ms(1000); 
      ///////////////////////
      set_adc_channel_mcp(0);
      //U=abs(read_adc_volts_mcp());
      U=read_adc_volts_mcp();
      printf("\r\n U1: %1.3f",U);
      delay_ms(1000);
      set_adc_channel_mcp(1);
      U=read_adc_volts_mcp();
      printf("\r\n U2: %1.3f",U);
      delay_ms(1000);
      set_adc_channel_mcp(2);
      U=read_adc_volts_mcp();
      printf("\r\n U3: %1.3f",U);
      delay_ms(1000);
      set_adc_channel_mcp(3);
      U=read_adc_volts_mcp();
      printf("\r\n U4: %1.3f",U);
      delay_ms(1000);      
   }
}


