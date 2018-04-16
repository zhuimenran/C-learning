/*
*设计一个一元稀疏多项式简单计算器，要求基本功能：
*（1）输入并建立多项式
*（2）输出多项式
*（3）两个多项式相加
*（4）两个多项式相减
*/
//time :2017.10.15
//name: taoxiaobo
#include<stdio.h>
#include<stdlib.h>
struct Number
{
	double coef;
	int index;
	struct Number *next;
};
/*
*输入 
*/
struct Number *InputNumber(struct Number *head)
{
	struct Number *ptr1 = NULL;
	struct Number *ptr2 = NULL;
	double Coef = 0;
	int Index = 0;
	char ch;
	char sh;//抵消scanf()输入字符的 缺陷 
	
	ch = 'w';
	while(ch != 'q')
	{
		printf("please input number:");
		scanf("%lf\t%d",&Coef,&Index);
		ptr2 = (struct Number *)malloc(sizeof(struct Number));
		if(head == NULL)
		{
			head = ptr2;
		}
		else
		{
			ptr1->next = ptr2;
		}
		ptr2->next = NULL;//
		ptr2->coef = Coef;
		ptr2->index = Index;
		
		ptr1 = ptr2;
		
		printf("q to qiut:");
		scanf("%c", &sh);
		scanf("%c", &ch);
	}
	
	return head;
}

void PrintNumber(struct Number *head)
{
	struct Number *ptr1 = NULL;
	ptr1 = head;
	while(ptr1 != NULL)
	{
		if(ptr1->next == NULL)
		{
			printf("%lfe%d\n",ptr1->coef ,ptr1->index );
		}
		else
		{
			printf("%lfe%d+",ptr1->coef ,ptr1->index );
		}
		ptr1 = ptr1->next;
	}
	return;
}

struct Number *Add(struct Number *head,struct Number *head1) 
{
	struct Number *ptr1 = NULL;
	struct Number *ptr2 = NULL;
	struct Number *ptr3 = NULL;
	struct Number *ptr4 = NULL;
	
	ptr1 = head;
	ptr2 = head1;
	if(head->index >= head1->index)
	{
		while(ptr1!=NULL&&ptr2!=NULL)
		{
			if(ptr1->index == ptr2->index )
			{
				ptr1->coef = ptr1->coef + ptr2->coef ; 
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			else
			{
				if(ptr1->index>ptr2->index)
				{
					ptr1=ptr1->next;
				}
				else
				{
					ptr4 = ptr2->next ;
					ptr2->coef = ptr2->coef + ptr1->coef ;
					ptr1->next = ptr2;
					ptr2->next = ptr1;
				
					ptr2 = ptr4;
				}
			} 
		}
	}
	else
	{
		head = ptr2;
		while(ptr1!=NULL&&ptr2!=NULL)
		{
			if(ptr2->index == ptr1->index )
			{
				ptr2->coef = ptr2->coef + ptr1->coef ; 
				ptr1 = ptr1->next;
				ptr2 = ptr2->next; 
			}
			else
			{
				if(ptr2->index>ptr1->index)
				{
					ptr2=ptr2->next;
				}
				else
				{
					ptr3 = ptr1->next ;
					ptr1->coef = ptr1->coef + ptr2->coef ;
					ptr2->next = ptr1;
					ptr1->next = ptr2;
				
					ptr1 = ptr3;
				}
			}	
		}
	}
	return head;
}
struct Number *Sub(struct Number *head,struct Number *head1) 
{
	struct Number *ptr1 = NULL;
	struct Number *ptr2 = NULL;
	struct Number *ptr3 = NULL;
	struct Number *ptr4 = NULL;
	
	ptr1 = head;
	ptr2 = head1;
	if(head->index >= head1->index)
	{
		while(ptr1!=NULL&&ptr2!=NULL)
		{
			if(ptr1->index == ptr2->index )
			{
				ptr1->coef = ptr1->coef - ptr2->coef ; 
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			else
			{
				if(ptr1->index>ptr2->index)
				{
					ptr1=ptr1->next;
				}
				else
				{
					ptr4 = ptr2->next ;
					ptr2->coef = ptr2->coef - ptr1->coef ;
					ptr1->next = ptr2;
					ptr2->next = ptr1;
				
					ptr2 = ptr4;
				}
			} 
		}
	}
	else
	{
		head = ptr2;
		while(ptr1!=NULL&&ptr2!=NULL)
		{
			if(ptr2->index == ptr1->index )
			{
				ptr2->coef = ptr1->coef - ptr2->coef ; 
				ptr1 = ptr1->next;
				ptr2 = ptr2->next; 
			}
			else
			{
				if(ptr2->index>ptr1->index)
				{
					ptr2->coef = -(ptr2->coef);
					ptr2=ptr2->next;
				}
				else
				{
					ptr3 = ptr1->next ;
					ptr1->coef = ptr1->coef - ptr2->coef ;
					ptr2->next = ptr1;
					ptr1->next = ptr2;
				
					ptr1 = ptr3;
				}
			}	
		}
	}
	return head;
}
int main()
{
	struct Number *head = NULL;
	struct Number *head1 = NULL;
	char sh;
	char ch;
	
	printf("input the one:\n");
	head = InputNumber(head);
	PrintNumber(head);

	printf("input the second:\n");
	head1 = InputNumber(head1);
	PrintNumber(head1);
	
	printf("please input the operator:");
	scanf("%c", &sh);
	scanf("%c", &ch);
	if(ch == '+')
	{
		head = Add(head,head1);
	}
//	
	if(ch == '-')
	{
		head = Sub(head, head1);
	}
//	
	PrintNumber(head);
	
	return 0;
}
