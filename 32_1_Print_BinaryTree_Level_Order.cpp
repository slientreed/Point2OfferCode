
//
//  Created by mark on 2019/7/12.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：32.从上到下打印二叉树。
 2. 思路：层次遍历，用队列
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



// 层序遍历
void LevelOrder(BinaryTreeNode* root)
{
    if(root == nullptr)
        return;
    
    queue<BinaryTreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode* pNode = q.front();
        q.pop();
        cout << pNode->val << " ";
        
        
        if(pNode->left != nullptr)
            q.push(pNode->left);
        if(pNode->right != nullptr)
            q.push(pNode->right);
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
    
    cout << "层次遍历二叉树为：";
    LevelOrder(p1);
    cout << endl;
    
    return 0;
}


