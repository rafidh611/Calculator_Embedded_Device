#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "ST7735.h"
#include "Print.h"
#include "PLL.h"

int input1[10];
int input2[10];

int arr[10][3]=
{
	{0,1,0},
	{0,2,1},
	{0,4,2},
	{0,8,3},
	{0,16,4},
	{0,32,5},
	{1,1,6},
	{1,2,7},
	{1,4,8},
	{1,8,9}
};



void Multiplication(int x[],int index1, int y[], int index2);

void Division(int x[],int index1, int y[], int index2);

void Addition(int x[],int index1, int y[], int index2);

void Subtraction(int x[],int index1, int y[], int index2);

void Graphing();



	

