//
//  main.cpp
//  MLQueue
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#include <iostream>
#include "MLQueue.h"
#include "MLQueue.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // 类文件名与类名不相同亦可.
    Queue<int> qu(50);
    qu.Enqueue(30);
    qu.Enqueue(20);
    cout<<qu.Dequeue()<<endl;
}
