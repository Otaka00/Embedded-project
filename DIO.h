#include "types.h"
#include "lab3.h"
#include "stdint.h"
#include "tm4c123gh6pm.h"

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define IN 1
#define OUT 0

void DIO_init(int8 pin, int8 port, int8 dir);
void DIO_WritePin(int8 port, int8 pin, int8 value);
void DIO_WritePort(int8 port, int8 value);
int8 DIO_ReadPin(int8 port, int8 pin);
int8 DIO_ReadPort(int8 port);