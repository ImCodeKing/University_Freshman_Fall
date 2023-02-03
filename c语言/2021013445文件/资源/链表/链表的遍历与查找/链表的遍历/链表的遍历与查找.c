#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedefһ���ṹ��
{
	int Data;//Ӧ�ø���������
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedefһ���ṹ��ָ��
typedef void(*ElmtOperationType)(int*);//������Ҫ�ı�//����Ӧ��һ��������Ԫ�ؽ��в����ĺ������������滻ElmOperationType
void TraverseLinkedList(LinkedList List, ElmtOperationType AccessFunc)//����ı���
{
	LNode* Current;
	Current = List;
	while (Current != NULL)
	{
		AccessFunc(&Current->Data);
		Current = Current->Next;
	}
}
//����������Ĳ���
LNode* GetNode(LinkedList List, unsigned int ZeroBasedIndex)//�����ض�Index�ŵ�����ڵ�ָ��
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
//����β�ڵ��ָ��
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