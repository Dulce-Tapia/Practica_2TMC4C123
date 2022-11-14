
#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Macros
#define _50MHZ 0x07
#define _15MHZ 0x0F
#define _80MHZ 0x04 

//Definición de la práctica 2
#define SENSOR  (*((volatile uint32_t *)0x4002400C))
#define LIGHT   (*((volatile uint32_t *)0x400050FC))
#define goN   0
#define waitN 1
#define goE   2
#define waitE 3
#define NVIC_ST_CTRL_R      (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile uint32_t *)0xE000E018))


#include "TM4C123GH6PM.h"
#include "GPIO.h"
#include "PLL.h"
#include "SysTick.h"

#endif /* INCLUDE_H_ */