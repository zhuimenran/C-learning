//time：2018.4.13
//name:taoxiaobo 
//问题描述 
/**
	输入一组整数，求出这组数字子序列和中的最大值，只要求出最大子序列的和，不必求出最大值对
应的序列。

    最大子序列和：整数序列A1， A2，... An （可能有负数），求A1~An的一个子序列Ai~Aj，使得Ai到Aj的和最大。

例如：

序列：-2, 11, -4, 13, -5, 2, -5, -3, 12, -9，则最大子序列和为21。

序列：0, -3, 6, 8, -20, 21, 8, -9, 10, -1, 3, 6, 5，则最大子序列和为43。
*/
#include<stdio.h>
//#define MAX_NUMBER_COUNT 100
int main(int argc, char **argv)
{
	//to storage number
	//int number[MAX_NUMBER_COUNT] = {0};
	
	//to count the numbers
	
	int temp = 1;
	int number2 = 0;
	char number[10];
	
	char *s;
	int i = 0;
	int num = 0;
	
	scanf("%s", s);
	printf("%d" ,1+2);
	printf("%s", s);
	printf("%d", 2+2);
	
	while((*++s)!='\0')
	{
		i = 0;
		while((*s++)!='\n')
		{
			number[i] = *s;
			i++;
			temp = temp * 10;
		}
		
		if(number[0] !='-')
		{
			while(i>0)
			{
				temp = temp/10;
				number2 = number2 +(number[i-1]-'0')*temp;
				i--;
			}
			
			num = num + number2;
		}
		else
		{
			while(i>1)
			{
				temp = temp/100;
				number2 = number2 +(number[i-2]-'0')*temp;
				i--;
			}
			
			num = num - number2;	
		}
		
		temp = 1;
	}
	
	printf("%d",num);
	
	return 0;
	
}
 
