#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode//typedefһ���ṹ��
{
	int Data;//Ӧ�ø���������
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;//typedefһ���ṹ��ָ��
void InputElement(int* PtrOfElement) //�����������֣���ʼ����
{
	if (PtrOfElement == NULL)
	{
		return;
	}
	memset(PtrOfElement, 0, sizeof(int));
	scanf("%d", PtrOfElement);//Ӧ��%d����
}
LinkedList CreateLinkedListR(int Count)//��������//β�巨//Ӧ�ø���������
{
	LinkedList Res;
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
	Res = Head->Next;
	free(Head);
	return Res;
}
LinkedList CreateLinkedListF(int Count)//ͷ�巨
{
	LinkedList Res;
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
		New->Next = Head->Next;
		Head->Next = New;
		End = New;
	}
	Res = Head->Next;
	free(Head);
	return Res;
}