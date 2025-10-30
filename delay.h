#include<LPC21xx.h>
void delay_ms(int ms)

{

T1PR=15000-1;
T1TCR=0x01;
while(T1TC<ms);
T1TCR=0x03;
T1TCR=0x00;

}
