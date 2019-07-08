
//
//  Created by mark on 2019/7/7.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：22.链表中倒数第k个节点
 2. 思路：双指针解法
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

/*
 1. 定义两个指针，first，last。
 2. first先走k-1步，然后last跟first同时走，first到链表尾部，last指向倒数第k个节点；
 3. 注意输入k是0，还有链表节点数小于k的情况
 */

struct ListNode
{
    int val;
    ListNode* next;
}LN,*pLN;


// 找倒数第k大的节点
ListNode* FindKthFromTail(ListNode* pHead, unsigned int k)
{
    if(pHead == nullptr)
        return NULL;
    
    ListNode* first = pHead;
    ListNode* last = pHead;
    
    for(int i = 0; i < k - 1; ++i)
    {
        if(first->next != nullptr)
            first = first->next;
        else
            return NULL;
    }
    
    while(first->next != nullptr)
    {
        first = first->next;
        last = last->next;
    }
    
    return last;
}



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
    
    int k;
    cout << "输入要查倒数第几个节点：";
    cin >> k;
    ListNode* res = FindKthFromTail(p1, k);
    if(res == nullptr)
        cout << "没有这个节点" << endl;
    else
        cout << "得到的倒数第" << k << "个节点值是:" << res->val << endl;
    
    return 0;
}


