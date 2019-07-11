
//
//  Created by mark on 2019/7/10.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：30.包含min函数的栈，定义栈的数据结构，在该类型中实现一个能得到栈的最小元素的min函数
 2. 思路：调用一个辅助min栈，每次压栈的同时往min栈压入当前栈内的最小值（把之前最小值和当前最小值相比较的小者）;
 */



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <assert.h>

using namespace std;


class minStack
{

public:
    
    // 压栈操作
    void push(int value)
    {
        s_data.push(value);
        
        if(s_min.empty() || value < s_min.top())
            s_min.push(value);
        else
            s_min.push(s_min.top());
    }

    // 出栈操作
    void pop()
    {
        assert(s_data.size() > 0 && s_min.size() > 0);
        
        s_data.pop();
        s_min.pop();
    }
    
    // 返回栈顶元素
    int top()
    {
        assert(s_data.size() > 0 && s_min.size() > 0);
        
        return s_data.top();
    }
    
    // 返回栈中最小值
    int min_top()
    {
        return s_min.top();
    }

    // 判空
    bool empty()
    {
        return s_data.empty();
    }
    
    
private:
    stack<int> s_data;    // 正常数据栈
    stack<int> s_min;  // 保存当前最小值栈
    
};






int main(){

    minStack s;
    
    s.push(4);
    s.push(1);
    s.push(2);
    s.push(3);
    
    int a = s.min_top();
    s.pop();
    int b = s.min_top();
    cout << a << endl;
    cout << b << endl;
    
    return 0;
}


