#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE_ADDRESS 0x40021000 

#define RCC_CR        *((u32 *)(RCC_BASE_ADDRESS + 0x00))
#define RCC_CFGR      *((u32 *)(RCC_BASE_ADDRESS + 0x04))
#define RCC_CIR       *((u32 *)(RCC_BASE_ADDRESS + 0x08))
#define RCC_APB2RSTR  *((u32 *)(RCC_BASE_ADDRESS + 0x0C))
#define RCC_APB1RSTR  *((u32 *)(RCC_BASE_ADDRESS + 0x10))
#define RCC_AHBENR    *((u32 *)(RCC_BASE_ADDRESS + 0x14))
#define RCC_APB2ENR   *((u32 *)(RCC_BASE_ADDRESS + 0x18))
#define RCC_APB1ENR   *((u32 *)(RCC_BASE_ADDRESS + 0x1C))
#define RCC_BDCR      *((u32 *)(RCC_BASE_ADDRESS + 0x20))
#define RCC_CSR       *((u32 *)(RCC_BASE_ADDRESS + 0x24))

/* BUS IDs   */


#define RCC_HSE_CRYSTAL  0 
#define RCC_HSE_RC       1
#define RCC_HSI          2
#define RCC_PLL          3

#define HSE         0
#define HSE_DIV_2   1
#define HSI_DIV_2   2

#endif
