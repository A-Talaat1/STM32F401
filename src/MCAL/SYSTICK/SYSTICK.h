#ifndef SYSTICK_H_  // Header guard to prevent double inclusion
#define SYSTICK_H_

#include "../../../lib/Error/Error.h"  // Including error handling library
#include "../../../lib/StdTypes.h"      // Including standard data types library
#include "MCAL/SYSTICK/SYSTICK_Confg.h" // Including SysTick configuration header

// Enumeration defining SysTick states
typedef enum
{
    SYSTICK_Not_Expired, // SysTick timer has not expired
    SYSTICK_Expired      // SysTick timer has expired
} SYSTICK_State_t;

// Function pointer type for SysTick callback function
typedef void (* SYSTICK_CB_t) (void);

/**
 * @brief Set the time interval for SysTick in milliseconds.
 * 
 * @param Time_mS Time interval in milliseconds.
 * @return Error_t Error status.
 */
Error_t SYSTICK_Set_Time_mS(u32 Time_mS);

/**
 * @brief Set the time interval for SysTick in ticks.
 * 
 * @param Ticks Time interval in ticks.
 * @return Error_t Error status.
 */
Error_t SYSTICK_Set_Ticks(u32 Ticks);

/**
 * @brief Get the current tick count of SysTick.
 * 
 * @return u32 Current tick count.
 */
u32 SYSTICK_Get_Tick(void);

/**
 * @brief Set the callback function to be called when SysTick expires.
 * 
 * @param SYSTICK_CB Callback function.
 * @return Error_t Error status.
 */
Error_t SYSTICK_Set_CB(SYSTICK_CB_t SYSTICK_CB);

/**
 * @brief Check if SysTick timer has expired.
 * 
 * @return SYSTICK_State_t SysTick state.
 */
SYSTICK_State_t SYSTICK_Is_Expired(void);

/**
 * @brief Disable the SysTick timer.
 * 
 */
void SYSTICK_Disable(void);

#endif /* SYSTICK_H_ */ // End of header guard and file
