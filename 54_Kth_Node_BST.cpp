
//
//  Created by mark on 2019/7/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：54. 二叉搜索树的第k大节点
 2. 思路：二叉搜索树的中序遍历为递增序列，中序遍历，然后找第k个即可。
 
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

class solutioin
{
    int count = 0;       // 记录第几个值

public:
    // 1. 递归写法
    TreeNode* KthNode_Recur(TreeNode* root, int k)
    {

        if(root == nullptr)
            return nullptr;
        TreeNode* res = nullptr;
        
        if((res = KthNode_Recur(root->left, k)) != nullptr)     // 递归遍历左子树，是否为nullptr
            return res;
        
        count++;
        if(count == k) return root;                             // 遍历当前节点
        
        if((res = KthNode_Recur(root->right, k)) != nullptr)     // 递归右子树
           return res;
        
        return nullptr;
    }




    // 2. 非递归写法.借助栈，对任一root，如果左节点不为空，入栈root,且root=root->left;如果左节点为空，弹出节点访问，看是否满足条件；不满足root=root->right;直到栈空。
    TreeNode* KthNode(TreeNode* root, int k)
    {
        if(root == nullptr)
            return nullptr;
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        int count = 0;
        
        while(node != nullptr || !s.empty())   // 开始遍历树
        {
            while(node != nullptr)    // 一直访问左子树
            {
                s.push(node);
                node = node->left;
            }
            
            if(!s.empty())
            {
                node = s.top();
                count++;
                if(count == k) return node;         // 判断是否找到第k个节点
                
                s.pop();
                node = node->right;
            }
            
        }
        
        return nullptr;
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

};


int main()
{
    solutioin solu;
    
    //            8
    //        6      10
    //       5 7    9  11
    TreeNode* pNode8 = solu.CreateTreeNode(8);
    TreeNode* pNode6 = solu.CreateTreeNode(6);
    TreeNode* pNode10 = solu.CreateTreeNode(10);
    TreeNode* pNode5 = solu.CreateTreeNode(5);
    TreeNode* pNode7 = solu.CreateTreeNode(7);
    TreeNode* pNode9 = solu.CreateTreeNode(9);
    TreeNode* pNode11 = solu.CreateTreeNode(11);
    
    solu.ConnectTreeNodes(pNode8, pNode6, pNode10);
    solu.ConnectTreeNodes(pNode6, pNode5, pNode7);
    solu.ConnectTreeNodes(pNode10, pNode9, pNode11);
    
    cout << "输入K值(小于8)：";
    int k;
    cin >> k;
    
    TreeNode* res = solu.KthNode_Recur(pNode8, k);
    cout << "第k个节点值是：" << res->val << endl;
    
    
    return 0;
}


