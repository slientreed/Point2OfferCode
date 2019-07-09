
//
//  Created by mark on 2019/7/9.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：27.二叉树镜像，镜像输出二叉树
 2. 思路：镜像就是交换每个根节点的左右子节点，遍历二叉树，然后不断交换；
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>

using namespace std;


struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
}TN,*pTN;


// 1. 递归
void Mirror_Recu(BinaryTreeNode* root)
{
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr)
        return ;
    
    BinaryTreeNode* temp = root->left;   // 交换左右子节点
    root->left = root->right;
    root->right = temp;
    
    if(root->left != nullptr)            // 交换左右子节点
        Mirror_Recu(root->left);
    if(root->right != nullptr)
        Mirror_Recu(root->right);
}



// 2. 非递归，先序遍历
void Mirror_iter(BinaryTreeNode* root)
{
    if(root == nullptr)
        return;
    
    stack<BinaryTreeNode*> s;
    s.push(root);
    
    while(!s.empty())
    {
        BinaryTreeNode* cur = s.top();
        s.pop();
        
        swap(cur->left, cur->right);   // 交换当前根节点的左右子树节点
        
        if(cur->left != nullptr)
            s.push(cur->left);
        if(cur->right != nullptr)
            s.push(cur->right);
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

    // 创建个树
    /*
                      1
                2          3
             4     5    6     7
     
     */
    
    BinaryTreeNode* A1 = CreateTreeNode(1);
    BinaryTreeNode* A2 = CreateTreeNode(2);
    BinaryTreeNode* A3 = CreateTreeNode(3);
    BinaryTreeNode* A4 = CreateTreeNode(4);
    BinaryTreeNode* A5 = CreateTreeNode(5);
    BinaryTreeNode* A6 = CreateTreeNode(6);
    BinaryTreeNode* A7 = CreateTreeNode(7);
    ConnectTreeNodes(A1, A2, A3);
    ConnectTreeNodes(A2, A4, A5);
    ConnectTreeNodes(A3, A6, A7);

    cout << "原树是：";
    PrintPreOrder(A1);
    cout << endl;
    
    cout << "镜像后：";
    Mirror_iter(A1);
    PrintPreOrder(A1);
    cout << endl;
    
    
    return 0;
}


