//
//  Heap.cpp
//  MLCppDS
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#include "Heap.h"

template <class Elem>
HeapTree<Elem>::HeapTree(int MaxSize)
: MAX_SIZE(MaxSize)
{
    Data       = new Elem[MAX_SIZE];
    CurrentNum = 0;
}

template <class Elem>
HeapTree<Elem>::HeapTree(const HeapTree<Elem> &OtherTree)
: MAX_SIZE(OtherTree.MAX_SIZE)
{
    Data       = new Elem[MAX_SIZE];
    CurrentNum = OtherTree.CurrentNum;
    
    for (int i = 0; i < OtherTree.CurrentNum; ++i)
        Data[i] = OtherTree.Data[i];
}

template <class Elem>
HeapTree<Elem>::HeapTree(Elem *Array, int ElemNum, int MaxSize)
: MAX_SIZE(MaxSize)
{
    Data       = new Elem[MAX_SIZE];
    CurrentNum = ElemNum;
    
    for (int i = 0; i < ElemNum; ++i)
        Data[i] = Array[i];
    
    for (int i = ParentOf(CurrentNum - 1); i >= 0; --i)
    {
        ShiftDown(i);
    }
    
}

template <class Elem>
HeapTree<Elem>::~HeapTree(void)
{
    if (Data)
        delete Data;
}

// 排序基于最大树的删除元素操作(总是删除根,即最大值)
template <class Elem>
Elem *HeapTree<Elem>::Sort(void)
{
    Elem *NewArray = new Elem[CurrentNum];
    
    for (int ElemNum = CurrentNum-1; ElemNum >=0; --ElemNum)
    {
        NewArray[ElemNum] = Remove();
    }
    return NewArray;
}

template <class Elem>
bool HeapTree<Elem>::Add(const Elem &Item)
{
    if (CurrentNum >= MAX_SIZE)
        return false;
    Data[ CurrentNum ] = Item;
    ShiftUp(CurrentNum++);
    return true;
}

// 删除根,即最大值
template <class Elem>
Elem HeapTree<Elem>::Remove(void)
{
    assert(CurrentNum > 0);
    
    Elem Temp = Data[0];
    Data[0] = Data[--CurrentNum];
    ShiftDown(0);
    return Temp;
}

template <class Elem>
inline int HeapTree<Elem>::GetSize(void)
{
    return CurrentNum;
}

template <class Elem>
void HeapTree<Elem>::ShiftUp(int Node)
{
    int  Current = Node,
    Parent  = ParentOf(Current);
    Elem Item    = Data[Current];
    
    while (Current > 0)
    {
        if (Data[Parent] < Item)
        {
            Data[Current] = Data[Parent];
            Current = Parent;
            Parent = ParentOf(Current);
        }
        else
            break;
    }
    Data[Current] = Item;
}

template <class Elem>
void HeapTree<Elem>::ShiftDown(int Node)
{
    int Current = Node,
    Child   = LeftChildOf(Current);
    Elem Item   = Data[Current];
    
    while (Child < CurrentNum)
    {
        if (Child < (CurrentNum - 1))
            if (Data[Child] < Data[Child+1])  // 比较左孩子和右孩子,将child指向较大者
                ++Child;
        
        if (Item < Data[Child])
        {    // 如果父结点小于左孩子,交换
            Data[Current] = Data[Child];
            Current       = Child;
            Child         = LeftChildOf(Current);
        }
        else
            break;
    }
    Data[Current] = Item;
}

template <class Elem>
inline int HeapTree<Elem>::ParentOf(int Node)
{
    assert(Node > 0);
    return (Node - 1) / 2;
}

template <class Elem>
inline int HeapTree<Elem>::LeftChildOf(int Node)
{
    return (Node * 2) + 1;
}

template <class Elem>
Elem HeapTree<Elem>::getData(int ElemNum) {
    return Data[ElemNum];
}