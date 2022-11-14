#include "lib/include.h"

// Linked data structure
struct State 
{
  uint32_t Out;
  uint32_t Time; 
  uint32_t Next[4];
};
typedef const struct State State_t;

State_t FSM[4]=
{
 {0x21,3000,{goN,waitN,goN,waitN}},
 {0x22, 500,{goE,goE,goE,goE}},
 {0x0C,3000,{goE,goE,waitE,waitE}},
 {0x14, 500,{goN,goN,goN,goN}}
 };

uint32_t S;  // index to the current state
uint32_t Input;

int main(void){
   
  Configurar_GPIO();
   //Practica 2
   volatile uint32_t delay;
  Configurar_PLL(_80MHZ);  //se coloca el valor del reloj
  SysTick_Init();   // Program 10.2
  SYSCTL->RCGCGPIO |= 0x12;      // B E
  delay = SYSCTL->RCGCGPIO;      // no need to unlock
  GPIOE->DIR &= ~0x03;   // inputs on PE1-0
  GPIOE->DEN |= 0x03;    // enable digital on PE1-0
  GPIOB->DIR |= 0x3F;    // outputs on PB5-0
  GPIOB->DEN |= 0x3F;    // enable digital on PB5-0
  S = goN;  
  while(1)
  {
    LIGHT = FSM[S].Out;  // set lights
    SysTick_Wait10ms(FSM[S].Time);
    Input = SENSOR;     // read sensors
    S = FSM[S].Next[Input]; 
  }
}