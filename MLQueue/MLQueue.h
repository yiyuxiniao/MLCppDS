//
//  MLQueue.h
//  MLCppDS
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#ifndef __MLCppDS__MLQueue__
#define __MLCppDS__MLQueue__

#include <assert.h>

template <class Elem>
class Queue
{
public:
    Queue(int MaxSize=500);
    Queue(const Queue<Elem> &OtherQueue);
    ~Queue(void);
    
    /**
     *  进队列
     *
     *  @param Item 最后的元素
     */
    void       Enqueue(const Elem &Item);
    
    /**
     *  出队列
     *
     *  @return 最前的元素
     */
    Elem       Dequeue(void);
    
    /**
     *  队列长度
     *
     *  @return 队列中元素的个数
     */
    int ElemNum(void);
    
protected:
    Elem     *Data;
    const int MAX_NUM;
    
    /**
     *  队列首尾
     */
    int       Beginning, End;
    
    /**
     *  元素个数
     */
    int       ElemCount;
};
#endif /* defined(__MLCppDS__MLQueue__) */
