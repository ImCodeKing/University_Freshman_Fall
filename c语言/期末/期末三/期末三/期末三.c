#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tagLNode
{
	char Code[5];
	char Class;
	int Height;
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;
LinkedList MyCreate()
{
	LinkedList Res;
	LNode* Head;
	LNode* New;
	LNode* End;
	int IsFirst = 1;
	unsigned int IsCycle = 1;
	Head = (LNode*)malloc(sizeof(LNode));
	Head->Next = NULL;
	End = Head;
	while (IsCycle == 1)
	{
		New = (LNode*)malloc(sizeof(LNode));
		scanf("%s %c%d", &New->Code, &New->Class, &New->Height);
		if (strcmp(New->Code, "0000") == 0)
		{
			IsCycle = 0;
			break;
		}
		New->Next = End->Next;
		End->Next = New;
		End = New;
	}
	Res = Head->Next;
	free(Head);
	return Res;
}
void MyPrint(LinkedList List)
{
	LNode* Current;
	Current = List;
	while (Current != NULL)
	{
		if (Current->Next != NULL)
		{
			printf("(%s %c %d)->", Current->Code, Current->Class, Current->Height);
		}
		else
		{
			printf("(%s %c %d)", Current->Code, Current->Class, Current->Height);
		}
		Current = Current->Next;
	}
}
void MyFree(LinkedList* PtrOfList)//销毁链表
{
	LNode* Current = NULL;
	unsigned int IsListEmpty = 0;
	if (*PtrOfList == NULL)
	{
		IsListEmpty = 1;
	}
	if (PtrOfList == NULL || IsListEmpty)
	{
		return;
	}
	Current = (*PtrOfList);
	while (Current != NULL)
	{
		(*PtrOfList) = Current->Next;
		free(Current);
		Current = (*PtrOfList);
	}
}
unsigned int LinkedListLength(LinkedList List) 
{
	unsigned Len = 0;
	LNode* Current;
	//链表的本质就是第0个结点的指针
	Current = List;
	//如果List本来就是空链表，则不会执行循环体
	while (Current != NULL) 
	{
		Len++;
		Current = Current->Next;
	}
	return Len;
}
void SwapLinkedListNodes(LinkedList* PtrOfList, int FirstIdx, int SecondIdx)
{
	LNode* PrevFirst = NULL;
	LNode* PrevSecond = NULL;
	LNode* First = NULL;
	LNode* Second = NULL;
	int MinIdx = 0;
	int MaxIdx = 0;
	int Length = 0;
	//临时结点，为了解决第0号结点没有前驱的问题
	LNode Temp;
	//链表指针不能为空
	if (PtrOfList == NULL)
	{
		return;
	}
	//待交换结点下标越界，不能交换
	Length = LinkedListLength(*PtrOfList);
	if (FirstIdx < 0 || FirstIdx >= Length)
	{
		return;
	}
	if (SecondIdx < 0 || SecondIdx >= Length)
	{
		return;
	}
	//同一结点，不能交换
	if (FirstIdx == SecondIdx)
	{
		return;
	}
	//调整FirstIdx一定小于SecondIdx
	MinIdx = (FirstIdx < SecondIdx) ? FirstIdx : SecondIdx;
	MaxIdx = (FirstIdx > SecondIdx) ? FirstIdx : SecondIdx;
	FirstIdx = MinIdx;
	SecondIdx = MaxIdx;
	//临时节点，为了解决第0号结点没有前驱的问题
	Temp.Next = *PtrOfList;
	//用最多一次遍历，定位2个待交换结点及其前驱结点
	PrevFirst = &Temp;
	First = PrevFirst->Next;
	PrevSecond = &Temp;
	Second = PrevSecond->Next;
	while (FirstIdx > 0 && SecondIdx > 0)
	{
		PrevFirst = PrevFirst->Next;
		First = First->Next;
		PrevSecond = PrevSecond->Next;
		Second = Second->Next;
		FirstIdx--;
		SecondIdx--;
	}
	while (SecondIdx > 0)
	{
		PrevSecond = PrevSecond->Next;
		Second = Second->Next;
		SecondIdx--;
	}
	//待交换结点，相邻
	if (First == PrevSecond)
	{
		PrevFirst->Next = Second;
		First->Next = Second->Next;
		Second->Next = First;
	}
	//待交换结点，不相邻
	else {
		PrevFirst->Next = First->Next;
		PrevSecond->Next = Second->Next;

		First->Next = Second->Next;
		Second->Next = PrevFirst->Next;

		PrevFirst->Next = Second;
		PrevSecond->Next = First;
	}
	//更新List指向：如不是第0号结点，此语句不会改变List
	*PtrOfList = Temp.Next;
}
LNode* GetNode(LinkedList List, unsigned int ZeroBasedIndex)//返回特定Index号的链表节点指针
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
void MySort(LinkedList* PtrOfList)
{
	int i = 0;
	int j = 0;
	int MinClass;
	int Lenth;
	Lenth = LinkedListLength(*PtrOfList);
	for (i = 0; i < Lenth - 1; i++)
	{
		MinClass = i;
		for (j = i + 1; j < Lenth; j++)
		{
			if (GetNode(*PtrOfList, j)->Class < GetNode(*PtrOfList, MinClass)->Class)
			{
				MinClass = j;
			}
		}
		if (MinClass != i)
		{
			SwapLinkedListNodes(PtrOfList, i, MinClass);
		}
	}
	for (i = 0; i < Lenth; i++)
	{
		for (j = 0; j < Lenth; j++)
		{
			if (GetNode(*PtrOfList, i)->Class == GetNode(*PtrOfList, j)->Class)
			{
				if (GetNode(*PtrOfList, i)->Height < GetNode(*PtrOfList, j)->Height)
				{
					SwapLinkedListNodes(PtrOfList, i, j);
				}
				else if (GetNode(*PtrOfList, i)->Height == GetNode(*PtrOfList, j)->Height)
				{
					if (GetNode(*PtrOfList, i)->Code < GetNode(*PtrOfList, j)->Code)
					{
						SwapLinkedListNodes(PtrOfList, i, j);
					}
				}
			}
		}
	}
}
LNode* MySearch(LinkedList List, char ToFindClass, int ToFindPlace)
{
	LNode* ClassStart;
	LNode* Current;
	LNode* ClassEnd;
	int Count = 0;
	Current = List;
	while (Current != NULL)
	{
		if (Current->Class == ToFindClass)
		{
			ClassStart = Current;
			break;
		}
		Current = Current->Next;
	}
	while (Current != NULL)
	{
		if (Current->Class != ToFindClass)
		{
			ClassEnd = Current;
			break;
		}
		Current = Current->Next;
		Count++;
	}
	return GetNode(ClassStart, Count - ToFindPlace);
}
int main(int argc, char* argv[])
{
	LinkedList List = NULL;
	char ToFindClass = '\0';
	int ToFindPlace = 0;
	LNode* ToPrint;
	List = MyCreate();
	MyPrint(List);
	printf("\n");
	MySort(&List);
	MyPrint(List);
	printf("\n");
	getchar();
	scanf("%c%d", &ToFindClass, &ToFindPlace);
	ToPrint = MySearch(List, ToFindClass, ToFindPlace);
	printf("(%s %c %d)", ToPrint->Code, ToPrint->Class, ToPrint->Height);
	MyFree(&List);
	return 0;
}