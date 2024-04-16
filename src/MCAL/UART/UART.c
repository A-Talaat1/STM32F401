#include "UART.h"

#define UART_NUMBER_OF_PERIPHERALS 0x00000003UL

/*UART Peripherals Base Address */
#define UART_ONE_BASE_ADDRESS 0x40011000UL
#define UART_TWO_BASE_ADDRESS 0x40004400UL
#define UART_SIX_BASE_ADDRESS 0x40011400UL

/*UART Enable*/
#define UART_PERI_ENABLE 0x00002000UL
#define UART_TX_ENABLE   0x00000008UL
#define UART_RX_ENABLE   0x00000004UL

/*Masks*/
#define UART_GET_TXE_MASK  0x00000080
#define UART_GET_TC_MASK   0x00000040
#define UART_GET_RXNE_MASK 0x00000020

typedef struct
{

    u32 SR;
    u32 DR;
    u32 BRR;
    u32 CR1;
    u32 CR2;
    u32 CR3;
    u32 GTPR;

}UART_Registers_t;


static volatile UART_Registers_t * const UART [3] = { (volatile UART_Registers_t * const )UART_ONE_BASE_ADDRESS,
                                                      (volatile UART_Registers_t * const )UART_TWO_BASE_ADDRESS,
                                                      (volatile UART_Registers_t * const )UART_SIX_BASE_ADDRESS 
                                                    };


/*Static APIs*/
static u32 Calc_Baud_Rate(u16 Baud_Rate, u8 Over_Sampling);
static u32 Round_Float(float Float_Number);


Error_t UART_Init(UART_Confg_t *UART_CONFIG)
{
    Error_t Error = ERROR_Ok;
   
    u32 Temp_BRR = UART[UART_CONFIG->UART_ID]->BRR;
    u32 Temp_CR1 = UART[UART_CONFIG->UART_ID]->CR1;
    u32 Temp_CR2 = UART[UART_CONFIG->UART_ID]->CR2;
    u32 Temp_CR3 = UART[UART_CONFIG->UART_ID]->CR3;

    Temp_BRR |= Calc_Baud_Rate(UART_CONFIG->Baud_Rate, UART_CONFIG->Over_Sampling);

    Temp_CR1 |= UART_PERI_ENABLE;
    Temp_CR1 |= UART_TX_ENABLE;
    Temp_CR1 |= UART_RX_ENABLE;
    Temp_CR1 |= UART_CONFIG->Byte_Length;
    Temp_CR1 |= UART_CONFIG->Parity_Enable;
    Temp_CR1 |= UART_CONFIG->Parity_Type;
    Temp_CR1 |= UART_CONFIG->Over_Sampling;

    Temp_CR2 |= UART_CONFIG->Stop_Bits;

    Temp_CR3 |= UART_CONFIG->Sampling;

    UART[UART_CONFIG->UART_ID]->BRR = Temp_BRR;
    UART[UART_CONFIG->UART_ID]->CR1 = Temp_CR1;
    UART[UART_CONFIG->UART_ID]->CR2 = Temp_CR2;
    UART[UART_CONFIG->UART_ID]->CR3 = Temp_CR3;

    return Error;
}

Error_t UART_TX_Byte(u8 UART_Peri, u8 Byte)
{
    Error_t Error = ERROR_Ok;

    u8 TXE = UART[UART_Peri]->SR & UART_GET_TXE_MASK;
    
    if (TXE)
    {
        UART[UART_Peri]->DR = Byte;
    }
    else
    {
        Error = ERROR_Nok;
    }
    
    return Error;
    
}

Error_t UART_RX_Byte(u8 UART_Peri, u8 *Byte)
{
    Error_t Error;

    u8 RXNE = UART[UART_Peri]->CR1 & UART_GET_RXNE_MASK;

    if (RXNE)
    {
        *Byte = UART[UART_Peri]->DR;
    }
    else
    {
        Error = ERROR_Nok;
    }
    
    return Error;

}



static u32 Calc_Baud_Rate(u16 Baud_Rate, u8 Over_Sampling)
{
    volatile u32 Result = 0;
    volatile u32 Div_Mantissa = 0;
    volatile u8  Div_Fraction = 0;
    volatile u8  Sample = 0;
    volatile float Fraction = 0;
    volatile float Temp_Div = 0;

    if (Over_Sampling)
    {
        Sample = 1;
    }
    
    Temp_Div = ( (UART_SYSTEM_FREQ) / ( Baud_Rate * 8 * (2 - Sample) ) );

    Fraction = Temp_Div - (u32) Temp_Div;
    Div_Mantissa = Temp_Div - Fraction;

    if(Over_Sampling)
    {
        Div_Fraction = Round_Float(8 * Fraction);
    }
    else
    {
        Div_Fraction = Round_Float(16 * Fraction);
    }

    Result = Div_Fraction;
    Result = Div_Mantissa << 4;

    return Result;
    
}

static u32 Round_Float(float Float_Number)
{
    return (u32)(Float_Number + 0.5);   
}

void USART1_IRQHandler(void)
{

}

void USART2_IRQHandler(void)
{
    
}

void USART6_IRQHandler(void)
{
    
}