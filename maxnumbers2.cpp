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
	int i = 0;
	
	int number = 0;
	int num = 0;
	
	scanf("%d", &number);
	while(==1)
	{
		if(number>0)
		num = num + number;
		i++;
	}
	
	printf("%d",num);
	
	return 0;
	
}
 
