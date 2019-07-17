
//
//  Created by mark on 2019/7/17.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：36.二叉搜索树和双向链表。把二叉搜索树转化成双向链表
 2. 思路：分成左子树，root，右子树。然后递归
 
 */



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <assert.h>

using namespace std;



struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void ConvertNodeRecursive(TreeNode* root, TreeNode** pLastNode);


TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(pRootOfTree == nullptr)
        return NULL;
    
    TreeNode* pLastNode = nullptr;                 // 指向已经排序树已经转换好的节点,指向双向链表的尾节点
    ConvertNodeRecursive(pRootOfTree, &pLastNode);     // 递归转换节点
    
    TreeNode* pHeadList = pLastNode;                    // 返回双向链表的头结点,从尾节点，一直遍历到头结点返回
    while(pHeadList != nullptr && pHeadList->left != nullptr)
        pHeadList = pHeadList->left;
    
    return pHeadList;
    
}

void ConvertNodeRecursive(TreeNode* root, TreeNode** pLastNode)
{
    if(root == nullptr)
        return;
    
    TreeNode* pCur = root;
    
    if(pCur->left != nullptr)                           // 中序遍历，先递归左子树
        ConvertNodeRecursive(pCur->left, pLastNode);
    
    pCur->left = *pLastNode;                        // 当前根节点的左指针，指向已经完成转换的最后一个节点;
    if(*pLastNode != nullptr)
        (*pLastNode)->right = pCur;
    
    *pLastNode = pCur;                         // 更新已经完成排序的最后一个节点
    
    if(pCur->right != nullptr)                //  递归转换右子树
        ConvertNodeRecursive(pCur->right, pLastNode);
}



int main(){

    //    4
    //  3
    //2
    
    TreeNode tree[3];  // 建3个节点
    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = NULL;
    tree[1].val = 3;
    tree[1].left = &tree[2];
    tree[1].right = NULL;
    tree[2].val = 2;
    tree[2].left = NULL;
    tree[2].right = NULL;

    TreeNode* p = Convert(tree);

    while(p != nullptr)
    {
        cout << "当前节点：" << p->val << " ";
        if(p->left != nullptr)
            cout << "左节点：" << p->left->val << " ";
        if(p->right != nullptr)
            cout << "右节点：" << p->right->val << " ";
        cout << endl;
        p = p->right;
    }
    
    cout << endl;
    
    return 0;
}


