/*С��׼���μ�ѧУ��֯�Ĵ���, ����ǰС��׼����������װ��һЩ��ʳ, С���ı�������Ϊw�� 
С������һ����n����ʳ, ��i����ʳ���Ϊv[i]�� 
С����֪������������������������������,��һ���ж�������ʳ�ŷ�(�����Ϊ0Ҳ��һ�ַŷ�)�� 

��������:
�����������
��һ��Ϊ����������n��w(1 <= n <= 30, 1 <= w <= 2 * 10^9),��ʾ��ʳ�������ͱ�����������
�ڶ���n��������v[i](0 <= v[i] <= 10^9),��ʾÿ����ʳ�������

�������:
���һ��������, ��ʾС��һ���ж�������ʳ�ŷ���
ʾ��1 
����
3 10
1 2 4
���
8
˵��
������ʳ�����С��10,����ÿ����ʳ�з���Ͳ��������������һ����2*2*2 = 8�������
*/ 

#include<stdio.h>
#define MAX_NUM 1024
int main()
{
	int n = 0;//number
	int w = 0;//weight
	int i = 0;
	int count = 0;//count
	
	int v[MAX_NUM] = {0};
	
	printf("please input number and weight:\n");
	
	scanf("%d %d", &n, &w);
	
	if(n>=1&&n<=30)
	{
		;
	}
	else
	{
		return 0;
	}
	
	printf("please input weights:\n");
	while(i<n)
	{
		scanf("%d",&v[i]);
		i++;
	}
	
	int m = 1;
	i = 0;
	while(i<n)
	{
		m = m * 2;
		i++;
	}
	
	int weight = 0;
	int j = 0;
	
	int h = 0;
	int l = 0;
	i = 0;
	
	while(i<m)
	{
		l = i;
		for(j = 0; j<n; j++)
		{
			
			h = i%2;
			i = i/2;
			if(h == 1)
			{
				weight = weight + v[j];
			}
		}
		
		if(weight <= w)
		{
			count++;
		}
		i = l+1;
		
		printf("(%d\t%d\t)", l,weight);
		weight = 0;
	}
	
	printf("\n%d", count);
	return 0;
 } 


