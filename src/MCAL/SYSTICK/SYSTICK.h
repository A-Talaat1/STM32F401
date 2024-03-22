#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "../../../lib/Error/Error.h"
#include "../../../lib/StdTypes.h"
#include "MCAL/SYSTICK/SYSTICK_Confg.h"

typedef enum
{
    SYSTICK_Not_Expired,
    SYSTICK_Expired,
}SYSTICK_State_t;

typedef void (* SYSTICK_CB_t) (void);

/*Func1: Set the time to be triggered with periodically*/
Error_t SYSTICK_Set_Time_mS(u32 Time_mS);
/*Func2: Set the ticks to be triggered with periodically*/
Error_t SYSTICK_Set_Ticks(u32 Ticks);
/*Func3: current tick*/
u32 SYSTICK_Get_Tick(void);
/*Func4: Setcall back function with periodicity*/
Error_t SYSTICK_Set_CB(SYSTICK_CB_t SYSTICK_CB);
/*Func5: Is expired*/
SYSTICK_State_t SYSTICK_Is_Expired(void);
/*Func6: Disable the timer*/
void SYSTICK_Disable(void);
#endif /*SYSTICK_H_*/