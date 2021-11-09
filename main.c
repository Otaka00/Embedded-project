#include "DIO.h"
void main()
{
  int c = 0;
  DIO_init(1, PORTF, OUT);
  DIO_init(2, PORTF, OUT);
  DIO_init(3, PORTF, OUT);
  while(1){
  DIO_WritePin(PORTF , 1 , 1); 
  while (c < 1000000) c++;
  c = 0;
  DIO_WritePin(PORTF , 1 , 0); 
  DIO_WritePin(PORTF , 2 , 1);
  while (c < 1000000) c++;
  c = 0;
  DIO_WritePin(PORTF , 2 , 0); 
  DIO_WritePin(PORTF , 3 , 1);
  while (c < 1000000) c++;
  c = 0;
  DIO_WritePin(PORTF , 3 , 0); 
  }
}







/*  while(1){
  DIO_WritePin(PORTF, 1, 1); 
  while(c<1000000) c++;
  c=0;
  if(DIO_ReadPin(PORTF, 1)){
    DIO_WritePin(PORTF , 1 , 0); 
    DIO_WritePin(PORTF , 2 , 1);
    while(c<1000000) c++;
  c=0;
  }
  DIO_WritePin(PORTF, 1, 0);
} */
