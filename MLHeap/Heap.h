//
//  Heap.h
//  MLCppDS
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#ifndef __MLCppDS__Heap__
#define __MLCppDS__Heap__

#include <assert.h>
/**
 *  堆(heap): 指的是数据结构中的堆,而不是内存中的堆(实现方式可能不一样).
 *  堆通常可以看做一棵树,且满足:
 *  1. 堆中任意节点的值总是不大于(不小于)其子节点的值-- 最大树(堆)/最小树(堆)
 *  2. 总是完全树.
 *  常见的堆有二叉堆、左倾堆、斜堆、二项堆、斐波那契堆等
 *  这里实现的是最简单的基于数组的二叉最大堆,由于实现方式的不一样,根结点索引值有0(1)的区别,导致了左孩子和父结点计算方式的不同.
 *  堆可以看作是一个有优先级的队列,最重要的节点是根(root).
 */

template <class Elem>
class HeapTree
{
public:
    HeapTree(int MaxSize=500);
    HeapTree(const HeapTree<Elem> &OtherTree);
    HeapTree(Elem *Array, int ElemNum, int MaxSize);
    ~HeapTree(void);
    
    /**
     *  堆排序算法
     *
     *  @return 元素
     */
    Elem *Sort(void);
    
    /**
     *  堆内添加元素,对应upheap/downheap过程,必需理解这两个过程.
     *
     *  @param Item 元素
     *
     *  @return 成功 或 失败
     */
    bool Add(const Elem &Item);
    
    /**
     *  堆内删除元素
     *
     *  @return 元素
     */
    Elem Remove(void);
    
    /**
     *  堆内节点数
     *
     *  @return 堆内节点数
     */
    int GetSize(void);
    
    Elem getData(int ElemNum);
    
protected:
    Elem     *Data;
    int       CurrentNum;
    const int MAX_SIZE;
    
    void ShiftUp(int Node);      // upheap过程
    void ShiftDown(int Node);    // dwonheap过程
    
    inline int ParentOf(int Node);      // 父节点索引值
    inline int LeftChildOf(int Node);   // 左孩子索引值
};
#endif /* defined(__MLCppDS__Heap__) */
