/************************************************************************/
/*  RS232F.C    Biblioteca de Comunicação serial assíncrona por         */
/*                software                       			*/
/*                                                                      */
/*  Autor: Eng. Fabrício de Lima Ribeiro				*/
/*                                                                      */
/*  Velocidade : 4800 Bps, 1 Start, 1 Stop, paridade ímpar              */
/*                                                                      */
/*  Rotinas utilizadas:                                                 */
/*                                                                      */
/*  void ini_serial (void) 	                                        */
/*  void tx_serial (char dado)                                    	*/
/*  char rx_serial (void)                                            	*/
/*                                                                      */
/*  Estas rotinas funcionam sem modificação para velocidades de 9600 e  */
/*  19200 Bps.                                                          */
/*                                                                      */
/************************************************************************/

// Definições de comunicação
/* 
   Para alterar a velocidade de comunicação, basta alterar o valor da
   constante baud_rate
*/
#ifndef baud_rate
//const long int baud_rate = 9600;
const long int baud_rate = 4800;
#endif

const int tempo_bit_dado = 1000000/baud_rate-10;
//const int tempo_bit_start = 1500000/baud_rate-10;

#bit pino_tx = 0x05.1	// pino de transmissão é o GP1
#bit pino_rx = 0x05.2	// pino de recepção é o GP2
#bit dir_tx  = 0x85.1	// direção do pino de tx
#bit dir_rx  = 0x85.2	// direção do pino de rx

void ini_serial (void)
{
   dir_tx = 0;   	// pino de tx como saída
   pino_tx = 1;   	// coloca o pino de tx em nível 1
   dir_rx = 1;   	// configura o pino de rx como entrada
}

void tx_serial (char dado)
{
	int conta, aux;
	char dado1;
	short parity;

	dado1=dado;
	aux=0;
	parity=0;
	conta = 8;

	while (conta)
	{
      		if (shift_right ( &dado1, 1, 0))
		   aux++;

		conta--;
	}

	if (aux%2)
		parity=1;

	pino_tx = 0;
	delay_us(tempo_bit_dado);
	conta = 8;

	while (conta)
	{

	     	if (shift_right ( &dado, 1, 0))
			pino_tx=1;
	      	else
			pino_tx=0;
      	
		delay_us ( tempo_bit_dado);
		conta--;
	}

	pino_tx=parity;
	delay_us(tempo_bit_dado);

	pino_tx = 1;
	delay_us(tempo_bit_dado);
}

char rx_serial (void)
{
	int conta,dado;
	conta = 8;
	dado = 0;
	while (pino_rx);
	delay_us(tempo_bit_dado+10);
	
	while (conta)
	{
		shift_right( &dado, 1, pino_rx);
		delay_us(tempo_bit_dado);
		conta--;
	}
	delay_us(tempo_bit_dado);
	
	delay_us(tempo_bit_dado);

	return dado;
}
