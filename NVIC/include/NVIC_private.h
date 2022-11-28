#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS  0xE000E100

#define NVIC_ISER0 *((volatile u32*)(NVIC_BASE_ADDRESS+0x000))
#define NVIC_ISER1 *((volatile u32*)(NVIC_BASE_ADDRESS+0x004))


#define NVIC_ICER0 *((volatile u32*)(NVIC_BASE_ADDRESS+0x080))
#define NVIC_ICER1 *((volatile u32*)(NVIC_BASE_ADDRESS+0x084))

#define NVIC_ISPR0 *((volatile u32*)(NVIC_BASE_ADDRESS+0x100))
#define NVIC_ISPR1 *((volatile u32*)(NVIC_BASE_ADDRESS+0x104))
#endif