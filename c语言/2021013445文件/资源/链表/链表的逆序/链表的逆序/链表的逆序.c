#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedefһ���ṹ��
{
	int Data;//Ӧ�ø���������
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedefһ���ṹ��ָ��
void ReverseLinkedList(LinkedList* PtrOfList)//���������
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