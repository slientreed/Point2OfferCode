//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/6/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 题目：给定一个二叉树和一个节点，找中序遍历的下一个节点？（树种节点除了左右节点指针，还有一个指向父节点的指针）
 2. 思路：中序遍历下，一个节点（非空）的下个节点有下面几种情况：
         1.该节点有右子树：则是右子树的最左边子节点；
         2.如果没有右子树，且它是父节点的左节点：则是其父节点；
         3.该节点既没有右子树，又是父节点的右节点：沿着父节点指针向上遍历，直到找到一个是其父节点的左子节点的节点，该节点的父节点即为所求；
         如果上诉3种情况都不满足，则说明该节点是中序最后一个节点，返回NULL。
 */

#include <iostream>
#include <vector>


using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
    BinaryTreeNode(int x):val(x),left(NULL),right(NULL),parent(NULL){}
};


BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;
    
    BinaryTreeNode* pNext = nullptr;
    if(pNode->right != NULL)         // 如果有右子树
    {
        pNext = pNode->right;
        while(pNext->left != NULL)   // 找右子树的最左边节点
        {
            pNext  = pNode->left;
        }
        return pNext;
    }
    
    if(pNode->parent != NULL)       // 如果父节点存在
    {
        if(pNode == pNode->parent->left)   // 且如果是父节点的左子节点，下个节点为父节点
            return pNode->parent;
        else
        {
            BinaryTreeNode* parent_node = pNode->parent;
            BinaryTreeNode* current_node = pNode;
            while(parent_node != NULL && current_node == parent_node->right)  // 沿着父节点向上，找一个节点是其父节点的左子节点（第一个找到的即是）
            {
                current_node = parent_node;
                parent_node = current_node->parent;
            }
        
            return parent_node;              // 该节点的父节点即是下一个
        }
    }
    
    return pNext;
}


// ==================== 辅助代码用来构建二叉树 ====================

BinaryTreeNode* CreatBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode(value);
    pNode->val = value;
    pNode->left = nullptr;
    pNode->right = nullptr;
    pNode->parent = nullptr;
    
    return pNode;
}


void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
        
        if(pLeft != nullptr)
            pLeft->parent = pParent;
        if(pRight != nullptr)
            pRight->parent = pParent;
    }
}

// 中序遍历打印
void printTree(BinaryTreeNode* root)
{
    if(root == NULL)
        return;
    
    printTree(root->left);
    cout << root->val << ' ';
    printTree(root->right);
    
}




//       1
//    2     3
//  4   5
//        6
// 中序输出：425613
//三种情况，分别找：2，4，6

int main(){
    
    // 生成一个二叉树，并连接起来
    BinaryTreeNode* pNode1 = CreatBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreatBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreatBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreatBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreatBinaryTreeNode(5);
    //BinaryTreeNode* pNode1 = CreatBinaryTreeNode(1);
    BinaryTreeNode* pNode6 = CreatBinaryTreeNode(6);
    
    ConnectTreeNodes(pNode1, pNode2, pNode3);
    ConnectTreeNodes(pNode2, pNode4, pNode5);
    ConnectTreeNodes(pNode5, nullptr, pNode6);
    
    printTree(pNode1);
    cout << endl;
    
    BinaryTreeNode* pNext2 = GetNext(pNode2);
    if(pNext2 != nullptr)
        cout << "2的下个节点是：" << pNext2->val << endl;
    BinaryTreeNode* pNext4 = GetNext(pNode4);
    if(pNext4 != nullptr)
        cout << "4的下个节点是：" << pNext4->val << endl;
    BinaryTreeNode* pNext6 = GetNext(pNode6);
    if(pNext6 != nullptr)
        cout << "6的下个节点是：" << pNext6->val << endl;

    
    return 0;
}
