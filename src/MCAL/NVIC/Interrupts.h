#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

typedef enum
{

    WWDG,                    /* Watchdog interrupt */
    PVD,                     /* Power voltage detector interrupt */
    TAMP_STAMP,              /* Tamper and time stamp interrupts */
    RTC_WKUP,                /* RTC (Real-Time Clock) wakeup interrupt */
    FLASH,                   /* Flash global interrupt */
    RCC,                     /* RCC (Reset and Clock Control) global interrupt */
    EXTI0,                   /* EXTI line 0 interrupt */
    EXTI1,                   /* EXTI line 1 interrupt */
    EXTI2,                   /* EXTI line 2 interrupt */
    EXTI3,                   /* EXTI line 3 interrupt */
    EXTI4,                   /* EXTI line 4 interrupt */
    DMA1_Stream0,            /* DMA1 stream 0 global interrupt */
    DMA1_Stream1,            /* DMA1 stream 1 global interrupt */
    DMA1_Stream2,            /* DMA1 stream 2 global interrupt */
    DMA1_Stream3,            /* DMA1 stream 3 global interrupt */
    DMA1_Stream4,            /* DMA1 stream 4 global interrupt */
    DMA1_Stream5,            /* DMA1 stream 5 global interrupt */
    DMA1_Stream6,            /* DMA1 stream 6 global interrupt */
    ADC,                     /* ADC1, ADC2, and ADC3 global interrupts */
    EXTI9_5,                 /* EXTI line 9 to 5 interrupts */
    TIM1_BRK_TIM9,           /* TIM1 break interrupt and TIM9 global interrupt */
    TIM1_UP_TIM10,           /* TIM1 update interrupt and TIM10 global interrupt */
    TIM1_TRG_COM_TIM11,      /* TIM1 trigger and commutation interrupts and TIM11 global interrupt */
    TIM1_CC,                 /* TIM1 capture compare interrupt */
    TIM2,                    /* TIM2 global interrupt */
    TIM3,                    /* TIM3 global interrupt */
    TIM4,                    /* TIM4 global interrupt */
    I2C1_EV,                 /* I2C1 event interrupt */
    I2C1_ER,                 /* I2C1 error interrupt */
    I2C2_EV,                 /* I2C2 event interrupt */
    I2C2_ER,                 /* I2C2 error interrupt */
    SPI1,                    /* SPI1 global interrupt */
    SPI2,                    /* SPI2 global interrupt */
    USART1,                  /* USART1 global interrupt */
    USART2,                  /* USART2 global interrupt */
    EXTI15_10,               /* EXTI line 15 to 10 interrupts */
    RTC_Alarm,               /* RTC alarm interrupt */
    OTG_FS_WKUP,             /* USB OTG FS wakeup interrupt */
    DMA1_Stream7,            /* DMA1 stream 7 global interrupt */
    SDIO,                    /* SDIO global interrupt */
    TIM5,                    /* TIM5 global interrupt */
    SPI3,                    /* SPI3 global interrupt */
    DMA2_Stream0,            /* DMA2 stream 0 global interrupt */
    DMA2_Stream1,            /* DMA2 stream 1 global interrupt */
    DMA2_Stream2,            /* DMA2 stream 2 global interrupt */
    DMA2_Stream3,            /* DMA2 stream 3 global interrupt */
    DMA2_Stream4,            /* DMA2 stream 4 global interrupt */
    OTG_FS,                  /* USB OTG FS global interrupt */
    DMA2_Stream5,            /* DMA2 stream 5 global interrupt */
    DMA2_Stream6,            /* DMA2 stream 6 global interrupt */
    DMA2_Stream7,            /* DMA2 stream 7 global interrupt */
    USART6,                  /* USART6 global interrupt */
    I2C3_EV,                 /* I2C3 event interrupt */
    I2C3_ER,                 /* I2C3 error interrupt */
    FPU,                     /* FPU global interrupt */
    SPI4,                    /* SPI4 global interrupt */
    IRQ_Count,               /* Count of IRQs */

} IRQ_t;

#endif /*INTERRUPTS_H_*/