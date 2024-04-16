#ifndef UART_H_
#define UART_H_
#include "../lib/Error/Error.h"
#include "../lib/StdTypes.h"

#define UART_SYSTEM_FREQ 16000000UL

/*UART Peripherals*/
#define UART_1 0x00000000UL
#define UART_2 0x00000001UL
#define UART_6 0x00000002UL

/*Byte Length*/
#define UART_EIGHT_BIT 0x00000000UL
#define UART_NINE_BIT  0x00001000UL

/*Parity State*/
#define UART_ENABLE_PARITY  0x00000400UL
#define UART_DISABLE_PARITY 0x00000000UL

/*Parity Type*/
#define UART_ODD_PARITY  0x00000200UL
#define UART_EVEN_PARITY 0x00000000UL

/*Stop Bits*/
#define UART_HALF_BIT    0x00001000UL
#define UART_ONE_BIT     0x00000000UL
#define UART_ONEHALF_BIT 0x00003000UL
#define UART_TWO_BITS    0x00002000UL

/*Over Sampling*/
#define UART_OVERSAMPLING_16 0x00000000UL
#define UART_OVERSAMPLING_8  0x00008000UL

/*Sampling*/
#define UART_THREE_BIT_SAMPLING 0x00000000UL
#define UART_ONE_BIT_SAMPLING   0x00000800UL

typedef void (*CB_t) (void);

typedef struct 
{
    
    u8 UART_ID;

    u16 Baud_Rate;

    u8 Byte_Length;

    u8 Parity_Enable;

    u8 Parity_Type;

    u8 Stop_Bits;

    u8 Over_Sampling;

    u8 Sampling;

}UART_Confg_t;


/*APIs*/

Error_t UART_Init(UART_Confg_t *UART_CONFIG);

Error_t UART_TX_Byte(u8 UART_Peri, u8 Byte);

Error_t UART_RX_Byte(u8 UART_Peri, u8 *Byte);

Error_t UART_TX_Buffer_Async_ZC(u8 UART_ID, u8 *Buffer, u32 Length, CB_t CB);

Error_t UART_RX_Buffer_Async_ZC(u8 UART_ID, u8 *Buffer, u32 Length, CB_t CB);

/*Extra*/
u8 UART_IS_DR_Empty(void);

u8 UART_IS_TX_Complete(void);

/*Get States*/

#endif /*UART_H_*/