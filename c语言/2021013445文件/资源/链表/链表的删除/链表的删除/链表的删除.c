#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedefһ���ṹ��
{
	int Data;//Ӧ�ø���������
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedefһ���ṹ��ָ��
LNode* DeleteAt(LinkedList* PtrOfList, unsigned int Index)//ɾ��β���
{
	LNode* Prev = NULL;
	LNode* ToDelete = NULL;
	LNode Temp;
	if (PtrOfList == NULL) 
	{
		return NULL;
	}
	Temp.Next = *PtrOfList;
	Prev = &Temp;
	Prev = (Index == 0) ? (&Temp) : GetNode(*PtrOfList, Index - 1);
	ToDelete = Prev->Next;
	if (Prev != NULL && ToDelete != NULL) 
	{
		Prev->Next = ToDelete->Next;
		free(ToDelete);
	}
	*PtrOfList = Temp.Next;
	return Prev->Next;
}
LNode* DeleteAt(LinkedList* PtrOfList, unsigned int Index)//ɾ��ͷ���
{
	LNode* Prev = NULL;
	LNode* ToDelete = NULL;
	LNode Temp;
	if (PtrOfList == NULL) 
	{
		return NULL;
	}
	Temp.Next = *PtrOfList;
	Prev = &Temp;
	Prev = (Index == 0) ? (&Temp) : GetNode(*PtrOfList, Index - 1);
	ToDelete = Prev->Next;
	if (Prev != NULL && ToDelete != NULL)
	{
		Prev->Next = ToDelete->Next;
		free(ToDelete);
	}
	*PtrOfList = Temp.Next;
	return Prev->Next;
}
