#include "Operations.h"

int power(int x)
{
	if(x == 0)
	{
		return 1;
	}
	else
	{
		int y = 1;
		int ten = 10;
		for(int t = 0; t < x; t++)
		{
			y = y * ten;
		}
		return y;
	}
}
int convertValue(int x[], int f)
{
	int c = 0;
	int sum = 0;
	for(int i = 0; i < f+1; i++)
	{
		c = x[i] * power(f);
		sum += c;
	}
	return sum;
	
}
void Addition(int x[],int index1, int y[], int index2)
{
	int val1 = convertValue(x,index1);
	int val2 = convertValue(y,index2);
	int sum = val1 + val2;
	ST7735_SetCursor(0,7);
	ST7735_OutString("Answer:");
	ST7735_SetCursor(0,8);
	LCD_OutDec(sum);
	int status1 = GPIO_PORTB_DATA_R & 0x80;
	while(status1 != 0x80)
	{
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
	return;
}

void Subtraction(int x[],int index1, int y[], int index2)
{
	int val1 = convertValue(x,index1);
	int val2 = convertValue(y,index2);
	int sum = val1 - val2;
	ST7735_SetCursor(0,7);
	ST7735_OutString("Answer:");
	ST7735_SetCursor(0,8);
	LCD_OutDec(sum);
	int status1 = GPIO_PORTB_DATA_R & 0x80;
	while(status1 != 0x80)
	{
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
	return;
}

void Multiplication(int x[],int index1, int y[], int index2)
{
	int val1 = convertValue(x,index1);
	int val2 = convertValue(y,index2);
	int sum = val1 * val2;
	ST7735_SetCursor(0,7);
	ST7735_OutString("Answer:");
	ST7735_SetCursor(0,8);
	LCD_OutDec(sum);
	int status1 = GPIO_PORTB_DATA_R & 0x80;
	while(status1 != 0x80)
	{
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
	return;
}

void Division(int x[],int index1, int y[], int index2)
{
	int val1 = convertValue(x,index1);
	int val2 = convertValue(y,index2);
	int sum = val1/val2;
	ST7735_SetCursor(0,7);
	ST7735_OutString("Answer:");
	ST7735_SetCursor(0,8);
	LCD_OutDec(sum);
	int status1 = GPIO_PORTB_DATA_R & 0x80;
	while(status1 != 0x80)
	{
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
	return;
}

int Converter(int identity, int num)
{
	int j = 0;
	for(int i = 0; i < 10; i++)
	{
		if(arr[i][j]==identity)
		{
			if(arr[i][j+1] == num)
			{
				return arr[i][j+2];
					
			}
			
		}
		
	}
	
}

void getInput(int* index1, int g)
{
	int index = 0;
	int j = 0;
	int status1 = GPIO_PORTB_DATA_R & 0x80;

	while(status1 != 0x80)
	{
		int get1 = GPIO_PORTE_DATA_R & 0x7F;
		int get2 = GPIO_PORTD_DATA_R & 0x0F;
		if(get1 != 0 | get2 != 0)
		{
			if(get1 != 0)
			{
				int x = Converter(0,get1);
				input1[index]=x;
				index++;
				ST7735_SetCursor(j,g);
	      LCD_OutDec(x);
				j++;
			}
			if(get2 != 0)
			{
				int y = Converter(1,get2);
				input1[index]=y;
				index++;
				ST7735_SetCursor(j,g);
	      LCD_OutDec(y);
				j++;
				
			}
		}
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
}

void Graphing()
{
	
	ST7735_FillScreen(0x000);
	ST7735_SetCursor(0,0);
	ST7735_OutString("_x^2 + _x + _");
	ST7735_SetCursor(0,1);
	ST7735_OutString("First Blank:");
	int first_blank = 0;
	getInput(&first_blank,2);
	ST7735_SetCursor(0,3);
	ST7735_OutString("Second Blank:");
	int second_blank = 0;
	getInput(&second_blank,4);
	ST7735_SetCursor(0,5);
	ST7735_OutString("First Blank:");
	int third_blank = 0;
	getInput(&third_blank,6);
	ST7735_FillScreen(0x000);
	ST7735_SetCursor(0,0);
	ST7735_OutString("Y-axis vs. X-axis");
	int status1 = GPIO_PORTB_DATA_R & 0x80;
	int i = 0;
	while(status1 != 0x80)
	{
		
		int f = first_blank * i * i;
		int d = second_blank * i;
		int sum = f + d + third_blank;
		i++;
		ST7735_PlotPoint(sum);
	  ST7735_PlotNext();
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
	
	
	
}
	