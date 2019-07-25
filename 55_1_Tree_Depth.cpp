
//
//  Created by mark on 2019/7/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：55_1. 二叉树深度.
 2. 思路：递归左右子树
 
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

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};


int TreeDepth(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    
    int left = TreeDepth(root->left);     // 递归左子树
    int right = TreeDepth(root->right);   // 递归右子树
    
    return (left > right) ? (left + 1) : (right + 1);       // 返回左右子树中较大值加1
}


//辅助函数 ------------------------------------------------------------------------------------------------------------------------

// 构建树节点
TreeNode* CreateTreeNode(int val)
{
    TreeNode* pNode = new TreeNode();
    pNode->val = val;
    pNode->left = nullptr;
    pNode->right = nullptr;
    
    return pNode;
}

// 连接树节点
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}


int main()
{
    
    //            8
    //        6      10
    //       5 7    9  11
    //     12
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode10 = CreateTreeNode(10);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode7 = CreateTreeNode(7);
    TreeNode* pNode9 = CreateTreeNode(9);
    TreeNode* pNode11 = CreateTreeNode(11);
    TreeNode* pNode12 = CreateTreeNode(12);
    
    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    ConnectTreeNodes(pNode5, pNode12, nullptr);
    
    cout << TreeDepth(pNode8) << endl;
    
    return 0;
}


