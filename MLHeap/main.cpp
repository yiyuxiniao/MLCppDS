//
//  main.cpp
//  MLHeap
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#include <iostream>
#include "Heap.h"
#include "Heap.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
    int array[10]={5,10,3,4,6,8,90,34,50,30};
    HeapTree<int> *hp = new HeapTree<int>(array, 10, 50);
    for (int i=0; i<10; i++) {
        cout<<hp->getData(i)<<" ";
    }
    cout<<endl;
    hp->Add(70);
    for (int i=0; i<11; i++) {
        cout<<hp->getData(i)<<" ";
    }
    cout<<endl;
    
    int *a=hp->Sort();
    for (int i=0; i<11; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
