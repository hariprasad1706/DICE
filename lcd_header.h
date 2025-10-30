#include"delay.h"
#define lcd_d 0xFF
#define rs 1<<8
#define E 1<<9
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char *);
void lcd_integer(unsigned int);
void lcd_init(void)
{
	IODIR0=lcd_d|rs|E;
	lcd_cmd(0X01);
	lcd_cmd(0X02);
	lcd_cmd(0X0C);
	lcd_cmd(0X38);
	lcd_cmd(0X80);
}

void lcd_cmd(unsigned char cmd)

{

	  IOCLR0=lcd_d;
	  IOSET0=cmd;
	  IOCLR0=rs;
	  IOSET0=E;
	  delay_ms(2);
	  IOCLR0=E;
}
void lcd_data(unsigned char d)
{
	  IOCLR0=lcd_d;
	  IOSET0=d;
	  IOSET0=rs;
	  IOSET0=E;
	  delay_ms(2);
	  IOCLR0=E;
}
void lcd_string(unsigned char *s)
{
while(*s)
{
	lcd_data(*s++);
	}
} 
void lcd_integer(unsigned int n)
{
int arr[5],i=0,j;
	 	while(n)
		{
			arr[i++]=n%10;
			n/=10;
	    }
		for(j=i-1;j>=0;j--)
		lcd_data((arr[j]+48));
}
