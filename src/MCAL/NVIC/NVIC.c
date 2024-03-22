#include "MCAL/NVIC/NVIC.h"

#define NVIC_BASE_ADDRESS 0xE000E100

#define NVIC ((volatile NVIC_Registers_t * const)NVIC_BASE_ADDRESS)

typedef struct
{

    u32 ISER[8];
    u32 RESERVED0[24];
    u32 ICER[8];
    u32 RESERVED1[24];
    u32 ISPR[8];
    u32 RESERVED2[24];
    u32 ICPR[8];
    u32 RESERVED3[24];
    u32 IABR[8];
    u32 RESERVED4[56];
    u8 IPR[240];
    u32 RESERVED5[580];

}NVIC_Registers_t;

static Error_t Validate_IRQ (IRQ_t IRQ);

Error_t NVIC_Enable_IRQ(IRQ_t IRQ)
{
    Error_t Error_State = Validate_IRQ(IRQ);

    u32 Register = (IRQ / 32) ;
    u32 Bit = (IRQ % 32);

    if (Error_State != ERROR_Ok) {/*Do Nothing*/}
    else
    {
        NVIC->ISER[Register] |= (1 << Bit) ;
    }
    return Error_State;
}

Error_t NVIC_Disable_IRQ(IRQ_t IRQ)
{
    Error_t Error_State = Validate_IRQ(IRQ);

    u32 Register = (IRQ / 32) ;
    u32 Bit = (IRQ % 32);

    if (Error_State != ERROR_Ok) {/*Do Nothing*/}
    else
    {
        NVIC->ICER[Register] |= (1 << Bit) ;
    }
    return Error_State;

}

Error_t NVIC_Set_Pending_IRQ(IRQ_t IRQ)
{
    Error_t Error_State = Validate_IRQ(IRQ);

    u32 Register = (IRQ / 32) ;
    u32 Bit = (IRQ % 32);

    if (Error_State != ERROR_Ok) {/*Do Nothing*/}
    else
    {
        NVIC->ISPR[Register] |= (1 << Bit) ;
    }
    return Error_State;
}

Error_t NVIC_Clear_Pending_IRQ(IRQ_t IRQ)
{
    Error_t Error_State = Validate_IRQ(IRQ);

    u32 Register = (IRQ / 32) ;
    u32 Bit = (IRQ % 32);

    if (Error_State != ERROR_Ok) {/*Do Nothing*/}
    else
    {
        NVIC->ICPR[Register] |= (1 << Bit) ;
    }
    return Error_State;
}

Error_t NVIC_Get_Pending_IRQ(IRQ_t IRQ, u8 *Pending_State)
{
    Error_t Error_State = ERROR_Ok;

    u32 Register = (IRQ / 32) ;
    u32 Bit = (IRQ % 32);

    if ( (Error_State = Validate_NULL_Pointer(Pending_State)) != ERROR_Ok){/*Do Nothing*/}
    else
    if ((Error_State = Validate_IRQ(IRQ)) != ERROR_Ok){/*Do Nothing*/}
    else
    {
        *Pending_State = (NVIC->ISPR[Register] & (1 << Bit) );
    }
    
    return Error_State;
}

Error_t NVIC_Get_Active_State(IRQ_t IRQ, u8 *ActiveState)
{
   Error_t Error_State = ERROR_Ok;

    u32 Register = (IRQ / 32) ;
    u32 Bit = (IRQ % 32);

    if ( (Error_State = Validate_IRQ(IRQ)) != ERROR_Ok) {/*Do Nothing*/}
    else
    {
        *ActiveState = (NVIC->IABR[Register] & (1 << Bit) );
    }
    return Error_State;
}


static Error_t Validate_IRQ (IRQ_t IRQ)
{
    Error_t Error_State;

    if (IRQ >= IRQ_Count || IRQ < 0)
    {
        Error_State = ERROR_Invalid_IRQ;
    }
    else
    {
        Error_State = ERROR_Ok;
    }
    
    return Error_State;
}