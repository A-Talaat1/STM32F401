#ifndef NVIC_H_
#define NVIC_H_

#include "../../../lib/Error/Error.h"
#include "../../../lib/StdTypes.h"
#include "MCAL/NVIC/Interrupts.h"

Error_t NVIC_Enable_IRQ(IRQ_t IRQ);

Error_t NVIC_Disable_IRQ(IRQ_t IRQ);

Error_t NVIC_Set_Pending_IRQ(IRQ_t IRQ);

Error_t NVIC_Clear_Pending_IRQ(IRQ_t IRQ);

Error_t NVIC_Get_Pending_IRQ(IRQ_t IRQ, u8 *Pending_State);

Error_t NVIC_Set_Priority(IRQ_t IRQ, u32 Priority);

Error_t NVIC_Get_Priority(IRQ_t IRQ);

Error_t NVIC_Get_Active_State(IRQ_t IRQ, u8 *ActiveState);

#endif /*NVIC_H_*/