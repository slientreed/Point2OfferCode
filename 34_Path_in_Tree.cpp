
//
//  Created by mark on 2019/7/12.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：34.找二叉树中和为某一值的路径
 2. 思路：前序遍历，递归实现
         1. 每次访问一个节点，把当前权值求和；
         2. 如果当前节点为叶子节点，且路径中节点值的和刚好等于输入值，当前路径符合要求，打印出来；
         3. 如果不是叶子节点，继续访问其左右叶子节点。（当前节点访问后函数会递归到其父节点，所以在函数退出之前要在路径上删除当前节点并减去当前节点的值）
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


void _FindPath(BinaryTreeNode* root, int expectSum, vector<int>& path, int cur_sum);

void FindPath(BinaryTreeNode* root, int expectSum)
{
    if(root == nullptr)
        return;
    
    vector<int> path;
    int cur_sum = 0;
    _FindPath(root, expectSum, path, cur_sum);
}


void _FindPath(BinaryTreeNode* root, int expectSum, vector<int>& path, int cur_sum)
{

    cur_sum += root->val;
    path.push_back(root->val);
    
    // 如果是叶子节点，且路径上累加值和等于输入值，打印路径
    bool isLeaf = root->left == nullptr && root->right == nullptr;
    if(isLeaf && cur_sum == expectSum)
    {
        cout << "路径是：";
        vector<int>::iterator iter = path.begin();    // 迭代器打印
        for(; iter != path.end(); ++iter)
            printf("%d\t",*iter);
        
        cout << endl;
    }
    
    // 如果不是叶子节点，遍历其子节点
    if(root->left != nullptr)
        _FindPath(root->left, expectSum, path, cur_sum);
    if(root->right != nullptr)
        _FindPath(root->right, expectSum, path, cur_sum);
    
    // 递归结束，返回到父节点前，在路径path去掉当前节点值（否则后面打印会出现访问过的节点）
    path.pop_back();
    
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

    BinaryTreeNode* p1 = CreateTreeNode(10);
    BinaryTreeNode* p2 = CreateTreeNode(5);
    BinaryTreeNode* p3 = CreateTreeNode(12);
    BinaryTreeNode* p4 = CreateTreeNode(4);
    BinaryTreeNode* p5 = CreateTreeNode(7);
    
    ConnectTreeNodes(p1, p2, p3);
    ConnectTreeNodes(p2, p4, p5);
    
    FindPath(p1, 22);
    
    return 0;
}


