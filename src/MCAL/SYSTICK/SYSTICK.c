#include "MCAL/SYSTICK/SYSTICK.h"
#include "../../../lib/Error/Error.h"

#define BASE_ADDRESS              0xE000E010UL

#define MAX_TICKS                 0x00FFFFFFUL
#define SYSTICK_VAL_MASK          0x00000000UL
#define SYSTICK_CTRL_MASK         0x00000007UL
#define SYSTICK_IS_EXPIRED_MASK   0x00010000UL
#define SYSTICK_DISABLE_MASK      0xFFFFFFFEUL

#define SYSTICK ((volatile SYSTICK_Register_t * const) BASE_ADDRESS)

SYSTICK_CB_t CB = NULL;

typedef struct
{
    u32 CTRL;
    u32 LOAD;
    u32 VAL;
    u32 CALIB;
}SYSTICK_Register_t;

/*Static Functions APIs*/
static void SYSTICK_Init(void);
static Error_t Validate_Time (u32 Time_mS);
static Error_t Validate_Ticks (u32 Ticks);
static u32 Calc_Max_Time (void);


Error_t SYSTICK_Set_Time_mS(u32 Time_mS)
{
    Error_t Error_State = Validate_Time(Time_mS);
    if (Error_State != ERROR_Ok){/*Return Error*/}
    else
    {
    SYSTICK->LOAD = (( (u64)(Time_mS) * (u64)(SYS_CLK) / (u64)(1000) ) - (u64)(1) );
    SYSTICK_Init();
    }
    return Error_State;
}

Error_t SYSTICK_Set_Ticks(u32 Ticks)
{
    Error_t Error_State = Validate_Ticks(Ticks);
    if (Error_State != ERROR_Ok){/*Return Error*/}
    else
    {
        SYSTICK_Init();
        SYSTICK->LOAD = Ticks;
    }
    return Error_State;
}

u32 SYSTICK_Get_Tick(void)
{
    return SYSTICK->VAL;
}

Error_t SYSTICK_Set_CB(SYSTICK_CB_t SYSTICK_CB)
{
    Error_t Error_State = Validate_NULL_Pointer(SYSTICK_CB);
    if (Error_State != ERROR_Ok){/*Return Error*/}
    else
    {
        CB = SYSTICK_CB;
    }
    return Error_State;
}

SYSTICK_State_t SYSTICK_Is_Expired(void)
{
    return (SYSTICK->CTRL & SYSTICK_IS_EXPIRED_MASK);
}

void SYSTICK_Disable(void)
{
    SYSTICK->CTRL &= ~SYSTICK_CTRL_MASK;
}

void SysTick_Handler(void)
{
    if (CB)
    {
        CB();
    }
    
}

/***************************************************************/
static void SYSTICK_Init(void)
{
    SYSTICK->VAL  &= SYSTICK_VAL_MASK;
    SYSTICK->CTRL |= SYSTICK_CTRL_MASK;
}

static Error_t Validate_Time (u32 Time_mS)
{
    Error_t Error_State = ERROR_Ok;
    if (Time_mS < 0 || Time_mS > Calc_Max_Time())
    {
        Error_State = ERROR_Invalid_Argument;
    }
    return Error_State;
}

static Error_t Validate_Ticks (u32 Ticks)
{
    Error_t Error_State = ERROR_Ok;
    if (Ticks < 0 || Ticks > MAX_TICKS)
    {
        Error_State = ERROR_Invalid_Argument;
    }
    return Error_State;
}

static u32 Calc_Max_Time (void)
{
    return (((u64)MAX_TICKS * (u64)1000) / (u64)SYS_CLK);
}