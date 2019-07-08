
//
//  Created by mark on 2019/7/8.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：23.找链表中环的入口节点
 2. 思路：判断是否有环；找到环中任一节点；计算环的个数；找到环的入口节点。
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

/*
 1. 如果有环，先找到环中任一节点： 双指针，快指针每次走两个节点，慢的走一个；如果快指针追上慢指针说明有环，且上的节点一定在环内；如果快指针到尾都没追上，没环
 2. 找到环中任一个节点，遍历一遍环，计算环的个数n；
 3. 定义两个指针，前面一个先走n步，然后后面跟前面一起走，相遇的节点就是环入口节点。
 */

struct ListNode
{
    int val;
    ListNode* next;
}LN,*pLN;


// 判断是否有环，有返回环中任一节点
ListNode* hasCycleList(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;
    
    ListNode* slow = pHead;
    
    ListNode* fast = pHead->next;
    
    while(fast != nullptr && slow != nullptr)
    {
        if(fast == slow)
            return fast;
        
        slow = slow->next;
        fast = fast->next;
        if(fast != nullptr)
            fast = fast->next;
    }
    
    return nullptr;
}


// 如果有环，计算链表环的长度
int LengthOfLoop(ListNode* node)
{
    int num = 0;
    //ListNode* p = hasCycleList(pHead);
    if(node == nullptr)
        return num;
    
    ListNode* cur = node->next;
    ++num;
    while(cur != node)
    {
        cur = cur->next;
        ++num;
    }
    
    return num;
}

// 求环的入口节点：两个指针，前指针先走环的长度步，后指针再走，两者相遇的就是入口节点
ListNode* EntryOfLoop(ListNode* pHead)
{
    ListNode* meeting = hasCycleList(pHead);
    int n = LengthOfLoop(meeting);
    if(n == 0)
        return nullptr;
    
    ListNode* first = pHead;
    ListNode* last = pHead;
    for(int i = 0; i < n; ++i)   // 先移动前面一个指针n步
    {
        first = first->next;
    }
    
    while(first != last)
    {
        first = first->next;
        last = last->next;
    }
    
    return last;
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
    ConnectListNodes(p6, p4);
    
    /*
    cout << "原链表是：";
    PrintList(p1);
    cout << endl;
    */
    
    ListNode* p = hasCycleList(p1);
    int n = LengthOfLoop(p);
    cout << "环的节点个数是：" << n << endl;
    
    ListNode* meet = EntryOfLoop(p1);
    cout << "环的入口节点是：" << meet->val << endl;

    
    return 0;
}


