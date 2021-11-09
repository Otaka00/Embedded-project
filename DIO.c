#include "DIO.h"

void DIO_init(int8 pin, int8 port, int8 dir){
  //while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
  switch(port) {
           case PORTA:
             Set_Bit(SYSCTL_RCGCGPIO_R ,0);
             while((SYSCTL_PRGPIO_R&0x00000001) == 0){};
               if(dir == IN){
                 Clear_Bit(GPIO_PORTA_DIR_R, pin);}
               else{Set_Bit(GPIO_PORTA_DIR_R, pin);}
               Set_Bit(GPIO_PORTA_DEN_R, pin);
             break;
             
           case PORTB:
             Set_Bit(SYSCTL_RCGCGPIO_R ,1);
             while((SYSCTL_PRGPIO_R&0x00000002) == 0){};
               if(dir == IN){
                 Clear_Bit(GPIO_PORTB_DIR_R, pin);}
               else{Set_Bit(GPIO_PORTB_DIR_R, pin);}
               Set_Bit(GPIO_PORTB_DEN_R, pin);
             break;
             
           case PORTC:
             Set_Bit(SYSCTL_RCGCGPIO_R ,2);
             while((SYSCTL_PRGPIO_R&0x00000004) == 0){};
               GPIO_PORTC_LOCK_R = 0x4C4F434B;
               Set_Bit(GPIO_PORTC_CR_R, pin);
               if(dir == IN){
                 Clear_Bit(GPIO_PORTC_DIR_R, pin);}
               else{Set_Bit(GPIO_PORTC_DIR_R, pin);}
               Set_Bit(GPIO_PORTC_DEN_R, pin);
             break;
             
           case PORTD:
             Set_Bit(SYSCTL_RCGCGPIO_R ,3);
             while((SYSCTL_PRGPIO_R&0x00000008) == 0){};
               GPIO_PORTD_LOCK_R = 0x4C4F434B;
               Set_Bit(GPIO_PORTD_CR_R, pin);
                if(dir == IN){
                 Clear_Bit(GPIO_PORTD_DIR_R, pin);}
               else{Set_Bit(GPIO_PORTD_DIR_R, pin);}
               Set_Bit(GPIO_PORTD_DEN_R, pin);
             break;
             
           case PORTE:
             Set_Bit(SYSCTL_RCGCGPIO_R ,4);
             while((SYSCTL_PRGPIO_R&0x00000010) == 0){};
               if(dir == IN){
                 Clear_Bit(GPIO_PORTE_DIR_R, pin);
               }
               else{Set_Bit(GPIO_PORTE_DIR_R, pin);}
               Set_Bit(GPIO_PORTE_DEN_R, pin);
             break;
             
           case PORTF:
             Set_Bit(SYSCTL_RCGCGPIO_R ,5);
            while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
               GPIO_PORTF_LOCK_R = 0x4C4F434B;
               Set_Bit(GPIO_PORTF_CR_R, pin);
                if(dir == IN){
                  Clear_Bit(GPIO_PORTF_DIR_R, pin);}
               else{Set_Bit(GPIO_PORTF_DIR_R, pin);}
               Set_Bit(GPIO_PORTF_DEN_R, pin);
             break;
           default:
             break;
  }
}

void DIO_WritePin(int8 port, int8 pin, int8 value){
  switch (port){
  case PORTA:
  if(value == 0){
   Clear_Bit(GPIO_PORTA_DATA_R, pin);
  }
  else if (value == 1){
    Set_Bit(GPIO_PORTA_DATA_R, pin);
  }
    break;
  case PORTB:
    if(value == 0){
   Clear_Bit(GPIO_PORTB_DATA_R, pin);
  }
  else if (value == 1){
    Set_Bit(GPIO_PORTB_DATA_R, pin);
  }
    break;
  case PORTC:
   if(value == 0){
   Clear_Bit(GPIO_PORTC_DATA_R, pin);
  }
  else if (value == 1){
    Set_Bit(GPIO_PORTC_DATA_R, pin);
  } 
    break;
  case PORTD:
   if(value == 0){
   Clear_Bit(GPIO_PORTD_DATA_R, pin);
  }
  else if (value == 1){
    Set_Bit(GPIO_PORTD_DATA_R, pin);
  } 
    break;
  case PORTE:
   if(value == 0){
   Clear_Bit(GPIO_PORTE_DATA_R, pin);
  }
  else if (value == 1){
    Set_Bit(GPIO_PORTE_DATA_R, pin);
  } 
    break;
  case PORTF:
   if(value == 0){
   Clear_Bit(GPIO_PORTF_DATA_R, pin);
  }
  else if (value == 1){
    Set_Bit(GPIO_PORTF_DATA_R, pin);
  } 
    break;
  default:
    break;
  }
}

void DIO_WritePort(int8 port, int8 value){
  switch (port) {
  case PORTA:
    GPIO_PORTA_DATA_R = value;
    break;
  case PORTB:
    GPIO_PORTB_DATA_R = value;
    break;
  case PORTC:
    GPIO_PORTC_DATA_R = value;
    break;
  case PORTD:
    GPIO_PORTD_DATA_R = value;
    break;
  case PORTE:
    GPIO_PORTE_DATA_R = value;
    break;
  case PORTF:
    GPIO_PORTF_DATA_R = value;
    break;
  default:
    break;
  }
}

int8 DIO_ReadPin(int8 port, int8 pin){
 switch (port) {
  case PORTA:
    return (Get_Bit(GPIO_PORTA_DATA_R, pin));
  case PORTB:
    return (Get_Bit(GPIO_PORTB_DATA_R, pin));
  case PORTC:
    return(Get_Bit(GPIO_PORTC_DATA_R, pin));
  case PORTD:
    return(Get_Bit(GPIO_PORTD_DATA_R, pin));
  case PORTE:
    return(Get_Bit(GPIO_PORTE_DATA_R, pin));    
  case PORTF:
    return(Get_Bit(GPIO_PORTF_DATA_R, pin));
  default:
    return -1;
  }
}

int8 DIO_ReadPort(int8 port){
switch (port) {
  case PORTA:
    return GPIO_PORTA_DATA_R;
  case PORTB:
    return GPIO_PORTB_DATA_R;
  case PORTC:
    return GPIO_PORTC_DATA_R;
  case PORTD:
    return GPIO_PORTD_DATA_R;
  case PORTE:
    return GPIO_PORTE_DATA_R;
  case PORTF:
    return GPIO_PORTF_DATA_R;
  default:
    return -1;
  }
}