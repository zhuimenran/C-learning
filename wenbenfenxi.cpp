#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define address "data.dat"
using namespace std;
typedef struct _word
{
	char* a;
	int count;
	struct _word* next;
}word;

word* h;
word* max, *mid, *min;
int i = 0;

void find(word*head, char* words)
{
	word*  last;
	last = head;
	int len = 0;
	char ascii;
	words = _strlwr(words);
	len = strlen(words);
	ascii = words[len - 1];
	if (ascii < 97 || ascii>122)
	{
		words[len - 1] = NULL;
	}
	if (last == NULL||last->a==NULL)
	{
		if (i == 0)
		{
			last = (word*)malloc(sizeof(word));
			h = last;
			i++;
		}
		last->a = (char*)malloc(20 * sizeof(char));
		last->next = (word*)malloc(sizeof(word));
		last->next->a = NULL;
		strcpy(last->a, words);
		last->count = 1;
		last = last->next;
	}
	else if (strcmp(last->a, words) == 0)
	{
		last->count++;
	}
	else
	{
		last = last->next;
		find(last, words);
	}
}

void sort(word* head)
{
	word* last;
	last = head;
	if (last != NULL&&last->next!=NULL)
	{
		if (last->count > max->count)
		{
			max = last;
			last = last->next;
			sort(last);
		}
		else if (last->count > mid->count&&last->count <= max->count)
		{
			mid = last;
			last = last->next;
			sort(last);
		}
		else if (last->count > min->count&&last->count <= mid->count)
		{
			min = last;
			last = last->next;
			sort(last);
		}
		else
		{
			last = last->next;
			sort(last);
		}
	}
}

int main(void)
{
	time_t start;
	time(&start);
	time_t end;
	max = (word*)malloc(sizeof(word));
	mid = (word*)malloc(sizeof(word));
	min = (word*)malloc(sizeof(word));
	max->count = 0;
	mid->count = 0;
	min->count = 0;
	char* words = (char*)malloc(20 * sizeof(char));
	FILE *fp;
	if ((fp = fopen(address, "rb")) == NULL)
	{
		printf("文件打开失败\n");
	}
	do
	{
		if (feof(fp) == 0)
		{

			if (fscanf(fp, "%s",words) == -1)
			{
				printf("error, 文件读取完毕\n");
			}
			find(h, words);
		}
		else
		{
			break;
		}
	} while (true);
	sort(h);
	printf("使用最多的单词是：%s\n", max->a);
	printf("使用次数为：%d\n", max->count);
	printf("使用第二多的单词是：%s\n", mid->a);
	printf("使用次数为：%d\n", mid->count);
	printf("使用第三多的单词是：%s\n", min->a);
	printf("使用次数为：%d\n", min->count);
	fclose(fp);
	printf("\n所使用时间：\n");
	time(&end);
	printf("%f\n", difftime(end, start));
	getchar();
	getchar();
	return 0;
}

