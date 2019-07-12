
//
//  Created by mark on 2019/7/12.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：33.给定数组，判断是否为二叉搜索树的后序遍历序列
 2. 思路：二叉搜索树：左子树小于根节点；右子树大于根节点。
                   1. 二叉树的后序遍历中，最后一个节点是根节点的值；根据此可以把数组分成两部分：
                   2. 第一部分是左子树节点的值，都比根节点小；第二部分是右子树节点的值，都比根节点大；
                   3. 递归判断左右子树，得出结果。
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


/*
// 1. 作者书中代码
// 二叉搜索树的后序遍历序列
bool isSquenceOfBST(int* nums, int length)
{

    if(nums == nullptr || length <= 0)
        return false;
    
    int root = nums[length - 1];       // root为根节点
    
    int i = 0;
    for(; i < length - 1; ++i)
    {
        if(nums[i] > root)            // 找到左右子树的分界点
            break;
    }
    
    int j = i;
    for(; j < length - 1; ++j)
    {
        if(nums[j] < root)           // 右子树全都大于根节点，如果小，不是二叉搜索树的遍历序列
            return false;
    }
    
    bool left = true;             // 递归左子树
    if(i > 0)
        left = isSquenceOfBST(nums,i);
    
    bool right = true;            // 递归右子树
    if(i < length - 1)
        right = isSquenceOfBST(nums + i, length - 1 - i);
    
    return left && right;
}

*/



// 2. 参考网上，使用向量
bool _isSquenceOfBST(vector<int> &nums, int left, int right);

bool isSquenceOfBST(vector<int> nums)
{
    if(nums.size() == 0)
        return false;
    
    return _isSquenceOfBST(nums, 0, nums.size() - 1);
}

bool _isSquenceOfBST(vector<int> &nums, int left, int right)    // 用于递归判断左右子树的子程序
{
    if(left >= right)
        return true;
    
    
    int mid = right - 1;       // 使得mid后面的元素都比根节点大,mid之后元素为root右子树
    while(nums[mid] > nums[right])
        --mid;
    
    int i = left;
    while(i < mid && nums[i] < nums[right])   // nums[i]都比root节点小，是root的左子树
        ++i;
    
    if(i < mid)              // 如果i和mid不相等
        return false;
    
    // [left, mid]为左子树；[mid+1, right-1]为右子树，递归遍历
    return _isSquenceOfBST(nums, left, mid) && _isSquenceOfBST(nums, mid + 1, right - 1);
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

    
    BinaryTreeNode* p1 = CreateTreeNode(8);
    BinaryTreeNode* p2 = CreateTreeNode(6);
    BinaryTreeNode* p3 = CreateTreeNode(10);
    BinaryTreeNode* p4 = CreateTreeNode(5);
    BinaryTreeNode* p5 = CreateTreeNode(7);
    BinaryTreeNode* p6 = CreateTreeNode(9);
    BinaryTreeNode* p7 = CreateTreeNode(11);
    
    ConnectTreeNodes(p1, p2, p3);
    ConnectTreeNodes(p2, p4, p5);
    ConnectTreeNodes(p3, p6, p7);
    
    cout << "先序打印二叉树为：";
    PrintPreOrder(p1);
    cout << endl;
    
    //int nums[] = {5,7,6,9,11,8,10};
    
    //vector<int> nums{5,7,6,9,11,10,8};
    vector<int> nums{5,7,6,9,11,8,10};
    if(isSquenceOfBST(nums))
        cout << "是后序遍历的序列!" << endl;
    else
        cout << "不是后序遍历序列!" << endl;
    
    return 0;
}


