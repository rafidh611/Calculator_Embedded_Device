
#include "Operations.h"

//0-5 : PE0-PE5
//6-9 : PD0-PD3

//Operations : PB0 - PB6

//PB7: Done Button to say you are done with pressing a number


//int operations[5];


void clearInputsArr()
{
	for(int i = 0; i < 10 ; i++)
	{
		input1[i] = 0;
		input2[i]= 0;
	}
}


void set_InputButtons()
{
	SYSCTL_RCGCGPIO_R |= 0X0E;
	volatile int bob;
	bob++;
	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_DIR_R &= 0x00;
	GPIO_PORTD_DEN_R |= 0x0F;
	GPIO_PORTD_DIR_R |= 0x00;
	GPIO_PORTE_DEN_R |= 0x3F;
	GPIO_PORTE_DIR_R |= 0x00;
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

//look at Port D and E for numbers
void getInput(int* index1,int* index2)
{
	int index = 0;
	int j = 0;
	ST7735_SetCursor(0,3);
	ST7735_OutString("Input 1:");
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
				ST7735_SetCursor(j,4);
	      LCD_OutDec(x);
				j++;
			}
			if(get2 != 0)
			{
				int y = Converter(1,get2);
				input1[index]=y;
				index++;
				ST7735_SetCursor(j,4);
	      LCD_OutDec(y);
				j++;
				
			}
		}
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
	
	status1 = GPIO_PORTB_DATA_R & 0x80;
	*index1 = index;
	index = 0;
	j = 0;
	ST7735_SetCursor(0,5);
	ST7735_OutString("Input 2:");
	
	while(status1 != 0x80)
	{
		int get1 = GPIO_PORTE_DATA_R & 0x7F;
		int get2 = GPIO_PORTD_DATA_R & 0x0F;
		if(get1 != 0 | get2 != 0)
		{
			if(get1 != 0)
			{
				int x = Converter(0,get1);
				input2[index]=x;
				index++;
				ST7735_SetCursor(j,6);
	      LCD_OutDec(x);
				j++;
				
			}
			if(get2 != 0)
			{
				int y = Converter(1,get2);
				input2[index]=y;
				index++;
				ST7735_SetCursor(j,6);
	      LCD_OutDec(y);
				j++;
				
			}
		}
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
	*index2 = index;
	
	
}
//look at Port B for Operation
int getOperation()
{
	//while B7 not pressed keep going
	int status1 = GPIO_PORTB_DATA_R & 0x80;
	
	while(status1 != 0x80)
	{
		int get = GPIO_PORTB_DATA_R & 0x7F;
		if(get != 0)
		{
			if(get == 1)
			{
				ST7735_SetCursor(0,1);
	      ST7735_OutString("Add");
				
			}
			else if(get == 2)
			{
				ST7735_SetCursor(0,1);
	      ST7735_OutString("Subtract");
				
			}
			else if(get == 4)
			{
				ST7735_SetCursor(0,1);
	      ST7735_OutString("Multiply");
			}
			else if(get == 8)
			{
				ST7735_SetCursor(0,1);
	      ST7735_OutString("Divide");
			}
			else if(get == 16)
			{
				ST7735_SetCursor(0,1);
	      ST7735_OutString("Graph");
				
			}
			else if(get == 32)
			{
				ST7735_SetCursor(0,1);
	      ST7735_OutString("Differentiate");
				
			}
			else if(get == 64)
			{
				ST7735_SetCursor(0,1);
	      ST7735_OutString("Integrate");
			}
			return get;
		}
		status1 = GPIO_PORTB_DATA_R & 0x80;
	}
}

int main()
{
	ST7735_InitR(INITR_REDTAB);
	ST7735_FillScreen(0x000);
	ST7735_SetCursor(5,0);
	ST7735_OutString("Hello!");
	volatile int u;
	u++;
	u++;
	u++;
	u++;
	u++;
	ST7735_SetCursor(2,1);
	ST7735_OutString("Welcome to the Awesome Calculator");
	u++;
	u++;
	u++;
	u++;
	u++;
	while(1)
	{
	clearInputsArr();
	//clearOperationsArr();
	ST7735_FillScreen(0x000);
	ST7735_SetCursor(0,0);
	ST7735_OutString("Press Button for the Operation you want!");
	int y = getOperation();
	int flag = 0;
	if(y == 16)
	{
		Graphing();
		flag = 1;
	}

	ST7735_FillScreen(0x000);
	if(flag == 1)
	{
		ST7735_SetCursor(0,0);
	  ST7735_OutString("Press Button for the Operation you want!");
		flag = 0;
	}
	ST7735_SetCursor(0,2);
	ST7735_OutString("Press Button for the Inputs you want!");
	int index1 = 0;
	int index2 = 0;
	getInput(&index1,&index2);
	
	
    if(y == 1)
		{
			Addition(input1,index1,input2,index2);
			clearInputsArr();
		}
		if(y == 2)
		{
			Subtraction(input1,index1,input2,index2);
			clearInputsArr();
		}
		if(y == 4)
		{
			Multiplication(input1,index1,input2,index2);
			clearInputsArr();
		}
		if(y == 8)
		{
			Division(input1,index1,input2,index2);
			clearInputsArr();
		}
		
		
		
		
	
}
	
}