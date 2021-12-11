#include "./UART_driver.h"

static void(*TX_Ptr)(void) = NULL_PTR ; 
static void(*RX_Ptr)(void) = NULL_PTR ; 
static u8* str_send_temp ;   
static u8* str_recieve_temp ;
void UART_init(u16 baud_rate , u32 FOSC)
{
	//CLR_BIT(UCSRC,URSEL);
	//u16 baud_value = (u16) ( (FOSC / (16*baud_rate) ) - 1) ;
	//UBRRH = (u8)(baud_value>>8);
	UBRRL =0X33; 
    // configuration of control registers   
	//SET_BIT(UCSRC,URSEL);
	SET_BIT(UCSRB,RXCIE);     // enable RX interrupt
	CLR_BIT(UCSRC,USBS);      // one stop bit
	CLR_BIT(UCSRC,UMSEL);     // asynchronous mode 
	//character size 8 bit
	CLR_BIT(UCSRB,UCSZ2);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
	// no parity mode
	CLR_BIT(UCSRB,UPM0);
	CLR_BIT(UCSRB,UPM1);
	//Enable Protocol
	
	SET_BIT(UCSRB,RXEN);      // enable RX pin
	SET_BIT(UCSRB,TXEN);      // enable TX pin
	
}
void UART_Send_Byte(u8 value)
{
	UDR = value ;
}
void UART_send_string(u8 *sentence)
{
	UART_Enable_TXINT();
	UART_Send_Byte(sentence[0]);
	str_send_temp = sentence ;
	TX_SetCallBack(TX_Func);
}
void TX_Func(void)
{
    static u16 i = 1 ;
	if(str_send_temp[i] != '\0')
	{
		UART_Send_Byte(str_send_temp[i]);
		i++;
	}	
	else
	{
		 i = 1 ;
		 str_send_temp = NULL_PTR ; 
		 UART_Disable_TXINT();
	}
}

char UART_Recieve_Byte(void)
{
	return UDR ;
}
void UART_recieve_string(u8 *recieved_sentence)
{
	str_recieve_temp = recieved_sentence ;
	UART_Enable_RXINT();
	RX_SetCallBack(RX_Func);
}
void RX_Func(void)
{
	static u16 i = 0 ;
	str_recieve_temp[i] = UART_Recieve_Byte();
	if(str_recieve_temp[i] == '\0')
	{
		UART_Disable_RXINT();
		i = 0 ;
	}
	else
	{
		i++ ;
	}	
}
/**********************         interrupt     ******************/
void UART_Enable_RXINT(void)
{
   SET_BIT(UCSRB,RXCIE);     // enable RX interrupt	
}
void UART_Disable_RXINT(void)
{
	CLR_BIT(UCSRB,RXCIE);     // disable RX interrupt
}
void UART_Enable_TXINT(void)
{
	SET_BIT(UCSRB,TXCIE);     // enable TX interrupt
}
void UART_Disable_TXINT(void)
{
	CLR_BIT(UCSRB,TXCIE);     // disable TX interrupt
}

void TX_SetCallBack(void(*LocalPtr)(void))
{
	TX_Ptr = LocalPtr ;	
}
ISR(TXC_vect)
{
	if(TX_Ptr!= NULL_PTR)
	{
		TX_Ptr();
	}
}
void RX_SetCallBack(void(*LocalPtr)(void))
{
	RX_Ptr = LocalPtr ;
}
ISR(RXC_vect)
{
	if(RX_Ptr!= NULL_PTR)
	{
		RX_Ptr();
	}
}
