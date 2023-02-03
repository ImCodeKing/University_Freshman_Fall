#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedef一个结构体
{
	int Data;//应该改数据类型
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedef一个结构体指针
void ReverseLinkedList(LinkedList* PtrOfList)//链表的逆序
{
	LNode* ToReverse = NULL;
	LNode* Next = NULL;
	LNode* LastReversed = NULL;
	if (PtrOfList == NULL) 
	{
		return;
	}
	ToReverse = *PtrOfList;
	while (ToReverse != NULL)
	{
		Next = ToReverse->Next;
		ToReverse->Next = LastReversed;
		LastReversed = ToReverse;
		ToReverse = Next;
	}
	*PtrOfList = LastReversed;
}