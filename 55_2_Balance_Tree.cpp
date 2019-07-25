
//
//  Created by mark on 2019/7/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：55_2. 判断一个树是不是平衡二叉树
 2. 思路：1. 由上个题，递归左右子树深度，判断每个节点是否平衡。 （会出现大量重复遍历，效率低）
         2. 后序递归遍历树，每次遍历时保存它的深度，就可以一边遍历一遍判断了。不用出现大量重复。
 
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


int TreeDepth(TreeNode* root);
// 方法1.不断调用计算树深函数，判断每个节点是不是平衡树
bool isBalance(TreeNode* root)
{
    if(root == nullptr)
        return true;
    
    int left = TreeDepth(root->left);
    int right = TreeDepth(root->right);
    if(abs(left - right) > 1)
        return false;
    
    return isBalance(root->left) && isBalance(root->right);
}

// 方法2，后序遍历，每次遍历一个节点记录它的深度
bool isBalance2(TreeNode* root, int* depth)
{
    if(root == nullptr)
    {
        *depth = 0;
        return true;
    }
    
    int left_depth, right_depth;
    // 后序遍历
    bool left = isBalance2(root->left, &left_depth);       // 先遍历左子树
    bool right = isBalance2(root->right, &right_depth);    // 再遍历右子树
    
    if(left && right)                        // 遍历根节点，且记录当前层数
    {
        if(abs(left_depth - right_depth) <= 1)
        {
            *depth = 1 + max(left_depth, right_depth);    // 记录每个每个节点的深度
            return true;
        }
    }
    return false;
}



// 计算每个子树的深度
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
    //       5 7
    //     12
    TreeNode* pNode8 = CreateTreeNode(8);
    TreeNode* pNode6 = CreateTreeNode(6);
    TreeNode* pNode10 = CreateTreeNode(10);
    TreeNode* pNode5 = CreateTreeNode(5);
    TreeNode* pNode7 = CreateTreeNode(7);
    //TreeNode* pNode9 = CreateTreeNode(9);
    //TreeNode* pNode11 = CreateTreeNode(11);
    TreeNode* pNode12 = CreateTreeNode(12);
    
    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, nullptr, nullptr);
    ConnectTreeNodes(pNode5, pNode12, nullptr);
    
    int depth = 0;
    if(isBalance2(pNode8, &depth))
        cout << "是平衡树" << endl;
    else
        cout << "不是平衡树" << endl;
    
    return 0;
}


