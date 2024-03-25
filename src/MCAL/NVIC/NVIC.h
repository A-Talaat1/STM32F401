#ifndef NVIC_H_
#define NVIC_H_

#include "../../../lib/Error/Error.h"
#include "../../../lib/StdTypes.h"
#include "MCAL/NVIC/Interrupts.h"

/**
 * @brief Enables the specified IRQ in the NVIC.
 * 
 * @param IRQ The IRQ to be enabled.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t NVIC_Enable_IRQ(IRQ_t IRQ);

/**
 * @brief Disables the specified IRQ in the NVIC.
 * 
 * @param IRQ The IRQ to be disabled.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t NVIC_Disable_IRQ(IRQ_t IRQ);

/**
 * @brief Sets the pending state of the specified IRQ in the NVIC.
 * 
 * @param IRQ The IRQ to set as pending.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t NVIC_Set_Pending_IRQ(IRQ_t IRQ);

/**
 * @brief Clears the pending state of the specified IRQ in the NVIC.
 * 
 * @param IRQ The IRQ to clear as pending.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t NVIC_Clear_Pending_IRQ(IRQ_t IRQ);

/**
 * @brief Gets the pending state of the specified IRQ in the NVIC.
 * 
 * @param IRQ The IRQ to get the pending state for.
 * @param Pending_State Pointer to where the pending state will be stored.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t NVIC_Get_Pending_IRQ(IRQ_t IRQ, u8 *Pending_State);

/**
 * @brief Sets the priority of the specified IRQ in the NVIC.
 * 
 * @param IRQ The IRQ to set the priority for.
 * @param Priority The priority level to set.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t NVIC_Set_Priority(IRQ_t IRQ, u32 Priority);

/**
 * @brief Gets the priority of the specified IRQ in the NVIC.
 * 
 * @param IRQ The IRQ to get the priority for.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t NVIC_Get_Priority(IRQ_t IRQ);

/**
 * @brief Gets the active state of the specified IRQ in the NVIC.
 * 
 * @param IRQ The IRQ to get the active state for.
 * @param ActiveState Pointer to where the active state will be stored.
 * @return Error_t Error code indicating success or failure of the operation.
 */
Error_t NVIC_Get_Active_State(IRQ_t IRQ, u8 *ActiveState);

#endif /* NVIC_H_ */
