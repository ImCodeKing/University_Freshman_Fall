#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedefһ���ṹ��
{
	int Data;//Ӧ�ø���������
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedefһ���ṹ��ָ��
LNode* GetLastNode(LinkedList List)//����β�ڵ��ָ��
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