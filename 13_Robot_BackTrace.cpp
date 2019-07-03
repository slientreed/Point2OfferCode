//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/7/3.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：12.机器人的运动范围，能到达多少个格子。
 2. 思路：类似11题的回溯法，详看下面代码
 3. 扩展：
 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int getSum(int num);      // 获取数字的每位和
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);  // 判断格子要求
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);   // 回溯递归

int movingCount(int threshold,int rows,int cols)
{
    if(threshold < 0 || rows <= 0 || cols <= 0)
    {
        return 0;
    }
    
    bool* visited = new bool[rows*cols];    // 标记当前格子未被访问过
    for(int i = 0; i < rows * cols; ++i)
    {
        visited[i] = false;
    }
    
    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    
    delete[] visited;
    return count;
    
}

// 回溯递归函数
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
    int count = 0;
    if(check(threshold,rows,cols,row,col,visited))   // 判断当前方格能不能进入
    {
        visited[row * cols + col] = true;
        
        count = 1 + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                  + movingCountCore(threshold, rows, cols, row, col + 1, visited)
                  + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                  + movingCountCore(threshold, rows, cols, row, col - 1, visited);
    }
    
    return count;
}

// 判断row的每位和与col的每位和是否大于k
bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
    if(row >= 0 && col >= 0 && col < cols && row < rows && getSum(row) + getSum(col) <= threshold && !visited[row * cols +col])
        return true;
    
    return false;
}

// 求各位的数值和
int getSum(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}


int main(){

    int count = 0;
    int k, row, col;
    cout << "请输入阈值k:";
    cin >> k;
    cout << "请输入方格行数：";
    cin >> row;
    cout << "请输入方格列数：";
    cin >> col;
    count = movingCount(k, row, col);
    cout << "可以到达" << count << "个格子" << endl;
    
    return 0;
}
