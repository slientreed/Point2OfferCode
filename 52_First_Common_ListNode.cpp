
//
//  Created by mark on 2019/7/24.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：51. 两个链表的第一个公共节点
 2. 思路：1. 暴力搜索，每次搜索一个节点，同时搜索一遍第二个。 time:O（n^2）
         2. 借助栈： 从后向前找，找到第一个不相同的后一个节点即是。所以把链表节点都入栈，然后挨个出栈对比，找到第一个不相同的下个节点； O(m+n)
         3. 为了解决两个链表不齐的问题，可以先遍历两个链表长度，找出长度差n，然后长的链表先走n步，短的再跟上对比；   time: O(m+n)
         4. 使用3的方法，可以 list1: list1 + list2   ;   list2: list2 + list1。这样两个链表一样长，且相同的都在最后，同步遍历即可
 */



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <assert.h>

#include <cstdio>
#include <fstream>
#include <map>
#include <set>

using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
}LN, *pLN;


// 方法3的实现：计算两个链表长度差
int GetListLength(ListNode* pHead);
ListNode* FindFirstCommonNode1(ListNode* pHead1, ListNode* pHead2)
{

    int length1 = GetListLength(pHead1);
    int length2 = GetListLength(pHead2);
    int diff;
    ListNode* list_long;
    ListNode* list_short;
    if(length1 > length2)
    {
        diff = length1 - length2;
        list_long = pHead1;
        list_short = pHead2;
    }
    else
    {
        diff = length2 - length1;
        list_long = pHead2;
        list_short = pHead1;
    }
    
    // 长的链表先走diff步，再同步走
    for(int i = 0; i < diff; i++)
        list_long = list_long->next;
    
    while(list_long != nullptr && list_short != nullptr && list_short->val != list_long->val)
    {
        list_long = list_long->next;
        list_short = list_short->next;
    }
    
    ListNode* CommonNode = list_long;        // 找到公共节点
    
    return CommonNode;
}

// 计算链表长度
int GetListLength(ListNode* pHead)
{
    int length = 0;
    ListNode* node = pHead;
    while(node != nullptr){
        length++;
        node = node->next;
    }
    
    return length;
}



// 方法2的实现，借助栈，从后往前对比
ListNode* FindFirstCommonNode2(ListNode* pHead1, ListNode* pHead2)
{
    
    ListNode* left = pHead1;
    ListNode* right = pHead2;
    stack<ListNode*> stack_left;
    stack<ListNode*> stack_right;
    
    // 两个节点依次入栈
    while(left != nullptr)
    {
        stack_left.push(left);
        left = left->next;
    }
    while(right != nullptr)
    {
        stack_right.push(right);
        right = right->next;
    }
    
    //开始弹出，对比元素
    while(!stack_left.empty() && !stack_right.empty())
    {
        left = stack_left.top();
        right = stack_right.top();
        if(left->val != right->val)             // 找到第一个不相等的元素，结束循环，下一个节点即是
            break;
        
        stack_left.pop();
        stack_right.pop();
    }
    
    if(left != right)
        return left->next;
    else
        return NULL;
}

// 辅助函数 --------------------------------------------------------------------------------------------

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



int main()
{
    
    ListNode* pHead1 = CreatListNode(1);
    ListNode* p2 = CreatListNode(2);
    ListNode* p3 = CreatListNode(3);
    ListNode* p4 = CreatListNode(4);
    ConnectListNodes(pHead1, p2);
    ConnectListNodes(p2, p3);
    ConnectListNodes(p3, p4);
    
    
    ListNode* pHead2 = CreatListNode(6);
    ListNode* p5 = CreatListNode(5);
    ListNode* p6 = CreatListNode(6);
    ListNode* p7 = CreatListNode(3);
    ListNode* p8 = CreatListNode(4);
    ConnectListNodes(pHead2, p5);
    ConnectListNodes(p5, p6);
    ConnectListNodes(p6, p7);
    ConnectListNodes(p7, p8);
    
    cout << "第一个链表是：";
    PrintList(pHead1);
    cout << endl;
    cout << "第二个链表是：";
    PrintList(pHead2);
    cout << endl;
    
    ListNode* C1 = FindFirstCommonNode1(pHead1, pHead2);
    ListNode* C2 = FindFirstCommonNode2(pHead1, pHead2);
    cout << "公共子节点是：" << C1->val << " ";
    cout << C2->val << endl;
    
    return 0;
}


