#include<stdio.h>
#define MAX_NUM 100
int main(int argc, char **argv)
{
	int number[MAX_NUM]= {0};//全部赋值为0 
	int i = 0;
	
	for(i=0; i<MAX_NUM; i++)
	{
		printf("%4d", number[i]);
	}
	
	return 0;
}
