
//
//  Created by mark on 2019/7/8.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：26.树的子结构，判断树B，是不是树A的子结构
 2. 思路：递归
        1. 遍历树A，查找与B的根节点一样的节点
        2. 判断数A中以R节点为根节点的子树，是不是和B有相同的结构。
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

bool isSubTree(BinaryTreeNode* rootA, BinaryTreeNode* rootB);

// 步骤1. 在A中查找和B根节点一样的节点
bool HasSubTree(BinaryTreeNode* rootA, BinaryTreeNode* rootB)
{
    bool res = false;
    
    if(rootA != nullptr && rootB != nullptr)
    {
        if(rootA->val == rootB->val)
            res = isSubTree(rootA,rootB);
        
        if(!res)
            res = HasSubTree(rootA->left, rootB) || HasSubTree(rootA->right, rootB);    // 递归
    }
    
    return res;
}


// 步骤2. 判断A中以R为根节点的子树是不是和B同构
bool isSubTree(BinaryTreeNode* rootA, BinaryTreeNode* rootB)
{
    if(rootB == nullptr)
        return true;
    if(rootA == nullptr)
        return false;
    
    if(rootA->val != rootB->val)
        return false;
    
    return isSubTree(rootA->left, rootB->left) && isSubTree(rootA->right, rootB->right);   // 递归左右子树
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



int main(){

    // 创建两个树
    /*
                      1                      2
                2          3              4     5
             4     5
     
     */
    
    BinaryTreeNode* A1 = CreateTreeNode(1);
    BinaryTreeNode* A2 = CreateTreeNode(2);
    BinaryTreeNode* A3 = CreateTreeNode(3);
    BinaryTreeNode* A4 = CreateTreeNode(4);
    BinaryTreeNode* A5 = CreateTreeNode(5);
    ConnectTreeNodes(A1, A2, A3);
    ConnectTreeNodes(A2, A4, A5);

    BinaryTreeNode* B1 = CreateTreeNode(2);
    BinaryTreeNode* B2 = CreateTreeNode(6);
    BinaryTreeNode* B3 = CreateTreeNode(5);
    ConnectTreeNodes(B1, B2, B3);
    
    if(HasSubTree(A1, B1))
        cout << "B是A的子树" << endl;
    else
        cout << "B不是A的子树" << endl;
    
    return 0;
}


