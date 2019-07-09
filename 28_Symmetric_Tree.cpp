
//
//  Created by mark on 2019/7/8.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：27.判断一个数是不是对称
 2. 思路：递归和非递归
         1. 树是空，true
         2. 判断左右子树是否对称：
                            1. 根节点相等；
                            2. 且左子树的左子树和右子树的右子树对称；
                            3. 左子树的右子树和右子树的左子树对称；
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
bool isSymmetric(BinaryTreeNode* left, BinaryTreeNode* right);

bool isSymmetric_Recu(BinaryTreeNode* root)
{
    if(root == nullptr)
        return true;
    
    return isSymmetric(root->left, root->right);
}

bool isSymmetric(BinaryTreeNode* left, BinaryTreeNode* right)
{
    if(left == nullptr && right == nullptr)    // 1.左右都为空
        return true;
    
    if(left->val != right->val)      // 2.左右子节点相等
        return false;
    
    // 3.左子树的左子树要和右子树的右子树对称，同时左子树的右子树要和右子树的左子树
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}


// 2. 迭代
bool isSymmetric_iter(BinaryTreeNode* root)
{
    if(root == nullptr)
        return true;
    
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* left = root->left;
    BinaryTreeNode* right = root->right;
    s.push(left);
    s.push(right);
    
    while(!s.empty())
    {
        BinaryTreeNode* temp1 = s.top();s.pop();
        BinaryTreeNode* temp2 = s.top();s.pop();
        if(temp1 == nullptr && temp2 == nullptr) continue;   // 同时为空才行
        if(temp1 == nullptr || temp2 == nullptr) return false;
        if(temp1->val != temp2->val) return false;   // 值要相等
        
        s.push(temp1->left); s.push(temp2->right);    // 注意这个入栈顺序：左子树的左节点-右子树的右节点， 左子树的右节点-右子树的左节点
        s.push(temp1->right); s.push(temp2->left);
        
    }
    return true;
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
                2          2
             4     5    5     4
     
     */
    
    BinaryTreeNode* A1 = CreateTreeNode(1);
    BinaryTreeNode* A2 = CreateTreeNode(2);
    BinaryTreeNode* A3 = CreateTreeNode(2);
    BinaryTreeNode* A4 = CreateTreeNode(4);
    BinaryTreeNode* A5 = CreateTreeNode(5);
    BinaryTreeNode* A6 = CreateTreeNode(5);
    BinaryTreeNode* A7 = CreateTreeNode(4);
    ConnectTreeNodes(A1, A2, A3);
    ConnectTreeNodes(A2, A4, A5);
    ConnectTreeNodes(A3, A6, A7);

    cout << "原树是：";
    PrintPreOrder(A1);
    cout << endl;
    
    if(isSymmetric_iter(A1))
        cout << "对称树" << endl;
    else
        cout << "非对称树" << endl;
    
    
    return 0;
}


