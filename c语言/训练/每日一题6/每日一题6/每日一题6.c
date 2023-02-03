#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode
{
	int Data;
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;
LinkedList CreateLinkedListR(int Count)//链表的创建
{
	LinkedList Res;
	LNode* Head;
	LNode* End;
	LNode* New;
	Head = (LNode*)malloc(sizeof(LNode));
	Head->Next = NULL;
	End = Head;
	while (Count-- > 0)
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->Next = End->Next;
		End->Next = New;
		End = New;
	}
	Res = Head->Next;
	free(Head);
	return Res;
}
LNode* GetNode(LinkedList List, unsigned int ZeroBasedIndex)
{
	unsigned int Index = 0;
	LNode* Current;
	Current = List;
	while (Index < ZeroBasedIndex && Current != NULL)
	{
		Current = Current->Next;
		Index++;
	}
	return Current;
}
int GetLNodeData(LinkedList List, int Index)
{
	LNode* Current;
	Current = List;
	while (Index-- > 0)
	{
		Current = Current->Next;
	}
	return Current->Data;
}
LinkedList AddLNode(LinkedList* List, int Index, int Data)
{
	LNode* Prev = NULL;
	LNode* New = NULL;
	LNode Temp;
	if (List == NULL)
	{
		return NULL;
	}
	Temp.Next = *List;
	Prev = (Index == 0) ? (&Temp) : GetNode(*List, Index - 1);
	if (Prev != NULL)
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->Data = Data;
		New->Next = Prev->Next;
		Prev->Next = New;
	}
	*List = Temp.Next;
	return New;
}
LinkedList DeleteLNode(LinkedList* List, int Index)
{
	LNode* Prev = NULL;
	LNode* ToDelete = NULL;
	LNode Temp;
	if (List == NULL)
	{
		return NULL;
	}
	Temp.Next = *List;
	Prev = &Temp;
	Prev = (Index == 0) ? (&Temp) : GetNode(*List, Index - 1);
	ToDelete = Prev->Next;
	if (Prev != NULL && ToDelete != NULL)
	{
		Prev->Next = ToDelete->Next;
		free(ToDelete);
	}
	*List = Temp.Next;
	return Prev->Next;
}
void SwichLNode(LinkedList* List, int Index1, int Index2)
{
	LNode* Head = NULL;
	Head = (LNode*)malloc(sizeof(LNode));
	Head->Next = *List;
	LNode* PreSwich1 = NULL;
	LNode* PreSwich2 = NULL;
	LNode* AfterSwich1 = NULL;
	LNode* AfterSwich2 = NULL;
	LNode* Swich1 = NULL;
	LNode* Swich2 = NULL;
	if (Index1 == 0)
	{
		PreSwich1 = Head;
		PreSwich2 = GetNode(*List, Index2 - 1);
		Swich1 = *List;
		Swich2 = GetNode(*List, Index2);
		AfterSwich1 = GetNode(*List, Index1 + 1);
		AfterSwich2 = GetNode(*List, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	else if (Index2 == 0)
	{
		PreSwich1 = GetNode(*List, Index1 - 1);
		PreSwich2 = Head;
		Swich1 = GetNode(*List, Index1);
		Swich2 = *List;
		AfterSwich1 = GetNode(*List, Index1 + 1);
		AfterSwich2 = GetNode(*List, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	else if (Index1 == Index2 + 1 || Index2 == Index1 + 1)
	{
		if (Index1 < Index2)
		{
			PreSwich1 = GetNode(*List, Index1 - 1);
			PreSwich2 = GetNode(*List, Index1);
			Swich1 = GetNode(*List, Index1);
			Swich2 = GetNode(*List, Index2);
			AfterSwich1 = GetNode(*List, Index2);
			AfterSwich2 = GetNode(*List, Index2 + 1);
			PreSwich1->Next = Swich2;
			Swich2->Next = Swich1;
			Swich1->Next = AfterSwich2;
		}
		else
		{
			PreSwich1 = GetNode(*List, Index2);
			PreSwich2 = GetNode(*List, Index2 - 1);
			Swich1 = GetNode(*List, Index1);
			Swich2 = GetNode(*List, Index2);
			AfterSwich1 = GetNode(*List, Index1 + 1);
			AfterSwich2 = GetNode(*List, Index1);
			PreSwich2->Next = Swich1;
			Swich1->Next = Swich2;
			Swich2->Next = AfterSwich1;
		}
	}
	else
	{
		PreSwich1 = GetNode(*List, Index1 - 1);
		PreSwich2 = GetNode(*List, Index2 - 1);
		Swich1 = GetNode(*List, Index1);
		Swich2 = GetNode(*List, Index2);
		AfterSwich1 = GetNode(*List, Index1 + 1);
		AfterSwich2 = GetNode(*List, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	*List = Head->Next;
	free(Head);
}
void PrintLNode(LinkedList List)
{
	LNode* ToPrint = NULL;
	ToPrint = List;
	if (List == NULL)
	{
		printf("\n");
	}
	else
	{
		while (ToPrint != NULL)
		{
			printf("%d ", ToPrint->Data);
			ToPrint = ToPrint->Next;
		}
		printf("\n");
	}
}
int main(int argc, char* argv[])
{
	unsigned int Total = 0;
	LinkedList List = NULL;
	scanf("%u", &Total);
	getchar();
	for (unsigned int i = 0; i < Total; i++)
	{
		char Process = '\0';
		Process = getchar();
		if (Process == 'G')
		{
			int G = 0;
			scanf("%d", &G);
			int Data = GetLNodeData(List, G);
			printf("%d\n", Data);
			getchar();
		}
		else if (Process == 'A')
		{
			int Index = 0;
			int Data = 0;
			scanf("%d%d", &Index, &Data);
			AddLNode(&List,Index, Data);
			getchar();
		}
		else if (Process == 'P')
		{
			PrintLNode(List);
			getchar();
		}
		else if (Process == 'D')
		{
			int Index = 0;
			scanf("%d", &Index);
			DeleteLNode(&List, Index);
			getchar();
		}
		else if (Process == 'S')
		{
			int Index1 = 0;
			int Index2 = 0;
			scanf("%d%d", &Index1, &Index2);
			SwichLNode(&List, Index1, Index2);
			getchar();
		}
	}
	return 0;
}