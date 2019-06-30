//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/6/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 题目：根据前序，后序遍历的结果生成原二叉树
 2. 思路：先根据前序找到root，前序的第1个节点；
         然后在中序中找到root的位置,root之前的为左子树，root之后的为右子树；
         记录左右子树的长度，并用向量记录左右子树，对左右子树递归则即可生成
 3. 这个代码还有点问题，我是参考的，估计自己写不出来，多看
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <iomanip>
#include <list>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode(int x):val(x),left(NULL),right(NULL){}
};


void preorder(BinaryTreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root->val << "->";
    preorder(root->left);
    preorder(root->right);
}


void inorder(BinaryTreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << "->";
    inorder(root->right);
}

void postorder(BinaryTreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << "->";
}


BinaryTreeNode* Construct(vector<int>preorder,vector<int>inorder)
{
    if(preorder.size() != inorder.size())
    {
        cout << "preorder和inorder的长度不一致" << endl;
        return NULL;
    }
    
    int size = preorder.size();
    if(size == 0){
        cout << "这是个空树" << endl;
        return NULL;
    }
    int length = size;
    cout << "树有" << length << "个节点" << endl;
    
    // 先序遍历的第一个点为root节点，记录
    int value = preorder[0];
    BinaryTreeNode* root = new BinaryTreeNode(value);
    cout << "the root is :" << root->val << endl;
    
    // 知道了root的值，在inorder中查找根的位置
    int root_index = 0;
    for(root_index = 0; root_index < length; ++root_index)
    {
        if(inorder[root_index] == root->val)
        {
            cout << "inorder中root的位置是:" << root_index << endl;
            break;
        }
    }
    if(root_index > length)
    {
        cout << "can‘t find root in inorder" << endl;
        return NULL;
    }
    
    
    // 区分出左子树和右子树
    
    // 先确定左子树和右子树的长度，从inorder
    int left_length = root_index;
    int right_length = length - 1 - root_index;
    cout << "左子树长度是：" << left_length << "," << "右子树的长度是：" << right_length << endl;
    
    // 创建左右子树向量
    vector<int> pre_left(left_length), in_left(left_length);
    vector<int> pre_right(right_length), in_right(right_length);
    for(int i = 0; i < length; ++i){
        if(i < root_index)
        {
            // 小于root_index的是左子树
            pre_left[i] = preorder[i+1];    // 因为前序遍历第一个是root，所以要 preorder[i+1]
            in_left[i] = inorder[i];
            cout << pre_left[i] << in_left[i] << ' ';
        }
        else if(i > root_index)
        {
            // 前序遍历的第一个是root节点，root后面root_index - 1 个左子树，再后面是右子树
            // 中序遍历 root_index - 1 是左子树，root_index是root,再后面是右子树
            pre_right[i - root_index - 1] = preorder[i];
            in_right[i - root_index - 1] = inorder[i];
            cout << pre_right[i - root_index - 1] << in_right[i - root_index - 1] << ' ';
        }
    }
    
    
    cout << endl << "root左子树是：";
    for(int i = 0; i < left_length; ++i)
    {
        cout << pre_left[i] << in_left[i] << ' ';
    }
    cout << endl;
    cout << "root右子树是：";
    for(int i = 0; i < right_length; ++i)
    {
        cout << pre_right[i] << in_right[i] << ' ';
    }
    cout << endl;
    
    root->left = Construct(pre_left, in_left);
    root->right = Construct(pre_right, in_right);
    
    return root;
}


int main(){
    
    vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8 };
    vector<int> in{4, 7, 2, 1, 5, 3, 8, 6};
    
    BinaryTreeNode* root = Construct(pre, in);
    
    cout << "preordr is:";
    preorder(root);
    cout << endl;
    
    cout << "inorder is:";
    inorder(root);
    cout << endl;
    
    cout << "postorder is:";
    postorder(root);
    cout << endl;
    
    return 0;
}



