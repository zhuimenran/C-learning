//time��2018.4.13
//name:taoxiaobo 
//�������� 
/**
	����һ������������������������к��е����ֵ��ֻҪ�����������еĺͣ�����������ֵ��
Ӧ�����С�

    ��������кͣ���������A1�� A2��... An �������и���������A1~An��һ��������Ai~Aj��ʹ��Ai��Aj�ĺ����

���磺

���У�-2, 11, -4, 13, -5, 2, -5, -3, 12, -9������������к�Ϊ21��

���У�0, -3, 6, 8, -20, 21, 8, -9, 10, -1, 3, 6, 5������������к�Ϊ43��
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
 
