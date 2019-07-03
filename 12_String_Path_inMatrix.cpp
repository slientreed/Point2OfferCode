//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/7/3.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：矩阵中的路径，判断一个矩阵中是否存在一条包含某字符串中所有字符的路径；
 2. 思路：回溯法
         1. 在格子中任选一个作为路径起点；
         2. 回溯特性：路径可看做栈，如果在第n个字符对应的格子周围找不到第n+1个字符，退回n-1个字符；
         3. 定义一个和字符矩阵一样大的bool值矩阵，标示路径是否已经进入的格子。（不可进入重复格子）
 
 3. 扩展：
 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
        return false;
    
    bool* visited = new bool[rows*cols];  // 定义bool矩阵判断当前字符是否被访问过
    memset(visited, 0, rows*cols);        // 初始化为0
    
    int pathLength = 0;   // 记录查找字符串的位置
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
                return true;
        }
    }
    
    delete[] visited;
    return false;
}

// 回溯搜索
bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')     // 回溯搜索中，递归的终止条件
        return true;
    
    bool hasPath = false;
    // 当前格子的字符和str的匹配
    if(row >= 0 && row < rows && col >= 0 && col < cols && matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col])
    {
        ++pathLength;
        visited[row*cols+col] = true;
        
        // 对当前格子（row,col）的字符进行上下左右递归
        hasPath = hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)
                  || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited);
        
        // 当前格子（row,col）回溯之后没有找到路径
        if(!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
        
    }
    
    return hasPath;
}


int main(){

    char* matrix = "hello word,I am mark!";
    char* str = "ord";
    if(hasPath(matrix, 3, 4, str))
        cout << "找到" << str << "字符串" << endl;
    else
        cout << "没有找到" << str << "字符串！" << endl;
    
    return 0;
}
