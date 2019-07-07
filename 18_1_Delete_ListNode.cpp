
//
//  Created by mark on 2019/7/7.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：给定单向链表头指针和一个节点指针，删除给定节点。
 2. 思路：用给点节点的下一个节点覆盖当前节点，然后把下一个节点删除。  time: O(1)
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
};


void DeleteNode(ListNode* pHead, ListNode* pDelete)
{
    if(!pHead || !pDelete)
        return;
    
    // 要删除的节点不是尾节点
    if(pDelete->next != nullptr)
    {
        ListNode* pTemp = pDelete->next;
        pDelete->val = pTemp->val;
        pDelete->next = pTemp->next;
        
        delete pTemp;
        pTemp = nullptr;
    }
    
    // 链表只有一个节点，要删除头结点
    else if(pDelete == pHead)
    {
        delete pDelete;
        pDelete = nullptr;
        pHead = nullptr;
    }
    else   // 要删除的节点是尾节点，没有下一个节点，同样要从头节点遍历，找到尾节点的前节点；
    {
        ListNode* pre = pHead;
        while(pre->next != pDelete)   // 一直找到尾节点
        {
            pre = pre->next;
        }
        pre->next = nullptr;
        delete pDelete;
        pDelete = nullptr;
    }
    
    
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
    
    ConnectListNodes(p1, p2);
    ConnectListNodes(p2, p3);
    ConnectListNodes(p3, p4);
    
    cout << "原链表是：";
    PrintList(p1);
    cout << endl;
    
    cout << "删节点后：";
    DeleteNode(p1, p3);
    PrintList(p1);
    cout << endl;
    
    
    return 0;
}


