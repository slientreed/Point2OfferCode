
//
//  Created by mark on 2019/7/18.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：37.序列化，和反序列化二叉树。（序列化指的是将一棵二叉树保存到文件中，反序列化就是从文件中读取二叉树结点值重构原来的二叉树）。
 2. 思路：选择合适的遍历算法，然后进行字符串和整数的转换，把文件中字符生成树；或者把树存储到文件中。
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



using namespace std;


struct BinaryTreeNode
{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};


// --------------------------------------------------------------------------

// 序列化,先序遍历二叉树，然后写入文件
void Serialize(BinaryTreeNode* root, ostream& stream)
{
    if(root == nullptr)
    {
        stream << "$,";
        return;
    }
    
    stream << root->val << ",";
    Serialize(root->left, stream);
    Serialize(root->right, stream);
}


// 反序列化，从文件中读取，然后生成二叉树

// ReadStream每次从流中读出一个字符，是数字返回true,$返回false
bool ReadStream(istream& stream, int* number)
{
    if(stream.eof())
        return false;
    
    char buffer[32];
    buffer[0] = '\0';
    
    char ch;
    stream >> ch;
    int i = 0;
    while(!stream.eof() && ch != ',')     // 不断读入
    {
        buffer[i++] = ch;
        stream >> ch;
    }
    
    bool isNumeric = false;
    if(i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }
    
    return isNumeric;
}

// 反序列化
void DeSerialize(BinaryTreeNode** pRoot, istream& stream)
{
    int number;
    if(ReadStream(stream, &number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->val = number;
        (*pRoot)->left = nullptr;
        (*pRoot)->right = nullptr;
        
        DeSerialize(&(*pRoot)->left, stream);
        DeSerialize(&(*pRoot)->right, stream);
    }
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

//测试函数 ------------------------------------------------------------------------------------------------------------------------

// 序列化测试函数
char* test_Serialize(BinaryTreeNode* root)
{
    // 序列化
    char* filename = "text.txt";
    ofstream fileOut;
    fileOut.open(filename);
    Serialize(root, fileOut);
    fileOut.close();
    
    return filename;
}


// 打印序列化之后，文件的内容
void print_SerializeFile(char* filename)
{
    ifstream fileIn1;
    char ch;
    fileIn1.open(filename);
    while(!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;
}


// 反序列化，从文件中生成二叉树
BinaryTreeNode* test_DeSerialize(char* filename)    // 传入文件名
{
    ifstream fileIn;
    fileIn.open(filename);
    BinaryTreeNode* pNewRoot = nullptr;
    DeSerialize(&pNewRoot, fileIn);
    fileIn.close();
    
    return pNewRoot;
}



int main(){

    //            8
    //        6      10
    //       5 7    9  11
    BinaryTreeNode* pNode8 = CreateTreeNode(8);
    BinaryTreeNode* pNode6 = CreateTreeNode(6);
    BinaryTreeNode* pNode10 = CreateTreeNode(10);
    BinaryTreeNode* pNode5 = CreateTreeNode(5);
    BinaryTreeNode* pNode7 = CreateTreeNode(7);
    BinaryTreeNode* pNode9 = CreateTreeNode(9);
    BinaryTreeNode* pNode11 = CreateTreeNode(11);
    
    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);
    
    
    // 测试序列化
    char* filename = test_Serialize(pNode8);
    
    
    // 打印序列化之后文件的内容
    cout << "序列化文件为：";
    print_SerializeFile(filename);
    
    // 反序列化二叉树文件
    BinaryTreeNode* pNewRoot = test_DeSerialize(filename);
    cout << "反序列化打印：";
    PrintPreOrder(pNewRoot);
    cout << endl;
    
    return 0;
}


