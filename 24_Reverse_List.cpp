
//
//  Created by mark on 2019/7/8.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：24.链表反转
 2. 思路：主要是防止断链，定义前中后三个节点，每次后移
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>

using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
}LN,*pLN;

/*
 主要的测试问题：
 1. 链表头指针是nullptr
 2. 输入链表只有一个节点
 3. 正常链表
 */
// 反转链表
ListNode* ReverseList(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    
    ListNode* NewHead = nullptr;
    ListNode* pre = nullptr;
    ListNode* cur = pHead;
    
    while(cur != nullptr)
    {
        ListNode* next = cur->next;
        
        if(next == nullptr)    // 如果链表只有一个头结点
            NewHead = cur;
        
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return NewHead;
}


// ------------------------------------------------------------------------------------------------------------------------

// 辅助函数，创建链表
ListNode* CreatListNode(int val)
{
    ListNode* node = new ListNode();
    node->val = val;
    node->next = nullptr;
    
    return node;
}

// 辅助函数，连接两个链表节点
void ConnectListNodes(ListNode* pre, ListNode* cur)
{
    pre->next = cur;
}

// 遍历链表
void PrintList(ListNode* node)
{
    while(node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
}


int main(){

    ListNode* p1 = CreatListNode(1);
    ListNode* p2 = CreatListNode(2);
    ListNode* p3 = CreatListNode(3);
    ListNode* p4 = CreatListNode(4);
    ListNode* p5 = CreatListNode(5);
    ListNode* p6 = CreatListNode(6);
    
    
    ConnectListNodes(p1, p2);
    ConnectListNodes(p2, p3);
    ConnectListNodes(p3, p4);
    ConnectListNodes(p4, p5);
    ConnectListNodes(p5, p6);
    
    cout << "原链表是：";
    PrintList(p1);
    cout << endl;
    
    cout << "反转后是：";
    ListNode* p = ReverseList(p1);
    PrintList(p);
    cout << endl;
    
    return 0;
}


