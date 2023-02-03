#include<stdio.h>
#include <stdlib.h>
typedef struct tagLNode
{
	int Data;
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;
void InputElement(int* PtrOfElement) //链表输入数字（初始化）
{
	if (PtrOfElement == NULL)
	{
		return;
	}
	memset(PtrOfElement, 0, sizeof(int));
	scanf("%d", PtrOfElement);//应该%d类型
}
LinkedList CreateLinkedListR(int Count)
{
	LinkedList Res;
	LNode* Head;
	LNode* New;
	LNode* End;
	Head = (LNode*)malloc(sizeof(LNode));
	Head->Next = NULL;
	End = Head;
	while (Count-- > 0)
	{
		New = (LNode*)malloc(sizeof(LNode));
		InputElement(&New->Data);
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
LNode* GetLastNode(LinkedList List)//返回尾节点的指针
{
	LNode* Last = NULL;
	LNode* Current;
	Current = List;
	while (Current != NULL)
	{
		Last = Current;
		Current = Current->Next;
	}
	return Last;
}
void ConnectLinkedList(LinkedList* PtrOfList1, LinkedList* PtrOfList2)
{
	if (PtrOfList1 == NULL || PtrOfList2 == NULL)
	{
		return;
	}
	if (*PtrOfList2 != NULL)
	{
		if (*PtrOfList1 == NULL)
		{
			*PtrOfList1 = *PtrOfList2;
		}
		else
		{
			GetLastNode(*PtrOfList1)->Next = *PtrOfList2;
		}
		*PtrOfList2 = NULL;
	}
}
int CountLinkedList(LinkedList List)
{
	LNode* Current;
	int Count = 0;
	Current = List;
	while (Current != NULL)
	{
		Count++;
		Current = Current->Next;
	}
	return Count;
}
void SwichLNode(LinkedList* PtrOfList, int Index1, int Index2)
{
	LNode* Head = NULL;
	Head = (LNode*)malloc(sizeof(LNode));
	Head->Next = *PtrOfList;
	LNode* PreSwich1 = NULL;
	LNode* PreSwich2 = NULL;
	LNode* AfterSwich1 = NULL;
	LNode* AfterSwich2 = NULL;
	LNode* Swich1 = NULL;
	LNode* Swich2 = NULL;
	if (Index1 == 0)
	{
		PreSwich1 = Head;
		PreSwich2 = GetNode(*PtrOfList, Index2 - 1);
		Swich1 = *PtrOfList;
		Swich2 = GetNode(*PtrOfList, Index2);
		AfterSwich1 = GetNode(*PtrOfList, Index1 + 1);
		AfterSwich2 = GetNode(*PtrOfList, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	else if (Index2 == 0)
	{
		PreSwich1 = GetNode(*PtrOfList, Index1 - 1);
		PreSwich2 = Head;
		Swich1 = GetNode(*PtrOfList, Index1);
		Swich2 = *PtrOfList;
		AfterSwich1 = GetNode(*PtrOfList, Index1 + 1);
		AfterSwich2 = GetNode(*PtrOfList, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	else if (Index1 == Index2 + 1 || Index2 == Index1 + 1)
	{
		if (Index1 < Index2)
		{
			PreSwich1 = GetNode(*PtrOfList, Index1 - 1);
			PreSwich2 = GetNode(*PtrOfList, Index1);
			Swich1 = GetNode(*PtrOfList, Index1);
			Swich2 = GetNode(*PtrOfList, Index2);
			AfterSwich1 = GetNode(*PtrOfList, Index2);
			AfterSwich2 = GetNode(*PtrOfList, Index2 + 1);
			PreSwich1->Next = Swich2;
			Swich2->Next = Swich1;
			Swich1->Next = AfterSwich2;
		}
		else
		{
			PreSwich1 = GetNode(*PtrOfList, Index2);
			PreSwich2 = GetNode(*PtrOfList, Index2 - 1);
			Swich1 = GetNode(*PtrOfList, Index1);
			Swich2 = GetNode(*PtrOfList, Index2);
			AfterSwich1 = GetNode(*PtrOfList, Index1 + 1);
			AfterSwich2 = GetNode(*PtrOfList, Index1);
			PreSwich2->Next = Swich1;
			Swich1->Next = Swich2;
			Swich2->Next = AfterSwich1;
		}
	}
	else
	{
		PreSwich1 = GetNode(*PtrOfList, Index1 - 1);
		PreSwich2 = GetNode(*PtrOfList, Index2 - 1);
		Swich1 = GetNode(*PtrOfList, Index1);
		Swich2 = GetNode(*PtrOfList, Index2);
		AfterSwich1 = GetNode(*PtrOfList, Index1 + 1);
		AfterSwich2 = GetNode(*PtrOfList, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	*PtrOfList = Head->Next;
	free(Head);
}
typedef void(*ElmtOperationType)(int*);
void OutputElement(int* PtrOfElement) 
{
	printf("%d->", *PtrOfElement);
}
void TraverseLinkedList(LinkedList List, ElmtOperationType AccessFunc) 
{
	LNode* Current;
	Current = List;
	while (Current != NULL) 
	{
		AccessFunc(&Current->Data);
		Current = Current->Next;
	}
}
int main(int argc, char* argv[])
{
	int Times = 0;
	unsigned int GroupMem = 0;
	scanf("%d%u", &Times, &GroupMem);
	int* Num = (int*)calloc(Times, sizeof(int));
	LinkedList* ListTotal = (LinkedList*)malloc(Times * sizeof(LinkedList));
	for (int i = 0; i < Times; i++)
	{
		scanf("%d", &Num[i]);
		*(ListTotal + i) = CreateLinkedListR(Num[i]);
	}
	/*for (int i = 0; i < Times; i++)
	{
		for (int j = 0; j < Num[i]; j++)
		{
			int ToPrint = GetNode(*(ListTotal + i), j)->Data;
			printf("%d ", ToPrint);
		}
		printf("\n");
	}*/
	for (int i = 0; i < Times; i++)
	{
		int Max = i;
		for (int j = i + 1; j < Times; j++)
		{
			if (Num[j] > Num[Max])
			{
				Max = j;
			}
		}
		if (Max != i)
		{
			int Temp = Num[Max];
			Num[Max] = Num[i];
			Num[i] = Temp;
		}
	}
	int NumberCount = (Num[0] % GroupMem == 0) ? (Num[0] / GroupMem) : (Num[0] / GroupMem + 1);
	LNode* HeadOfPrintList = (LNode*)calloc(NumberCount, sizeof(LNode));
	for (int i = 0; i < NumberCount; i++)
	{
		for (int j = 0; j < Times; j++)
		{
			if (GetNode(*(ListTotal + j), GroupMem) != NULL)
			{
				if (i == 0)
				{
					HeadOfPrintList[j].Next = GetNode(*(ListTotal + j), 0);//这个储存它的链表头
					for (int k = j + 1; k < Times; k++)
					{
						LinkedList Connect1 = HeadOfPrintList[j].Next;
						if (k == j + 1)
						{
							LNode* Good = GetNode(*(ListTotal + j), GroupMem);
							if (Good != NULL)
							{
								LNode* Temp = GetNode(*(ListTotal + j), GroupMem - 1)->Next;
								GetNode(*(ListTotal + j), GroupMem - 1)->Next = NULL;
								(*(ListTotal + j)) = Temp;
							}
							else
							{
								*(ListTotal + j) = NULL;
							}
						}
						LinkedList Connect2 = GetNode(*(ListTotal + k), 0);
						LNode* Good = GetNode(*(ListTotal + k), GroupMem);
						if (Good != NULL)
						{
							LNode* Temp = GetNode(*(ListTotal + k), GroupMem - 1)->Next;
							GetNode(*(ListTotal + k), GroupMem - 1)->Next = NULL;
							(*(ListTotal + k)) = Temp;
						}
						else
						{
							*(ListTotal + k) = NULL;
						}
						ConnectLinkedList(&Connect1, &Connect2);
					}
				}
				else
				{
					HeadOfPrintList[j].Next = GetNode(*(ListTotal + j), 0);//这个储存它的链表头
					for (int k = j + 1; k < Times; k++)
					{
						LinkedList Connect1 = HeadOfPrintList[j].Next;
						if (k == j + 1)
						{
							LNode* Good = GetNode(*(ListTotal + j), 2 * GroupMem);
							if (Good != NULL)
							{
								LNode* Temp = GetNode(*(ListTotal + j), 2 * GroupMem - 1)->Next;
								GetNode(*(ListTotal + j), 2 * GroupMem - 1)->Next = NULL;
								(*(ListTotal + j)) = Temp;
							}
							else
							{
								*(ListTotal + j) = NULL;
							}
						}
						LinkedList Connect2 = GetNode(*(ListTotal + k), GroupMem);
						LNode* Good = GetNode(*(ListTotal + k), 2 * GroupMem);
						if (Good != NULL)
						{
							LNode* Temp = GetNode(*(ListTotal + k), 2 * GroupMem - 1)->Next;
							GetNode(*(ListTotal + k), 2 * GroupMem - 1)->Next = NULL;
							(*(ListTotal + k)) = Temp;
						}
						else
						{
							*(ListTotal + k) = NULL;
						}
						ConnectLinkedList(&Connect1, &Connect2);
					}
				}
			}
		}
	}
for (int i = 0; i < NumberCount; i++)
{
	TraverseLinkedList((HeadOfPrintList + i)->Next, OutputElement);
	printf("\n");
}
	for (int i = 0; i < NumberCount; i++)
	{
		int TotalNumber = CountLinkedList((*(HeadOfPrintList + i)).Next);
		for (int m = 0; m < TotalNumber; m++)
		{
			int Least = m;
			for (int n = m + 1; n < TotalNumber; n++)
			{
				if ((GetNode((*(HeadOfPrintList + i)).Next, Least)->Data > (GetNode((*(HeadOfPrintList + i)).Next, n)->Data)))
				{
					Least = n;
				}
			}
			if (Least != m)
			{
				SwichLNode(&(((HeadOfPrintList + i))->Next), m, Least);
			}
		}
		for (int j = 0; j < TotalNumber; j++)
		{
			int ToPrint = (GetNode((*(HeadOfPrintList + i)).Next, j)->Data);
			printf("%d ", ToPrint);
		}
	}
	printf("\n");
	return 0;
}

















/*if ((GetNode(*(ListTotal + j), i * GroupMem) != NULL))
{
	LinkedList Connect1 = (HeadOfPrintList + i)->Next;
	LNode* Good = GetNode(*(ListTotal + j), (i + 1) * GroupMem);
	if (Good != NULL)
	{
		LNode* Temp = GetNode(*(ListTotal + j), (i + 1) * GroupMem - 1)->Next;
		GetNode(*(ListTotal + j), (i + 1) * GroupMem - 1)->Next = NULL;
		(*(ListTotal + j)) = Temp;
	}
	else
	{
		*(ListTotal + j) = NULL;
	}
	LinkedList Connect2 = GetNode(*(ListTotal + k), i * GroupMem);
	Good = GetNode(*(ListTotal + k), (i + 1) * GroupMem);
	if (Good != NULL)
	{
		LNode* Temp = GetNode(*(ListTotal + k), (i + 1) * GroupMem - 1)->Next;
		GetNode(*(ListTotal + k), (i + 1) * GroupMem - 1)->Next = NULL;
		(*(ListTotal + k)) = Temp;
	}
	else
	{
		*(ListTotal + k) = NULL;
	}
	ConnectLinkedList(&Connect1, &Connect2);
}
for (int j = 0; j < 9; j++)
	{
		if (GetNode((HeadOfPrintList + i)->Next, j)->Next == NULL)
		{
			break;
		}
		int ToPrint = GetNode((HeadOfPrintList + i)->Next, j)->Data;
		printf("%d ", ToPrint);
	}
*/






/*for (unsigned int j = 0; j < GroupMem; j++)
{
	if (GetNode(*(ListTotal + i), j) == NULL)
	{
		break;
	}
	else
}
for (int j = 0; j < Times - 1; j++)
{
	if (GetNode(*(ListTotal + j), GroupMem) != NULL && GetNode(*(ListTotal + j), GroupMem) != NULL)
		LNode Head;
	Head.Next = *(ListTotal + j);
	GetNode(*(ListTotal + j), GroupMem)->Next = *(ListTotal + j + 1);
	Head.Next = GetNode(*(ListTotal + j), GroupMem + 1);
}*/