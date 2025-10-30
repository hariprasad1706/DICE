#include<lpc21xx.h>
#include"lcd_header.h"
char count=0;
void ext_int0_isr(void)__irq
{
    unsigned char a;
	delay_ms(500);
    EXTINT=0x01;
	lcd_cmd(0xc1);
	if(T0PC==0)
	a=6;
	else
	a=T0PC;
    lcd_integer(a);
	count++;
	lcd_cmd(0xc9);
	lcd_integer(count);
	delay_ms(100);
	lcd_cmd(0x80);
	VICVectAddr=0;
	}
int main()
{		
	  PINSEL1=0x1;	       					//p0.16 EINTO  2MODE(01)
	 // IOSET0=0x1;
	  VICIntSelect=0;
	  VICVectCntl0=0x20|14;				   	//EINTO	IS channal 14
	  VICVectAddr0=(unsigned long)ext_int0_isr;
	  EXTMODE=0x01;			  			    //EINTO MOOD edge
	  EXTPOLAR=0x00;
      VICIntEnable=1<<14;		 		    // EINTO IS CHANNAL 14
	  lcd_init();
	  lcd_integer(count);
	  	
	  lcd_cmd(0x80);
	  lcd_string("DICE    COUNT");
	  	 while(1){
		 T0PR=6-1;
		 T0TCR=0x01;	

	 }
	 }
