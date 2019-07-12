
//
//  Created by mark on 2019/7/12.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：32.3.分行从上到下之字形打印二叉树。
 2. 思路：使用两个栈，打印某一层时，把下一层子节点保存到对应的栈中；
         1. 如果当前打印的是奇数层，先保存左子节点，在保存右子节点到另一个栈；
         2. 如果当前打印的是偶数层，先保存右子节点，再保存左子节点到另一个栈；
 */



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <assert.h>

using namespace std;



struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
}TN,*pTN;



// 之字形遍历
void LevelOrder_Lines_Reverse(BinaryTreeNode* root)
{
    if(root == nullptr)
        return;
    
    stack<BinaryTreeNode*> s[2];   // 使用两个栈
    int cur = 0;                  // 充作奇偶两个不同栈的标志
    int next = 1;
    
    s[cur].push(root);
    while(!s[0].empty() || !s[1].empty())
    {
        
        BinaryTreeNode* pNode = s[cur].top();
        s[cur].pop();
        cout << pNode->val << " ";              // 打印节点值
        
        
        if(cur == 0)                            // cur=0说明栈放的是奇数层；
        {
            if(pNode->left != nullptr)          // 则偶数层要先入栈左，再入栈右节点；出队的时候：右左顺序
                s[next].push(pNode->left);
            if(pNode->right != nullptr)
                s[next].push(pNode->right);
        }
        else                                  // 当前是偶数层，next是奇数
        {
            if(pNode->right != nullptr)      // 奇数层，先入栈右，再左
                s[next].push(pNode->right);
            if(pNode->left != nullptr)
                s[next].push(pNode->left);
        }
        
        
        
        if(s[cur].empty())         // 当前层数打印完毕
        {
            cur = 1 - cur;         // 交换栈打印下一层内容
            next = 1 - next;
            cout << endl;
        }
        
    }
    
}




//辅助函数 ------------------------------------------------------------------------------------------------------------------------

// 构建树节点
BinaryTreeNode* CreateTreeNode(int val)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->val = val;
    pNode->left = nullptr;
    pNode->right = nullptr;
    
    return pNode;
}

// 连接树节点
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}


// 销毁树
void DestroyTree(BinaryTreeNode* root)
{
    if(root != nullptr)
    {
        BinaryTreeNode* left = root->left;
        BinaryTreeNode* right = root->right;
        
        delete root;
        root = nullptr;
        
        DestroyTree(left);
        DestroyTree(right);
    }
}

// 先序打印树
void PrintPreOrder(BinaryTreeNode* root)
{
    if(root == nullptr)
        return;
    
    cout << root->val << " ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);
    
}





int main(){

    
    BinaryTreeNode* p1 = CreateTreeNode(1);
    BinaryTreeNode* p2 = CreateTreeNode(2);
    BinaryTreeNode* p3 = CreateTreeNode(3);
    BinaryTreeNode* p4 = CreateTreeNode(4);
    BinaryTreeNode* p5 = CreateTreeNode(5);
    BinaryTreeNode* p6 = CreateTreeNode(6);
    BinaryTreeNode* p7 = CreateTreeNode(7);
    
    ConnectTreeNodes(p1, p2, p3);
    ConnectTreeNodes(p2, p4, p5);
    ConnectTreeNodes(p3, p6, nullptr);
    ConnectTreeNodes(p4, p7, nullptr);
    
    cout << "先序打印二叉树为：";
    PrintPreOrder(p1);
    cout << endl;
    
    cout << "分层遍历二叉树为：" << endl;
    LevelOrder_Lines_Reverse(p1);
    cout << endl;
    
    return 0;
}


