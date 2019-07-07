
//
//  Created by mark on 2019/7/7.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：删除链表重复节点
 2. 思路：1.每次判断当前节点的值是否和下个节点值重复；
         2. 重复就继续循环找下个不重复的点，不重复就之前把当前节点的前一个节点连接到不重复的节点；
         3. 重复步骤1，2，直到节点尾。
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
    ListNode(int x):val(x),next(nullptr){}  // 构造函数
};

ListNode* DeleteDuplication(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    
    // 注意这里，有可能头结点也重复被删掉，所以定义一个节点指向头结点
    ListNode* start = new ListNode(-1);
    start->next = pHead;
    
    ListNode* pre = start;    // 指向当前节点的前一个节点
    ListNode* cur = pHead;    // 指向当前判断是否重复的节点
    
    while(cur != nullptr && cur->next != nullptr)
    {
        if(cur->val == cur->next->val)   // 如果发现重复值
        {
            while(cur->next != nullptr && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            
            pre->next = cur->next;     // 当前cur指向后一个不重复的节点
        }
        else
        {
            pre = pre->next;
            cur = cur->next;
        }
    }
    
    return start->next;
}


// -------------------------------------------------------------------------------------------------------------------


// 辅助函数，创建链表
ListNode* CreatListNode(int val)
{
    ListNode* node = new ListNode(-1);
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

    ListNode* head = CreatListNode(0);
    ListNode* p1 = CreatListNode(1);
    ListNode* p2 = CreatListNode(2);
    ListNode* p3 = CreatListNode(3);
    ListNode* p33 = CreatListNode(3);
    ListNode* p4 = CreatListNode(4);
    
    ConnectListNodes(head, p1);
    ConnectListNodes(p1, p2);
    ConnectListNodes(p2, p3);
    ConnectListNodes(p3, p33);
    ConnectListNodes(p33, p4);
    
    cout << "原链表是：";
    PrintList(head);
    cout << endl;
    
    cout << "删节点后：";
    DeleteDuplication(head);
    PrintList(head);
    cout << endl;
    
    
    return 0;
}


