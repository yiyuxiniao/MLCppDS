//
//  MLHashTable.h
//  MLCppDS
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#ifndef __MLCppDS__MLHashTable__
#define __MLCppDS__MLHashTable__
/**
 *  只是key-value编码了,主要区别在于hash算法,其它也没什么重要内容.
 *  有空学习下STL的map.
 */
template<class T>
class DataType
{
public:
    T key;
    DataType(T k):key(k){}
    
    DataType(void){}
    
    bool operator ==(const DataType &a)
    {
        return key == a.key;
    }
    
    bool operator !=(const DataType &a)
    {
        return key != a.key;
    }
};

enum KindOfItem{Empty, Active, Delete};

template<class T>
class HashItem
{
public:
    DataType<T> data;
    KindOfItem info;
    HashItem(KindOfItem i = Empty):info(i){}
    HashItem(DataType<T> d, KindOfItem i = Empty):data(d),info(i){}
    
    bool operator ==(const HashItem & a)
    {
        return a.data == data;
    }
    
    bool operator !=(const HashItem &a)
    {
        return a.data != data;
    }
    
};

template<class T>
class HashTable
{
public:
    const int size;
    HashItem<T> *ht;
    int FindItem(const HashItem<T> &a);
    int InsertItem(const HashItem<T> &a);
    int DeleteItem(const HashItem<T> &a);
    
    HashTable(int k);
    ~HashTable();
    
};
#endif /* defined(__MLCppDS__MLHashTable__) */
