//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/7/1.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：使用两个栈实现队列
 2. 思路： 每次入队数据插入stack1中；
          每次出队，判断stack2中是否有元素，如果没有stack1中的元素出栈入栈到stack2中，然后stack2出栈元素；
          如果stack1，stack2都为空，则说明队空；
 
 3. 有待补充：改成模板类
            输入那一块可以优化，cin特性
 */

#include <iostream>
#include <vector>
#include <stack>



using namespace std;


class queue
{
public:
    
    //queue();
    //~queue();
    
    // 入队成员函数
    void push(int node)    // 入队，直接插入
    {
        stack_in.push(node);
    }
    
    
    // 出队成员函数
    int pop()
    {
        if( stack_in.empty() && stack_out.empty())
            cout << "当前队列为空" << endl;
        
        if(stack_out.empty()){
            while(!stack_in.empty())  // 把stack_in中的元素出栈，放到stack_out中
            {
                int tmp = stack_in.top();
                stack_in.pop();
                stack_out.push(tmp);
            }
        }
        
        int res = stack_out.top();
        stack_out.pop();
        
        return res;
    }
    
    
    // 队的判空函数
    bool empty()
    {
        return (stack_in.empty() == true && stack_out.empty() == true );
    }

private:
    stack<int> stack_in;
    stack<int> stack_out;
    
};

int main(){

    queue q;
    cout << "请输入队列元素：";
    int a;
    // 这里用了cin连续输入，结束输入有几种方法：1.文件结束符（win中是ctrl+z,OS X是ctrl+d)；2.遇到无效输入，要求int，输入不是int即是无效
    while(cin >> a)
    {
        q.push(a);
    }
    
    cout << endl;
    cout << "队列出队是：";
    while(!q.empty())
    {
        int tmp = q.pop();
        cout << tmp << ' ';
    }
    cout << endl;
    
    return 0;
}
