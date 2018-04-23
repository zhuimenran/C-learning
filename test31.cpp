/*小明准备参加学校组织的春游, 出发前小明准备往背包里装入一些零食, 小明的背包容量为w。 
小明家里一共有n袋零食, 第i袋零食体积为v[i]。 
小明想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。 

输入描述:
输入包括两行
第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10^9),表示零食的数量和背包的容量。
第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积。

输出描述:
输出一个正整数, 表示小明一共有多少种零食放法。
示例1 
输入
3 10
1 2 4
输出
8
说明
三种零食总体积小于10,于是每种零食有放入和不放入两种情况，一共有2*2*2 = 8种情况。
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


