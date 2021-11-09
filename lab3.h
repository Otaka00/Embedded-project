#define Set_Bit(Reg,Pin){Reg |= (1 << Pin);}
#define Clear_Bit(Reg,Pin){Reg &= (0 << Pin);} 
#define Get_Bit(Reg,Pin) {(Reg & (1 << Pin)) >> Pin;} 
#define Toggle_Bit(Reg,Pin) {Reg ^= (1 << Pin);} 