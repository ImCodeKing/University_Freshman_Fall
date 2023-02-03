#include <stdio.h>
#include <stdlib.h>
typedef struct tagLNode
{
	int Data;
	struct tagLNode* Next;
}LNode;
typedef LNode* LinkedList;
LNode* GetNode(LinkedList List, unsigned int ZeroBasedIndex)
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
void SwichLNode(LinkedList* PtrOfList, int Index1, int Index2)
{
	LNode* Head = NULL;
	Head = (LNode*)malloc(sizeof(LNode));
	Head->Next = *PtrOfList;
	LNode* PreSwich1 = NULL;
	LNode* PreSwich2 = NULL;
	LNode* AfterSwich1 = NULL;
	LNode* AfterSwich2 = NULL;
	LNode* Swich1 = NULL;
	LNode* Swich2 = NULL;
	if (Index1 == 0)
	{
		PreSwich1 = Head;
		PreSwich2 = GetNode(*PtrOfList, Index2 - 1);
		Swich1 = *PtrOfList;
		Swich2 = GetNode(*PtrOfList, Index2);
		AfterSwich1 = GetNode(*PtrOfList, Index1 + 1);
		AfterSwich2 = GetNode(*PtrOfList, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	else if (Index2 == 0)
	{
		PreSwich1 = GetNode(*PtrOfList, Index1 - 1);
		PreSwich2 = Head;
		Swich1 = GetNode(*PtrOfList, Index1);
		Swich2 = *PtrOfList;
		AfterSwich1 = GetNode(*PtrOfList, Index1 + 1);
		AfterSwich2 = GetNode(*PtrOfList, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	else if (Index1 == Index2 + 1 || Index2 == Index1 + 1)
	{
		if (Index1 < Index2)
		{
			PreSwich1 = GetNode(*PtrOfList, Index1 - 1);
			PreSwich2 = GetNode(*PtrOfList, Index1);
			Swich1 = GetNode(*PtrOfList, Index1);
			Swich2 = GetNode(*PtrOfList, Index2);
			AfterSwich1 = GetNode(*PtrOfList, Index2);
			AfterSwich2 = GetNode(*PtrOfList, Index2 + 1);
			PreSwich1->Next = Swich2;
			Swich2->Next = Swich1;
			Swich1->Next = AfterSwich2;
		}
		else
		{
			PreSwich1 = GetNode(*PtrOfList, Index2);
			PreSwich2 = GetNode(*PtrOfList, Index2 - 1);
			Swich1 = GetNode(*PtrOfList, Index1);
			Swich2 = GetNode(*PtrOfList, Index2);
			AfterSwich1 = GetNode(*PtrOfList, Index1 + 1);
			AfterSwich2 = GetNode(*PtrOfList, Index1);
			PreSwich2->Next = Swich1;
			Swich1->Next = Swich2;
			Swich2->Next = AfterSwich1;
		}
	}
	else
	{
		PreSwich1 = GetNode(*PtrOfList, Index1 - 1);
		PreSwich2 = GetNode(*PtrOfList, Index2 - 1);
		Swich1 = GetNode(*PtrOfList, Index1);
		Swich2 = GetNode(*PtrOfList, Index2);
		AfterSwich1 = GetNode(*PtrOfList, Index1 + 1);
		AfterSwich2 = GetNode(*PtrOfList, Index2 + 1);
		PreSwich1->Next = Swich2;
		Swich1->Next = AfterSwich2;
		PreSwich2->Next = Swich1;
		Swich2->Next = AfterSwich1;
	}
	*PtrOfList = Head->Next;
	free(Head);
}
//�����ΰ汾�Ľ���
unsigned int LinkedListLength(LinkedList List) 
{
	unsigned Len = 0;
	LNode* Current;
	//����ı��ʾ��ǵ�0������ָ��
	Current = List;
	//���List�������ǿ������򲻻�ִ��ѭ����
	while (Current != NULL) 
	{
		Len++;
		Current = Current->Next;
	}
	return Len;
}
void SwapLinkedListNodes(LinkedList* PtrOfList, int FirstIdx, int SecondIdx)
{
	LNode* PrevFirst = NULL;
	LNode* PrevSecond = NULL;
	LNode* First = NULL;
	LNode* Second = NULL;
	int MinIdx = 0;
	int MaxIdx = 0;
	int Length = 0;
	//��ʱ��㣬Ϊ�˽����0�Ž��û��ǰ��������
	LNode Temp;
	//����ָ�벻��Ϊ��
	if (PtrOfList == NULL) 
	{
		return;
	}
	//����������±�Խ�磬���ܽ���
	Length = LinkedListLength(*PtrOfList);
	if (FirstIdx < 0 || FirstIdx >= Length) 
	{
		return;
	}
	if (SecondIdx < 0 || SecondIdx >= Length)
	{
		return;
	}
	//ͬһ��㣬���ܽ���
	if (FirstIdx == SecondIdx)
	{
		return;
	}
	//����FirstIdxһ��С��SecondIdx
	MinIdx = (FirstIdx < SecondIdx) ? FirstIdx : SecondIdx;
	MaxIdx = (FirstIdx > SecondIdx) ? FirstIdx : SecondIdx;
	FirstIdx = MinIdx;
	SecondIdx = MaxIdx;
	//��ʱ�ڵ㣬Ϊ�˽����0�Ž��û��ǰ��������
	Temp.Next = *PtrOfList;
	//�����һ�α�������λ2����������㼰��ǰ�����
	PrevFirst = &Temp;
	First = PrevFirst->Next;
	PrevSecond = &Temp;
	Second = PrevSecond->Next;
	while (FirstIdx > 0 && SecondIdx > 0) 
	{
		PrevFirst = PrevFirst->Next;
		First = First->Next;
		PrevSecond = PrevSecond->Next;
		Second = Second->Next;
		FirstIdx--;
		SecondIdx--;
	}
	while (SecondIdx > 0) 
	{
		PrevSecond = PrevSecond->Next;
		Second = Second->Next;
		SecondIdx--;
	}
	//��������㣬����
	if (First == PrevSecond) 
	{
		PrevFirst->Next = Second;
		First->Next = Second->Next;
		Second->Next = First;
	}
	//��������㣬������
	else {
		PrevFirst->Next = First->Next;
		PrevSecond->Next = Second->Next;

		First->Next = Second->Next;
		Second->Next = PrevFirst->Next;

		PrevFirst->Next = Second;
		PrevSecond->Next = First;
	}
	//����Listָ���粻�ǵ�0�Ž�㣬����䲻��ı�List
	*PtrOfList = Temp.Next;
}
//Ͷ��ȡ�ɵĽ���
void SwapNodes(LinkedList* PtrOfList, int First, int Second) 
{
	//�˴�����ElemType��int����Ϊ�������ͣ����¸�ElemFirst��ElemSecond��ֵ���������Ҫ�����޸�
	int ElemFirst;
	int ElemSecond;
	ElemFirst = GetNode((*PtrOfList), First)->Data;
	ElemSecond = GetNode((*PtrOfList), Second)->Data;
	InsertAt(PtrOfList, First, ElemSecond);
	DeleteAt(PtrOfList, First + 1);
	InsertAt(PtrOfList, Second, ElemFirst);
	DeleteAt(PtrOfList, Second + 1);
}




//ѡ����������
//�Զ���Ԫ�رȽϺ���ָ�����ͣ������ͺ�������ֵΪint��2������ΪElemType���β�
typedef int(*CampareOperationType)(int, int);
//������������ѡ�񷨣��������ָ�SwapNodes������ͬ��������Ԫ�صıȽϣ�ͨ�����ú���ָ��ʵ��
void SortLList(LinkedList* PtrOfList, CampareOperationType CampareFunc) 
{
	//���ѭ���ڵ�ָ�뼰ǰ��
	LNode* PrevFirst = NULL;
	LNode* PrevSecond = NULL;
	//�ڲ�ѭ���ڵ�ָ�뼰ǰ��
	LNode* First = NULL;
	LNode* Second = NULL;
	//ѡ�񷨵Ĵ������ڵ�ָ�뼰ǰ��
	LNode* PrevToSwap = NULL;
	LNode* ToSwap = NULL;
	//��ʱ��㣬Ϊ�˽����0�Ž��û��ǰ��������
	LNode Temp;
	//����ָ�벻��Ϊ��
	if (PtrOfList == NULL) 
	{
		return;
	}
	//������С��2������Ҫ����
	if (LinkedListLength(*PtrOfList) < 2) 
	{
		return;
	}
	//��ʱ��㣬Ϊͷ���
	Temp.Next = *PtrOfList;
	//ѭ����β���֮ǰ��һ���ڵ�
	for (PrevFirst = &Temp, First = Temp.Next; First->Next != NULL; PrevFirst = First, First = First->Next) 
	{
		//ѡ�����򣬴�����λ��ָ��Ϊ����ѭ��Firstλ��
		PrevToSwap = PrevFirst;
		ToSwap = First;
		//ѭ����β���
		for (PrevSecond = First, Second = PrevSecond->Next; Second != NULL; PrevSecond = Second, Second = Second->Next) 
		{
			//���ݱȽϽ���������Ƿ�ı�������ڵ㼰ǰ���ڵ�ָ�������ָ��
			if (CampareFunc(ToSwap->Data, Second->Data)) 
			{
				PrevToSwap = PrevSecond;
				ToSwap = Second;
			}
		}
		//ToSwapָ���㲻��Firstָ��Ľڵ㣬�Żᷢ����������ѡ��
		if (ToSwap != First) 
		{
			//��������㣬����
			if (First == PrevToSwap) 
			{
				PrevFirst->Next = ToSwap;
				First->Next = ToSwap->Next;
				ToSwap->Next = First;
			}
			//��������㣬������
			else
			{
				//�Ͽ����������
				PrevFirst->Next = First->Next;
				PrevToSwap->Next = ToSwap->Next;
				//����λ������Firstָ��Ľ��
				First->Next = PrevToSwap->Next;
				PrevToSwap->Next = First;
				//����λ������PreToSwapָ��Ľ��
				ToSwap->Next = PrevFirst->Next;
				PrevFirst->Next = ToSwap;
			}
			//���۱������Ľ���Ƿ����ڣ���Ҫ����Firstָ����ΪFirst�Ѿ�������PrevFirst->Next���粻���£����һ��ѭ����������ִ��
			First = PrevFirst->Next;
			//����Listָ���粻�ǵ�0�Ž�㣬����䲻��ı�List
			*PtrOfList = Temp.Next;
			//TraverseLList(*PtrOfList, OutputElement);
		}
	}
}