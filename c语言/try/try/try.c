#include <stdio.h>
#include <stdlib.h>
_BOOL good;
typedef struct tagLNode//typedef一个结构体
{
	int Data;//应该改数据类型
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedef一个结构体指针
void InputElement(int* PtrOfElement) //链表输入数字（初始化）
{
	if (PtrOfElement == NULL) 
	{
		return;
	}
	memset(PtrOfElement, 0, sizeof(int));
	scanf("%d", PtrOfElement);//应该%d类型
}
LNode* CreateLinkedListR(int Count)//创建链表
{
	LNode* Res;
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
	return Head;
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




































int main(int argc, char* argv[]) 
{
	int a;
	int b;
	scanf("%d%d", &a, &b);
	if (a > b) {
		swap(&a, &b);
	}
	printf("min=%d,max=%d\n", a, b); //输出
	return 0;
}
