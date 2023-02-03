#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedef一个结构体
{
	int Data;//应该改数据类型
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedef一个结构体指针
unsigned int IsListEmpty(LinkedList List) 
{
	return List == NULL;
}
void DestroyLinkedList(int* PtrOfList)//销毁链表//其中的类型需要改变 
{
	LNode* Current = NULL;
	if (PtrOfList == NULL || IsListEmpty(*PtrOfList))
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