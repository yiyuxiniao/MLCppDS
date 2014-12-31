//
//  MLStack.h
//  MLCppDS
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#ifndef __MLCppDS__MLStack__
#define __MLCppDS__MLStack__

#include <assert.h>

template <class Elem>
class MLStack
{
public:
    /**
     *  一个固定大小的栈
     */
    MLStack(int MaxSize=500);
    MLStack(const MLStack<Elem> &OtherStack);
    ~MLStack(void);
    
    /**
     *  放入顶部
     *
     *  @param Item 元素
     */
    void        Push(const Elem &Item);
    
    /**
     *  拿出
     *
     *  @return 顶部元素拿出
     */
    Elem        Pop(void);
    
    /**
     *  寻找
     *
     *  @param Depth 深度,距离顶部的距离
     *
     *  @return 元素
     */
    const Elem &Peek(int Depth) const;
    
protected:
    Elem     *Data;
    int       CurrElemNum;
    const int MAX_NUM;
};
#endif /* defined(__MLCppDS__MLStack__) */
