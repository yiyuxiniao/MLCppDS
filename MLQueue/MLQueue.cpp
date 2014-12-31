//
//  MLQueue.cpp
//  MLCppDS
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#include "MLQueue.h"

template <class Elem>
Queue<Elem>::Queue(int MaxSize) :
MAX_NUM( MaxSize )
{
    Data      = new Elem[MAX_NUM + 1];
    Beginning = 0;
    End       = 0;
    ElemCount = 0;
}

template <class Elem>
Queue<Elem>::Queue(const Queue &OtherQueue) :
MAX_NUM( OtherQueue.MAX_NUM )
{
    Beginning = OtherQueue.Beginning;
    End       = OtherQueue.End;
    ElemCount = OtherQueue.ElemCount;
    
    Data      = new Elem[MAX_NUM + 1];
    for (int i = 0; i < MAX_NUM; i++)
        Data[i] = OtherQueue.Data[i];
}

template <class Elem>
Queue<Elem>::~Queue(void)
{
    delete[] Data;
}

template <class Elem>
void Queue<Elem>::Enqueue(const Elem &Item)
{
    assert( ElemCount < MAX_NUM );
    Data[ End++ ] = Item;
    ++ElemCount;
    
    if (End > MAX_NUM)
        End -= (MAX_NUM + 1);
}

template <class Elem>
Elem Queue<Elem>::Dequeue(void)
{
    assert( ElemCount > 0 );
    
    Elem ReturnValue = Data[ Beginning++ ];
    --ElemCount;

    if (Beginning > MAX_NUM)
        Beginning -= (MAX_NUM + 1);
    
    return ReturnValue;
}

template <class Elem>
inline int Queue<Elem>::ElemNum(void)
{
    return ElemCount;
}