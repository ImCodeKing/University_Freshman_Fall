#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedefһ���ṹ��
{
	int Data;//Ӧ�ø���������
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedefһ���ṹ��ָ��
unsigned int IsListEmpty(LinkedList List) 
{
	return List == NULL;
}
void DestroyLinkedList(int* PtrOfList)//��������//���е�������Ҫ�ı� 
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