#include "UART.h"

#define UART_NUMBER_OF_PERIPHERALS 0x00000003UL

/*UART Peripherals Base Address */
#define UART_ONE_BASE_ADDRESS 0x40011000UL
#define UART_TWO_BASE_ADDRESS 0x40004400UL
#define UART_SIX_BASE_ADDRESS 0x40011400UL

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

static volatile UART_Registers_t * const UART[UART_NUMBER_OF_PERIPHERALS] = { ((volatile UART_Registers_t * const )UART_ONE_BASE_ADDRESS),
                                                                              ((volatile UART_Registers_t * const )UART_TWO_BASE_ADDRESS),
                                                                              ((volatile UART_Registers_t * const )UART_SIX_BASE_ADDRESS) };


/*Static APIs*/
static u32 Calc_Baud_Rate(u16 Baud_Rate, u8 Over_Sampling);
static u32 Round_Float(float Float_Number);


Error_t UART_Init(UART_Confg_t *UART_CONFIG)
{
    u32 Temp_BRR = UART[UART_CONFIG->UART_ID]->BRR;
    u32 Temp_CR1 = UART[UART_CONFIG->UART_ID]->CR1;
    u32 Temp_CR2 = UART[UART_CONFIG->UART_ID]->CR2;
    u32 Temp_CR3 = UART[UART_CONFIG->UART_ID]->CR3;

    Temp_BRR = Calc_Baud_Rate(UART_CONFIG->Baud_Rate, UART_CONFIG->Over_Sampling);

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

}

static u32 Calc_Baud_Rate(u16 Baud_Rate, u8 Over_Sampling)
{
    u32 Result;
    u32 Div_Mantissa;
    u8  Div_Fraction, Sample;
    float Fraction, Temp_Div;

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
    float fraction;
    u8 Addition = 0;

    fraction = Float_Number - (u32) Float_Number;

    if (fraction >= 0.5)
    {
        Addition = 1;

    }

    return ( (u32) Float_Number + Addition);
    
}