
//
//  Created by mark on 2019/7/8.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：25.合并两个有序链表
 2. 思路：不要断链，且递增;考虑特殊输入（空链表）
         1. 用两个指针分别遍历两个链表，每次找到小的节点插入新链表中；
         2. 递归方法，相当于每次比较两个头结点
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


// 1. 非递归
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
        return pHead2;
    else if(pHead2 == nullptr)
        return pHead1;
    
    ListNode* newHead = nullptr;    // 先生成新的头结点
    ListNode* cur = nullptr;       // 作为新链表的遍历节点
    
    if(pHead1->val < pHead2->val)
    {
        newHead = pHead1;
        pHead1 = pHead1->next;
        cur = newHead;
    }
    else
    {
        newHead = pHead2;
        pHead2 = pHead2->next;
        cur = newHead;
    }
        
    
    while(pHead1 != nullptr && pHead2 != nullptr)  // 遍历两个链表
    {
        if(pHead1->val < pHead2->val)
        {
            cur->next = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            cur->next = pHead2;
            pHead2 = pHead2->next;
        }
        cur = cur->next;
    }
    
    while(pHead1 != nullptr)       // 继续添加剩下的链表
    {
        cur->next = pHead1;
        pHead1 = pHead1->next;
    }
    while(pHead2 != nullptr)
    {
        cur->next = pHead2;
        pHead2 = pHead2->next;
    }
    
    return newHead;
}


// 2. 递归，相当于每次比较两个链表的头结点，然后添加;合并的那个链表头结点移动一个再递归
ListNode* MergeList_Recu(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
        return pHead2;
    if(pHead2 == nullptr)
        return pHead1;
    
    ListNode* newHead = nullptr;   // 定义新的头结点
    if( pHead1->val < pHead2->val)
    {
        newHead = pHead1;
        newHead->next = MergeList_Recu(pHead1->next, pHead2);   // 递归，从链表1头结点的下个节点开始
    }
    else
    {
        newHead = pHead2;
        newHead->next = MergeList_Recu(pHead2->next, pHead1);
    }
    
    return newHead;
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

    ListNode* pHead1 = CreatListNode(1);
    ListNode* p2 = CreatListNode(2);
    ListNode* p3 = CreatListNode(5);
    
    ListNode* pHead2 = CreatListNode(2);
    ListNode* p5 = CreatListNode(3);
    ListNode* p6 = CreatListNode(6);
    
    
    ConnectListNodes(pHead1, p2);
    ConnectListNodes(p2, p3);
    ConnectListNodes(pHead2, p5);
    ConnectListNodes(p5, p6);
    
    cout << "原链表1是：";
    PrintList(pHead1);
    cout << endl;
    
    cout << "原链表2是：";
    PrintList(pHead2);
    cout << endl;
    
    cout << "俩合并后是：";
    ListNode* pNew = MergeList_Recu(pHead1, pHead2);
    PrintList(pNew);
    cout << endl;
    
    return 0;
}


