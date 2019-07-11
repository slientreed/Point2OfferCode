
//
//  Created by mark on 2019/7/10.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：31.栈的压入，弹出序列：给出两个序列，一个是栈的压入，一个是栈的弹出，判断第二个是否可能是栈的弹出顺序
 2. 思路：开辟一个辅助栈，模拟出栈入栈过程。入栈序列push不断入栈，按照出栈序列模拟
         1. 如果下一个要弹出的的数字刚好是辅助栈顶的数字，直接弹出；
         2. 如果下个弹出的数字不在辅助栈顶，把压栈序列push中还么有入栈的数字压入辅助栈，知道把下个要弹出的数字压入栈顶。
         3. 如果push中所有数字都压入栈还没找到下一个弹出的数字，则pop不是一个弹出序列。
 */



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <assert.h>

using namespace std;


bool isPopOrder(vector<int> push_vec, vector<int> pop_vec)
{
    if(push_vec.size() == 0 || pop_vec.size() == 0)
        return false;
    
    stack<int>s;
    s.push(push_vec[0]);
    int push, pop;
    
    for(push = 0,pop = 0; push < push_vec.size() && pop < pop_vec.size();)
    {
        if(!s.empty() && s.top() == pop_vec[pop])   // 下一个要出栈的数字等于栈顶数字
        {
            s.pop();
            ++pop;
        }
        else                                    // 否则从压栈队列中向辅助栈压入
        {
            ++push;                         // 注意这里有点小技巧，push增1要放在前面，因为循环之前就把push_vec[0]压入栈了；
            s.push(push_vec[push]);
        }
    }
    
    if(s.empty())
        return true;
    else
        return false;
}




int main(){

    
    vector<int> push{1,2,3,4,5};
    vector<int> pop1{4,5,3,2,1};
    vector<int> pop2{4,3,5,1,2};
    
    if(isPopOrder(push, pop2))
        cout << "可能是弹出序列！" << endl;
    else
        cout << "不可能是弹出序列！" << endl;
    
    
    return 0;
}


