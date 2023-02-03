#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode
{
	int Data;
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;
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
//范静涛版本的交换
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
//投机取巧的交换
void SwapNodes(LinkedList* PtrOfList, int First, int Second) 
{
	//此处假设ElemType是int，如为其他类型，以下给ElemFirst和ElemSecond赋值代码代码需要进行修改
	int ElemFirst;
	int ElemSecond;
	ElemFirst = GetNode((*PtrOfList), First)->Data;
	ElemSecond = GetNode((*PtrOfList), Second)->Data;
	InsertAt(PtrOfList, First, ElemSecond);
	DeleteAt(PtrOfList, First + 1);
	InsertAt(PtrOfList, Second, ElemFirst);
	DeleteAt(PtrOfList, Second + 1);
}




//选择法链表排序
//自定义元素比较函数指针类型，此类型函数返回值为int，2个类型为ElemType的形参
typedef int(*CampareOperationType)(int, int);
//排序链表函数，选择法，交换部分跟SwapNodes基本相同。与两个元素的比较，通过调用函数指针实现
void SortLList(LinkedList* PtrOfList, CampareOperationType CampareFunc) 
{
	//外层循环节点指针及前驱
	LNode* PrevFirst = NULL;
	LNode* PrevSecond = NULL;
	//内层循环节点指针及前驱
	LNode* First = NULL;
	LNode* Second = NULL;
	//选择法的待交换节点指针及前驱
	LNode* PrevToSwap = NULL;
	LNode* ToSwap = NULL;
	//临时结点，为了解决第0号结点没有前驱的问题
	LNode Temp;
	//链表指针不能为空
	if (PtrOfList == NULL) 
	{
		return;
	}
	//链表长度小于2，不需要排序
	if (LinkedListLength(*PtrOfList) < 2) 
	{
		return;
	}
	//临时结点，为头结点
	Temp.Next = *PtrOfList;
	//循环到尾结点之前的一个节点
	for (PrevFirst = &Temp, First = Temp.Next; First->Next != NULL; PrevFirst = First, First = First->Next) 
	{
		//选择法排序，待交换位置指定为本轮循环First位置
		PrevToSwap = PrevFirst;
		ToSwap = First;
		//循环到尾结点
		for (PrevSecond = First, Second = PrevSecond->Next; Second != NULL; PrevSecond = Second, Second = Second->Next) 
		{
			//根据比较结果，决定是否改变待交换节点及前驱节点指针变量的指向
			if (CampareFunc(ToSwap->Data, Second->Data)) 
			{
				PrevToSwap = PrevSecond;
				ToSwap = Second;
			}
		}
		//ToSwap指向结点不是First指向的节点，才会发生交换——选择法
		if (ToSwap != First) 
		{
			//待交换结点，相邻
			if (First == PrevToSwap) 
			{
				PrevFirst->Next = ToSwap;
				First->Next = ToSwap->Next;
				ToSwap->Next = First;
			}
			//待交换结点，不相邻
			else
			{
				//断开待交换结点
				PrevFirst->Next = First->Next;
				PrevToSwap->Next = ToSwap->Next;
				//在新位置链入First指向的结点
				First->Next = PrevToSwap->Next;
				PrevToSwap->Next = First;
				//在新位置链入PreToSwap指向的结点
				ToSwap->Next = PrevFirst->Next;
				PrevFirst->Next = ToSwap;
			}
			//无论被交换的结点是否相邻，都要更新First指向，因为First已经不再是PrevFirst->Next，如不更新，则第一层循环不会正常执行
			First = PrevFirst->Next;
			//更新List指向：如不是第0号结点，此语句不会改变List
			*PtrOfList = Temp.Next;
			//TraverseLList(*PtrOfList, OutputElement);
		}
	}
}