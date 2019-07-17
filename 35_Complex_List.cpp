
//
//  Created by mark on 2019/7/12.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：35.复杂链表的复制，复杂链表有两个不同指针，如何实现复制。
 2. 思路：1. 直接复制，先复制后指针，再复制其他指针； O(n^2)
         2. 哈希表，记录对应的指针；O(n)
         3. 在原链表的尾部复制；  O(n)
 
 */



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <assert.h>

using namespace std;

struct ComplexListNode
{
    int val;
    ComplexListNode* next;
    ComplexListNode* bling;
};

/* 使用第三个方法：分步实现
 1. 复制原始链表的每个节点，并放在原链表节点的后面
 2. 设置复制出来的节点的bling指向
 3. 拆分长链表
 */


// 1. 在原始链表的后面复制每一个前面节点
void CloneNode(ComplexListNode* pHead)
{
    if(pHead == nullptr) return;
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        ComplexListNode* pTemp = new ComplexListNode();   // 复制一个新的节点
        pTemp->val = pNode->val;
        pTemp->next = pNode->next;
        pNode->next = pTemp;
        
        pTemp->bling = nullptr;
        
        pNode = pTemp->next;         // 往后走一步
    }
}


// 2. 设置复制节点的bling指针。
void ConntectBlingNode(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        ComplexListNode* pTemp = pNode->next;
        if(pNode->bling != nullptr)
        {
            pTemp->bling = pNode->bling->next;     // 找到复制节点的bling指向
        }
        
        pNode = pTemp->next;
    }
    
}

// 3. 拆分长链表，奇数上的节点为原链表，偶数上为新的链表
ComplexListNode* ReconntectNode(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pCloneHead = nullptr;
    ComplexListNode* pCloneNode = nullptr;
    
    if(pNode != nullptr)
    {
        pCloneHead = pCloneNode = pNode->next;       // 记录复制链表的头结点
        pNode->next = pCloneNode->next;
        pNode = pNode->next;
    }
    
    while (pNode != nullptr) {
        pCloneNode->next = pNode->next;   // 复制的链表节点往后移动
        pCloneNode = pCloneNode->next;
        
        pNode->next = pCloneNode->next;   // 原链表节点向后移动
        pNode->next = pNode->next;
        
    }
    
    return pCloneHead;
}


// 把三步结合起来，完成复杂链表的复制
ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNode(pHead);
    ConntectBlingNode(pHead);
    ComplexListNode* CloneHead =  ReconntectNode(pHead);
    return CloneHead;
}





int main(){

    
    
    
    
    
    return 0;
}


