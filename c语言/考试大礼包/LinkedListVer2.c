#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//自定义类型开始
//自定义int为元素类型,需要根据题目调整，元素类型可能是结构体
typedef int ElemType;
//自定义元素比较函数指针类型，此类型函数返回值为int，2个类型为ElemType的形参
typedef int(* CampareOperationType)(ElemType, ElemType);
//自定义元素操作函数指针类型，此类型函数返回值为void，1个类型为ElemType*的形参
typedef void(*ElmtOperationType)(ElemType*);

//自定义链表结点类型LNode
//使用ElemType，保持结点类型声明代码稳定，ElemType具体是什么类型，都不需要改变一下7行代码
typedef struct tagLNode{
    ElemType Data;
    struct tagLNode* Next;
}LNode;

//自定义链表类型，其实就是指向结点的指针
typedef LNode* LinkedList;
//自定义类型结束

//元素操作函数声明开始
//输入元素函数声明
void InputElement(ElemType* PtrOfElement);
//编辑元素函数声明
void EditElement(ElemType* PtrOfElement);
//输出元素函数声明
void OutputElement(ElemType* PtrOfElement);
//元素大于比较，first>second返回1，否在返回0
int IsLarger(ElemType First, ElemType Second);
//元素操作函数声明结束

//链表常规操作函数声明开始
//创建链表函数声明，根据结点数量”头插“动态开辟一个链表，并返回链表指针
LinkedList CreateLList_Front(int Count);
//创建链表函数声明，根据结点数量”尾插“动态开辟一个链表，并返回链表指针
LinkedList CreateLList_Rear(int Count);
//创建链表函数声明，根据结点数量头/尾插动态开辟一个链表，并返回链表指针
LinkedList CreateLList(int Count, unsigned int IsFrontInsert);
//链表是否为空函数声明，链表是否为空，为空返回1，非空返回0
unsigned int IsLListEmpty(LinkedList List);
//销毁链表函数声明，*PtrOfList将被置为NULL
void DestroyLList(LinkedList* PtrOfList);
//遍历链表函数声明，对链表List中的每个元素，依次执行Func函数进行访问
void TraverseLList(LinkedList List, ElmtOperationType AccessFunc);
//求链表长度函数声明
unsigned int LinkedListLength(LinkedList List);
//获取链表尾结点函数声明，返回尾结点指针
LNode* GetLastNode(LinkedList List);
//获取链表指定结点函数声明，返回第ZeroBasedIndex号结点指针
LNode* GetNode(LinkedList List, unsigned int ZeroBasedIndex);
//连接链表函数声明
void ConnectLinkedList(LinkedList* PtrOfList1, LinkedList* PtrOfList2);
//指定位置插入结点函数声明，在ZeroBasedIndex位置插入新结点，并返回新结点指针
LNode* InsertAt(LinkedList* PtrOfList, unsigned int ZeroBasedIndex, ElemType Element);
//指定位置删除结点函数声明，删除ZeroBasedIndex位置的结点，并返回删除后ZeroBasedIndex位置的结点指针
LNode* DeleteAt(LinkedList* PtrOfList, unsigned int ZeroBasedIndex);
//交换指定位置结点函数声明
void SwapLinkedListNodes(LinkedList* PtrOfList, int FirstIdx, int SecondIdx);
//排序链表函数声明
void SortLList(LinkedList* PtrOfList, CampareOperationType CampareFunc);
//链表逆序重构函数声明
void ReverseLinkedList(LinkedList* PtrOfList);
//链表常规操作函数声明结束

//元素操作函数定义开始
//输入元素
void InputElement(ElemType* PtrOfElement){
    //需要根据ElemType调整
    scanf("%d", PtrOfElement);
}
//编辑元素
void EditElement(ElemType* PtrOfElement){
    //需要根据ElemType调整
    (*PtrOfElement)++;
}
//输出元素
void OutputElement(ElemType* PtrOfElement){
    //需要根据ElemType调整
    printf("%d->", *PtrOfElement);
}
//元素大于比较，first>second返回1，否在返回0
int IsLarger(ElemType First, ElemType Second) {
    //需要根据ElemType调整
    return First > Sencond;
}
//元素操作函数定义结束

//链表常规操作函数定义开始
//根据结点数量，用头插法，动态开辟一个链表，并返回链表
LinkedList CreateLList_Front(int Count){
    //用于存放所创建的链表（链表的第0个结点首地址）
    LinkedList Res;
    //头结点指针，所有新结点都应插入到Head->Next位置
    LNode* Head;
    //新结点指针
    LNode* New;
    //尾结点指针
    LNode* End;

    //动态开辟头结点，Data无所谓，Next是NULL
    Head = (LNode*)malloc(sizeof(LNode));
    Head->Next = NULL;
    //此时头尾是同一结点
    End = Head;
    while (Count --> 0) {
        //动态开辟新结点
        New = (LNode*)malloc(sizeof(LNode));
        //输入结点元素
        InputElement(&New->Data);
        //两步法插入新结点到Head后
        New->Next = Head->Next;
        Head->Next = New;
        //更新尾结点指针
        End = New;
    }
    Res = Head->Next;
    free(Head);
    return Res;
}

//根据结点数量”尾插“动态开辟一个链表，并返回链表指针
LinkedList CreateLList_Rear(int Count){
    //用于存放所创建的链表（链表的第0个结点首地址）
    LinkedList Res;
    //头结点指针
    LNode* Head;
    //新结点指针
    LNode* New;
    //尾结点指针，所有新结点都应插入到Head->Next位置
    LNode* End;

    //动态开辟头结点，Data无所谓，Next是NULL
    Head = (LNode*)malloc(sizeof(LNode));
    Head->Next = NULL;
    //此时头尾是同一结点
    End = Head;
    while (Count --> 0) {
        //动态开辟新结点
        New = (LNode*)malloc(sizeof(LNode));
        //输入结点元素
        InputElement(&New->Data);
        //两步法插入新结点到End后
        New->Next = End->Next;
        End->Next = New;
        //更新尾结点指针
        End = New;
    }
    Res = Head->Next;
    free(Head);
    return Res;
}

//根据结点数量头/尾插动态开辟一个链表，并返回链表指针
LinkedList CreateLinkedList(int Count, unsigned int IsFrontInsert){
    if (IsFrontInsert != 0) {
        return CreateLList_Front(Count);
    }
    else {
        return CreateLList_Rear(Count);
    }
}

//链表是否为空，链表是否为空，为空返回1，非空返回0
unsigned int IsLListEmpty(LinkedList List){
    return List == NULL;
}

//销毁链表，*PtrOfList将被置为NULL
void DestroyLList(LinkedList* PtrOfList){
    LNode* Current = NULL;
    if (PtrOfList == NULL || IsLListEmpty(*PtrOfList)) {
        return;
    }
    //链表的本质就是第0个结点的指针
    Current = (*PtrOfList);
    while (Current != NULL) {
        //从链表上把Current指向的结点摘下来，构成新的链表
        (*PtrOfList) = Current->Next;
        //释放Current指向的结点空间
        free(Current);
        //Current指向新链表的第0个结点
        Current = (*PtrOfList);
    }
}

//遍历链表，对List中的每个结点的元素，依次执行AccessFunc函数进行访问
void TraverseLList(LinkedList List, ElmtOperationType AccessFunc){
    LNode* Current;
    //链表的本质就是第0个结点的指针
    Current = List;
    //如果List本来就是空链表，则不会执行循环体
    while (Current != NULL) {
        AccessFunc(&Current->Data);
        Current = Current->Next;
    }
}

//求链表长度函数
unsigned int LinkedListLength(LinkedList List) {
    unsigned Len = 0;
    LNode* Current;
    //链表的本质就是第0个结点的指针
    Current = List;
    //如果List本来就是空链表，则不会执行循环体
    while (Current != NULL) {
        Len++;
        Current = Current->Next;
    }
    return Len;
}

//获取链表尾结点，返回尾结点指针
LNode* GetLastNode(LinkedList List){
    LNode* Last = NULL;
    LNode* Current;
    //链表的本质就是第0个结点的指针
    Current = List;
    //如果List本来就是空链表，则不会执行循环体
    while (Current != NULL) {
        Last = Current;
        Current = Current->Next;
    }
    return Last;
}

//获取链表指定结点，返回第ZeroBasedIndex号结点指针
LNode* GetNode(LinkedList List, unsigned int ZeroBasedIndex){
    unsigned int Index = 0;
    LNode* Current;
    //链表的本质就是第0个结点的指针
    Current = List;
    //如果List本来就是空链表，则不会执行循环体
    while (Index < ZeroBasedIndex && Current != NULL) {
        Current = Current->Next;
        Index++;
    }
    return Current;
}

//连接链表
void ConnectLinkedList(LinkedList* PtrOfList1, LinkedList* PtrOfList2){
    //链表的指针不能为NULL
    if (PtrOfList1 == NULL || PtrOfList2 == NULL) {
        return;
    }
    //List2是非空链表才执行操作，否则无需操作
    if (*PtrOfList2 != NULL) {
        //如果List1是空链表
        if (*PtrOfList1 == NULL) {
            //List1指向List2的第0号结点
            *PtrOfList1 = *PtrOfList2;
        }
        //List1不是空链表
        else {
            //将List2的第0号结点，作为List1尾结点的后继
            GetLastNode(*PtrOfList1)->Next = *PtrOfList2;
        }
        //List2置空
        *PtrOfList2 = NULL;
    }
}

//指定位置插入结点，在ZeroBasedIndex位置插入新结点，并返回新结点指针
LNode* InsertAt(LinkedList* PtrOfList, unsigned int ZeroBasedIndex, ElemType Element){
    //要插入位置的前驱结点指针
    LNode* Prev = NULL;
    LNode* New = NULL;
    //临时结点，为了解决第0号结点没有前驱的问题
    LNode Temp;
    //链表指针不能为空
    if (PtrOfList == NULL) {
        return NULL;
    }

    Temp.Next = *PtrOfList;
    //如果在头插入，前驱结点为Temp，否则遍历寻找前驱结点(第Index-1号结点)
    Prev = (ZeroBasedIndex == 0) ? (&Temp) : GetNode(*PtrOfList, ZeroBasedIndex - 1);
    //存在前驱结点
    if (Prev != NULL) {
        //新建结点
        New = (LNode*)malloc(sizeof(LNode));
        //设定元素值
        strcpy(New->Data, Element);
        //新结点的后继结点，是前驱结点的后继结点
        New->Next = Prev->Next;
        //前驱结点的后继，是新结点
        Prev->Next = New;
    }
    //更新List指向：如插入位置不是头，此语句不会改变List
    *PtrOfList = Temp.Next;
    return New;
}

//指定位置删除结点，删除ZeroBasedIndex位置的结点，并返回删除后ZeroBasedIndex位置的结点指针
LNode* DeleteAt(LinkedList* PtrOfList, unsigned int ZeroBasedIndex){
    //要删除结点的前驱结点指针
    LNode* Prev = NULL;
    LNode* ToDelete = NULL;
    //临时结点，为了解决第0号结点没有前驱的问题
    LNode Temp;
    //链表指针不能为空
    if (PtrOfList == NULL) {
        return NULL;
    }

    Temp.Next = *PtrOfList;
    //如果删第0号结点，前驱结点为Temp，否则遍历寻找前驱结点(第Index-1号结点)
    Prev = (ZeroBasedIndex == 0) ? (&Temp) : GetNode(*PtrOfList, ZeroBasedIndex - 1);
    //如超范围删除，返回NULL
    if (Prev == NULL) {
        return NULL;
    }
    ToDelete = Prev->Next;
    //存在，前驱结点 和 要删除的结点
    if (Prev != NULL && ToDelete != NULL) {
        //跨过要删的结点
        Prev->Next = ToDelete->Next;
        //释放ToDelete
        free(ToDelete);
    }
    //更新List指向：如不是第0号结点，此语句不会改变List
    *PtrOfList = Temp.Next;
    return Prev->Next;
}

//交换指定位置结点函数
void SwapLListNodes(LinkedList* PtrOfList, int FirstIdx, int SecondIdx){
    LNode* PrevFirst = NULL;
    LNode* PrevSecond = NULL;
    LNode* First = NULL;
    LNode* Second = NULL;
    int MinIdx = 0;
    int MaxIdx = 0;
    int Length = 0;
    //临时结点，为了解决第0号结点没有前驱的问题
    LNode Temp;
    //链表指针不能为空
    if (PtrOfList == NULL) {
        return;
    }
    //待交换结点下标越界，不能交换
    Length = LinkedListLength(*PtrOfList);
    if (FirstIdx < 0 || FirstIdx >= Length) {
        return;
    }
    if (SecondIdx < 0 || SecondIdx >= Length) {
        return;
    }
    //同一结点，不能交换
    if (FirstIdx == SecondIdx) {
        return;
    }

    //调整FirstIdx一定小于SecondIdx
    MinIdx = (FirstIdx < SecondIdx) ? FirstIdx : SecondIdx;
    MaxIdx = (FirstIdx > SecondIdx) ? FirstIdx : SecondIdx;
    FirstIdx = MinIdx;
    SecondIdx = MaxIdx;
    
    //临时结点，为了解决第0号结点没有前驱的问题
    Temp.Next = *PtrOfList;
    
    //用最多一次遍历，定位2个待交换结点及其前驱结点
    PrevFirst = &Temp;
    First = PrevFirst->Next;
    PrevSecond = &Temp;
    Second = PrevSecond->Next;
    while (FirstIdx > 0 && SecondIdx > 0) {
        PrevFirst = PrevFirst->Next;
        First = First->Next;
        PrevSecond = PrevSecond->Next;
        Second = Second->Next;
        FirstIdx--;
        SecondIdx--;
    }
    while (SecondIdx > 0) {
        PrevSecond = PrevSecond->Next;
        Second = Second->Next;
        SecondIdx--;
    }
    
    //待交换结点，相邻
    if (First == PrevSecond) {
        PrevFirst->Next = Second;
        First->Next = Second->Next;
        Second->Next = First;
    }
    //待交换结点，不相邻
    else {
        //断开待交换结点
        PrevFirst->Next = First->Next;
        PrevSecond->Next = Second->Next;
        //在新位置链入First指向的结点
        First->Next = PrevSecond->Next;
        PrevSecond->Next = First;
        //在新位置链入Second指向的结点
        Second->Next = PrevFirst->Next;
        PrevFirst->Next = Second;
    }
    //更新List指向：如不是第0号结点，此语句不会改变List
    *PtrOfList = Temp.Next;
}

//排序链表函数
void SortLList(LinkedList* PtrOfList, CampareOperationType CampareFunc){
    //外层循环节点指针及前驱
    LNode* PrevFirst = NULL;
    LNode* PrevSecond = NULL;
    //内层循环节点指针及前驱
    LNode* First = NULL;
    LNode* Second = NULL;
    //选择法的待交换节点指针及前驱
    LNode* PrevToSwap = NULL;
    LNode* ToSwap = NULL;

    //临时结点，为了解决第0号结点没有前驱的问题
    LNode Temp;
    //链表指针不能为空
    if (PtrOfList == NULL) {
        return;
    }
    //链表长度小于2，不需要排序
    if (LinkedListLength(*PtrOfList) < 2) {
        return;
    }
    
    //临时结点，为头结点
    Temp.Next = *PtrOfList;

    //循环到尾结点之前的一个节点
    for (PrevFirst = &Temp, First = Temp.Next; First->Next != NULL; PrevFirst = First, First = First->Next) {
        //选择法排序，待交换位置指定为本轮循环First位置
        PrevToSwap = PrevFirst;
        ToSwap = First;
        //循环到尾结点
        for (PrevSecond = First, Second = PrevSecond->Next; Second!= NULL; PrevSecond = Second, Second = Second->Next) {
            //根据比较结果，决定是否改变待交换节点及前驱节点指针变量的指向
            if (CampareFunc(ToSwap->Data, Second->Data)) {
                PrevToSwap = PrevSecond;
                ToSwap = Second;
            }
        }
        //ToSwap指向结点不是First指向的节点，才会发生交换——选择法
        if (ToSwap != First) {
            //待交换结点，相邻
            if (First == PrevToSwap) {
                PrevFirst->Next = ToSwap;
                First->Next = ToSwap->Next;
                ToSwap->Next = First;
            }
            //待交换结点，不相邻
            else {
                //断开待交换结点
                PrevFirst->Next = First->Next;
                PrevToSwap->Next = ToSwap->Next;
                //在新位置链入First指向的结点
                First->Next = PrevToSwap->Next;
                PrevToSwap->Next = First;
                //在新位置链入PreToSwap指向的结点
                ToSwap->Next = PrevFirst->Next;
                PrevFirst->Next = ToSwap;
            }
            //无论被交换的结点是否相邻，都要更新First指向，因为First已经不再是PrevFirst->Next，如不更新，则第一层循环不会正常执行
            First = PrevFirst->Next;
            //更新List指向：如不是第0号结点，此语句不会改变List
            *PtrOfList = Temp.Next;
        }
    }
}


//链表逆序重构
void ReverseLinkedList(LinkedList* PtrOfList){
    //要从链表里脱离并进行逆序重构的结点
    LNode* ToReverse = NULL;
    //ToReverse的后继结点(下一次Reverse)
    LNode* Next = NULL;
    //最后一次从列表里脱离并已完成逆序重构的结点
    LNode* LastReversed = NULL;

    //链表指针不能为空
    if (PtrOfList == NULL) {
        return;
    }
    //最开始，要逆序的是第0号结点
    ToReverse = *PtrOfList;
    //依次处理所有结点
    while (ToReverse != NULL) {
        //Next是要逆序结点的后继结点
        Next = ToReverse->Next;
        //把要逆序的结点，放在，最后一个已经逆序的结点，的前面。(这就是逆序)
        ToReverse->Next = LastReversed;
        //已经逆序过了，所以LastReversed更新为ToReverse
        LastReversed = ToReverse;
        //下次要Reverse的就是现在的Next
        ToReverse = Next;
    }
    //最后Removed的结点，就是逆序后的第0个结点
    *PtrOfList = LastReversed;
}
//链表常规操作函数定义结束



//题目所需函数和main函数声明
//your code here

//题目所需函数定义
//your code here




