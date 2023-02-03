#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedefһ���ṹ��
{
	int Data;//Ӧ�ø���������
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedefһ���ṹ��ָ��
LNode* InsertAt(LinkedList* PtrOfList, unsigned int Index, int Element)//���ڵ���������Indexλ��//Ӧ���������ݵ�����
{
	LNode* Prev = NULL;
	LNode* New = NULL;
	LNode Temp;
	if (PtrOfList == NULL)
	{
		return NULL;
	}
	Temp.Next = *PtrOfList;
	Prev = (Index == 0) ? (&Temp) : GetNode(*PtrOfList, Index - 1);
	if (Prev != NULL) 
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->Data = Element;
		New->Next = Prev->Next;
		Prev->Next = New;
	}
	*PtrOfList = Temp.Next;
	return New;
}
LNode* InsertAt(LinkedList* PtrOfList, unsigned int Index, int Element)//���ڵ���������0��λ��//Ӧ���������ݵ�����
{
	LNode* Prev = NULL;
	LNode* New = NULL;
	LNode Temp;
	if (PtrOfList == NULL)
	{
		return NULL;
	}
	Temp.Next = *PtrOfList;
	Prev = (Index == 0) ? (&Temp) : GetNode(*PtrOfList, Index - 1);
	if (Prev != NULL) 
	{
		New = (LNode*)malloc(sizeof(LNode));
		New->Data = Element;
		New->Next = Prev->Next;
		Prev->Next = New;
	}
	*PtrOfList = Temp.Next;
	return New;
}