#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedef一个结构体
{
	int Data;//应该改数据类型
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedef一个结构体指针
typedef void(*ElmtOperationType)(int*);//类型需要改变//附近应有一个对链表元素进行操作的函数，函数名替换ElmOperationType
void TraverseLinkedList(LinkedList List, ElmtOperationType AccessFunc)//链表的遍历
{
	LNode* Current;
	Current = List;
	while (Current != NULL)
	{
		AccessFunc(&Current->Data);
		Current = Current->Next;
	}
}
//以下是链表的查找
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
//返回尾节点的指针
LNode* GetLastNode(LinkedList List)
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