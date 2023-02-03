#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
struct node
{
	int num;
	struct node* next;
};
struct node* create()
{
	int n = 0;
	struct node* p1, * p2, * head;
	int i;
	int randomIndex;

	head = NULL;

	while (n == 0)         //�����ĳ������
		n = ((int)rand()) % 20;

	for (i = 0; i < n; i++)
	{
		p1 = (struct node*)malloc(sizeof(struct node));
		p1->next = NULL;
		p1->num = ((int)rand());  //ÿ�ڵ��������
		if (i == 0)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
	}

	if (head != NULL)  //������Ϊ��ʱ������ɻ�
	{
		randomIndex = ((int)rand()) % n;  //����ɻ��Ľڵ�
		p2 = head;
		for (i = 0; i < randomIndex; i++)
			p2 = p2->next;
		p1->next = p2;
	}

	return head;
}
void openloop(struct node* List)
{
	unsigned int IsFinded = 0;
	int i = 0;
	int Count = 0;
	int Counter = 0;
	struct node* ToFind;
	struct node* Current;
	ToFind = List;
	for (i = 0; IsFinded == 0; i++)
	{
		Count = 0;
		Counter = 0;
		Current = List;
		while (Count < 20)
		{
			if ((Current->next) == ToFind && Counter == 1)
			{
				IsFinded = 1;
				Current->next = NULL;
				break;
			}
			else if((Current->next) == ToFind && Counter < 1)
			{
				Counter++;
			}
			Current = Current->next;
			Count++;
		}
		ToFind = ToFind->next;
	}
}
void print(struct node* List)
{
	struct node* Current;
	Current = List;
	while (Current != NULL)
	{
		printf("%d -> ", Current->num);
		Current = Current->next;
	}
	printf("NULL");
}
void main()
{
	struct node* head;
	srand(time(NULL));
	head = create();
	openloop(head);
	print(head);
}