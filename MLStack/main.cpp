//
//  main.cpp
//  MLStack
//
//  Created by mlyixi on 14/12/31.
//  Copyright (c) 2014年 mlyixi. All rights reserved.
//

#include <iostream>
#include "MLStack.h"
#include "MLStack.cpp" //模板类的可恶!!!!

using namespace std;

int main(int argc, const char * argv[]) {
    MLStack<int> st(50);
    st.Push(5);
    st.Push(10);
    st.Push(20);
    st.Push(30);
    cout<<st.Peek(2)<<endl;
    cout<<st.Pop()<<endl;
    cout<<st.Peek(2)<<endl;
    
}
