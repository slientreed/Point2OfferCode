//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/6/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 题目：从尾到头打印链表，注意是反向打印
 2. 思路：栈； 递归
 3. 实现：栈方法，从头遍历链表，每遍历一个放入栈中；最后在出栈
         递归方法，每访问一个链表，先递归输出它后面的节点，在输出该节点本身
 
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;


// 定义链表结构体
struct ListNode
{
public:
    int val;
    ListNode* next;
};


// 1. 借助栈的方法
void printListRevere(ListNode* pHead){
    
    stack<ListNode*> s;         // 注意这里栈中存储的是list指针
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        s.push(pNode);
        pNode = pNode->next;
    }
    
    cout << "链表逆序输出是：";
    while(!s.empty())
    {
        pNode = s.top();
        cout <<  pNode->val << "->";
        s.pop();
    }
    cout << endl;
}

/*
// 2. 借助递归方法
void printListRevere(ListNode* pHead){
    
    
        if(pHead != nullptr)
        {
            if(pHead->next != nullptr)
            {
                printListRevere(pHead->next);
            }
            
            cout << pHead->val << "->";
        }
}
*/


int main(){
    
    ListNode list[100];  // 这里是用自己定义的list结构体，如果直接用list容器更简单
    int n;
    cout << "要输入几个数字(小于100)：";
    cin >> n;
    
    for(int i = 0; i < n; ++i){   // 构建一个list
        cout << "请输入第" << i+1 << "个数字：";
        int tmp;
        cin >> tmp;
        list[i].val = tmp;
        list[i].next = &list[i+1];
    }
    list[n-1].next = NULL;
    
    cout << "原链表是：";
    for(int i = 0; i < n-1; ++i)
    {
        cout << list[i].val << "->";
    }
    cout << list[n-1].val <<endl;
    
    cout << "链表逆序输出：";
    printListRevere(list);
    cout << endl;
    
    return 0;
}




