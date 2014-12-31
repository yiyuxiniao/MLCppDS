//
//  MLStack.cpp
//  MLCppDS
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#include "MLStack.h"

template <class Elem>
MLStack<Elem>::MLStack(int MaxSize) :
MAX_NUM( MaxSize )
{
    Data = new Elem[MAX_NUM];
    CurrElemNum = 0;
}

template <class Elem>
MLStack<Elem>::~MLStack(void)
{
    delete[] Data;
}

template <class Elem>
inline void MLStack<Elem>::Push(const Elem &Item)
{
    assert(CurrElemNum < MAX_NUM);
    Data[CurrElemNum++] = Item;
}

template <class Elem>
inline Elem MLStack<Elem>::Pop(void)
{
    assert(CurrElemNum > 0);
    return Data[--CurrElemNum];
}

template <class Elem>
inline const Elem &MLStack<Elem>::Peek(int Depth) const
{
    assert(Depth < CurrElemNum);
    return Data[ CurrElemNum - (Depth + 1) ];
}