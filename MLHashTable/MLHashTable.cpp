//
//  MLHashTable.cpp
//  MLCppDS
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#include "MLHashTable.h"

template<typename T>
HashTable<T>::HashTable(int k):
size(k),
ht(0)
{
    ht = new HashItem<T>[size];
}


template<typename T>
HashTable<T>::~HashTable()
{
    if (ht)
        delete[] ht;
}

template<typename T>
int HashTable<T>::FindItem(const HashItem<T> &a)
{
    int i = a.data.key%size;
    int j = i;
    while (ht[j].info == Active && ht[j].data != a.data)
    {
        j = (j+1)%size;
        if (j == i)
        {
            return -size;
        }
    }
    
    if (ht[j].info == Active)
    {
        cout<<"发现数据"<<endl;
        return j;
    }
    else
    {
        return -j;
    }
    return 0;
}

template<typename T>
int HashTable<T>::InsertItem(const HashItem<T> &a)
{
    int i = FindItem(a);
    if (i > 0 || (i==0 && ht[0].info == Active))
    {
        return -1;
    }
    if (i == -size)
    {
        cout<<"hashtable已满，插入失败"<<endl;
        return -1;
    }
    else
    {
        ht[-i] = a;
        ht[-i].info = Active;
    }
    cout<<"插入成功"<<endl;
    return i;
    
}

template<typename T>
int HashTable<T>::DeleteItem(const HashItem<T> &a)
{
    int i = FindItem(a);
    cout<<i<<endl;
    if (i < 0|| (i==0 && ht[0].info != Active))
    {
        cout<<"无此数据"<<endl;
        return -1;
    }
    ht[i].info = Delete;
    cout<<"删除成功"<<endl;
    return i;
    
}