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

//这个问题没有完全解决，主要是输入的形式不对
#include<stdio.h>
//#define MAX_NUMBER_COUNT 100
int main(int argc, char **argv)
{
	//to storage number
	//int number[MAX_NUMBER_COUNT] = {0};
	
	//to count the numbers
	int i = 0;
	
	int number = 0;
	int num = 0;
	
	while(scanf("%d", &number)==1)
	{
		if(number>0)
		num = num + number;
		i++;
	}
	
	printf("%d",num);
	
	return 0;
	
}
 
