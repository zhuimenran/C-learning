//time:2017.5.5
//name:海波
//实现超长整数的四则运算
//error；对地址操作会无意间改变数值，从而得出错误结果
//2017.5.7
//第三次修改
//完成 

//增加说明
// there is a question with division
//*************************************************************

#include<stdio.h>
#include<windows.h>

void Print_out();
char * Add(char * a, char * b); 
char * Div(char * a, char * b);
char * Sub(char * a, char * b);
char * Mul(char * a, char * b);
char * change_order(char * out);

#define COUNTS 100

int main(int argc, char *argv[])
{
	char input_number1[COUNTS+1]={'\0'};
	char input_number2[COUNTS+1]={'\0'};
	char *output_number;
	char operator_char;
	int choice = 0;
	
	do{
		Print_out();
		printf("please input the first number:");
		scanf("%s", input_number1);
		getchar();
		printf("please input the operator:");
		scanf("%c", &operator_char);
		getchar(); 
		printf("please input the second number:");
		scanf("%s", input_number2);
	

		switch(operator_char)
		{
			case '+': output_number = Add(input_number1, input_number2); break;
			case '-': output_number = Sub(input_number1, input_number2); break;
			case '*': output_number = Mul(input_number1, input_number2); break;
			case '/': output_number = Div(input_number1, input_number2); break;
			default : printf("Input error!"); break;
		}
		
		printf("The Result is:");
		printf("%s", output_number);
		
		printf("\n Are you contuin? 1-yes or 2-no:");
		scanf("%d", &choice);
		system("cls");//清屏 
		
	}while(choice == 1);
	
	return 0;	
 } 
 
 void Print_out()
 {
 	printf("--------Welcome to the calculator----------\n");
 	printf("********************************************\n");
 	
 	return;
 }
 
 char * Add(char *a, char *b)
 {
 	int add1[COUNTS] = {0};
	int add2[COUNTS] = {0};
	int sum[COUNTS + 1] = {0};
	
	int i = 0;
	int j = 0;
	int asd = 0;
	int he = 0;
	int temp = 0;
	int m = 0;
	int n = 0;
	int jia = 0;

	//处理add1(char->int)	
	i = 0; 
	while(a[i]!='\0')
	{
		add1[i]=a[i]-'0';
		i++;
	}
	m=i;// 赋值 (m的值为 add1的位数) 
	
	j = 0;
	while(i>j)//使个位在add[0]上 
	{
	temp=add1[i-1];
	add1[i-1]=add1[j];
	add1[j]=temp;
	i--;
	j++;
    }
    
	//处理add2 
	j = 0;
	while(b[j]!='\0')
	{
		add2[j] = b[j]-'0';
		j++;
	}
	n = j;
	
	i = 0;
	while(j>i)
	{
	temp=add2[j-1];
	add2[j-1]=add2[i];
	add2[i]=temp;
	j--;
	i++;
    }

	//加法实现    
    i=0;
    asd=0;//(asd为进位的标值)
	while(i <= m||i <= n)
	{
	   he=add1[i]+add2[i]+ asd;
		if(he>9)
		{
	  		jia=he-10;
			sum[i]=jia;		   
			asd=1;
	   }
	   else 
	   {
			jia=he;
			asd=0;
			sum[i] = jia;
			asd = 0	;
		}
	i++;
	}
	
	//处理输出，将int转为char	
	if(sum[i-1]!=0)
	{
		a[i-1] = sum[i-1] + '0';
	}
	while(i>=2)
	{
		a[i-2] = sum[i-2] + '0';
		i=i-1;
	}
	
	a = change_order(a);
	
	return a;
}

char * change_order(char * out)
{
	int i = 0;
	int j = 0;
	char temp = 0;
	
	while(out[j]!='\0')
	{
		j++;
	}
	
	while(j>i)
	{
	temp=out[j-1];
	out[j-1]=out[i];
	out[i]=temp;
	j--;
	i++;
    }
    
    return out;
} 

//加法 

char * Sub(char * a, char * b)
{
	int add1[COUNTS] = {0};
	int add2[COUNTS] = {0};
	int sum[COUNTS + 1] = {0};
	
	int i = 0;
	int j = 0;
	int asd = 0;
	int he = 0;
	int temp = 0;
	int m = 0;
	int n = 0;
	int jia = 0;
	//str->int(a)
	while(a[i]!='\0')
	{
		add1[i]=a[i]-'0';
		i++;
	}
	m=i;//m代表位数 

	j = 0;
	while(i>j)
	{
		temp=add1[i-1];
		add1[i-1]=add1[j];
		add1[j]=temp;
		i--;
		j++;
    }
    
	j=0;
	while(b[j]!='\0')
	{
		add2[j]=b[j]-'0';
		j++;
	}
	n=j;
	
	i = 0;
	while(j>i)
	{
		temp=add2[j-1];
		add2[j-1]=add2[i];
		add2[i]=temp;
		j--;
		i++;
    }
    //个位的索引值为0； 
    i=0;
    asd=0;

	while(i<m||i<n)	
	{
	    he=add1[i]-add2[i]+asd;
		if(he<0)
		{
	  		jia=he+10;
	  		sum[i]=jia;
			asd=-1;
		}
		else
	   {
	   		jia=he;
			asd=0;
			sum[i]=jia;  
		}
		
		i++;
	}
	//i=max(m,n); 
	if(sum[i-1]!=0)
	{
		a[i-1] = sum[i-1] + '0';
	}
	else
	{
		a[i-1] = '\0';
	}
	while(i>=2)
	{
		a[i-2] = sum[i-2] + '0';
		i=i-1;
	}
	
	a = change_order(a);
	
	return a;
}

char * Mul(char * a, char * b)
{
	int add12[COUNTS+1] = {0};
	char add13[COUNTS]= {0};
	char c[COUNTS+1] = {'\0'};
	
	int i = 0;
	int m = 0;
	int j = 0;
	int x = 0;
	int n = 0;
	int temp = 0;
	int v = 0;
	
	while(b[j]!='\0')
	{
		c[j] = b[j];
		j++;
	}
	
	n = j;
	
	i = 0; 
	while(a[i]!='\0')
	{
		add12[i]=a[i]-'0';
		i++;
	}
	m=i;// 赋值
	j = 0;
	while(i>j)
	{
		temp=add12[i-1];
		add12[i-1]=add12[j];
		add12[j]=temp;
		i--;
		j++;
    }
    
    
	
	i=0;
	while(i<m)
	{
		if(add12[i] == 0)
		{
			if(i == 0)
			{
				while(v < COUNTS)
				{
					a[v] = '\0';
					v ++;
				}
				a[0] = 0;
			}
			//else: a 不变 
		}
		else
		{
			if(add12[i] == 1)
			{
				if(i == 0)
				{
					x = 0;
					while(b[x]!= '\0')//改了a[]->b[] 
		 			{
		 				a[x] = b[x];
		 				x++;
		 			}
				}
				else
				{
					a = Add(c, b);
				}	
			}
		 	else
		 	{
		 		if(i==0)
		 		{
		 			for(j=1;j<add12[i]; j++)
					{
						if(j == 1)
						{
							a = Add(c,b);	
						}
						else
						{
							a = Add(a, b);
						}
					}
		 		}
		 		else
		 		{
		 			for(j=1;j<=add12[i]; j++)
					{
						a = Add(a, b);
					}
		 		}
	 		}
		}
		
	 	b[n] = '0';//进位 
	 
	 	x = 0;
	 	if(add12[0]==0)
	 	{
	 		while(b[j]!='\0')
			{
				c[j] = b[j];
				j++;
			}	
		}
		else
		{
			while(a[x]!= '\0')
	 		{
	 			c[x] = a[x];
	 			x++;
		 	}	
		}
	 	
	 	n++;
	 	i++;
	}
	//增加了下面的代码，解决进位的bug,运行第一次无错误，第二次就有错了，error:会多进一为
	//本来230，会变成2300 
	i = 0;
	while(b[i]!='\0')
	{
		b[i] = '\0';
		i++;
	}
	
	return a;
}

char * Div(char * a, char * b)
{
	char add11[COUNTS+1] = {'\0'};
	char add12[COUNTS]= {'\0'};
	char c[COUNTS+1] = {'\0'};
	add11[0] ='1';
	add12[0] ='0';
	char add1[COUNTS] ={'\0'};
	char d[COUNTS] = {'\0'};
	
	char *add;
	char *adds;
	int i = 0;
	
	while(b[i]!='\0')
	{
		d[i] = b[i];
		i++;
	}
	
	add  =Add(add12, add11);
	
	printf("%s\n", add);
	
	i = 0;
	while(add[i]!= '\0')
	{
		add1[i] = add[i];
		i++;
	}
	
	adds = Mul(b, add);
	
	while(strcmp(adds, a) < 0)
	{
		i = 0;
		while(add1[i]!= '\0')
		{
			add[i] = add1[i];
			i++;
		}
		
		add  =Add(add, add11);
		i = 0;
		while(add[i]!= '\0')
		{
			add1[i] = add[i];
			i++;
		}
		adds = Mul(b, add);
		
		i = 0;
		while(b[i]!='\0')
		{	
			d[i] = b[i];
			i++;
		}
	}
	if(strcmp(adds, a) == 0)
	{
		i = 0;
		while(add[i]!= '\0')
		{
			a[i] = add[i];
			i++;
		}
	}
	else
	{
		add = Sub(add, add11);
		adds = Mul(add, b);
		
		a = Sub(a, adds);
		
		i = 0;
		while(a[i] != '\0')
		{
			a[i] = add[i];
			i++;
		}
		a[i]= '0';
	}
	
	return a;
}
