
//
//  Created by mark on 2019/7/10.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：29.顺时针打印矩阵
 2. 思路：根据矩阵的行和列数，依次旋转打印矩阵；每旋转依次，左上角后退一个单位，右下角前进一个单位；
         注意单行和单列情况
 */


/*
 问题：
 1. c++二维向量输入问题，如何传入指针迷迷糊糊的；
 2. 二维向量的操作不太清晰明白
 
 */



#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

void PrintMatrixInCycle(int** nums, int columns, int rows, int start);

// 判断循环打印条件
void PrintMatrix(int** nums, int columns, int rows)
{
    if(nums == nullptr || columns <= 0 || rows <= 0)
        return;
    
    int start = 0;
    
    while(columns > start * 2 && rows > start * 2)
    {
        PrintMatrixInCycle(nums,columns,rows,start);
        ++start;
    }
}


// 循环打印
void PrintMatrixInCycle(int** nums, int columns, int rows, int start)
{
    int end_x = columns - 1 - start;   // 表示剩下列数
    int end_y = rows - 1 - start;      // 表示剩下行数
    
    for(int i = start; i <= end_x; ++i)   // 从左到右打印一行
    {
        int num = nums[start][i];
        cout << num << " ";
    }
    
    
    if(start < end_y)                     // 从上到下打印一列
    {
        for(int i = start + 1; i <= end_y; ++i)
        {
            int num = nums[i][end_x];
            cout << num << " ";
        }
    }
    
    
    if(start < end_x && start < end_y)   // 从右向左打印一行
    {
        for(int i = end_x - 1; i >= start; --i)
        {
            int num = nums[end_y][i];
            cout << num << " ";
            
        }
    }
    
    
    if(start < end_x && start < end_y)    // 从下到上打印一列
    {
        for(int i = end_y - 1; i >= start + 1; --i)
        {
            int num = nums[i][start];
            cout << num << " ";
        }
    }
    
}

// 辅助函数-----------------------------------------------------------------------------

// 生成矩阵
int** CreatMatrix(int rows,int cols)
{
    if(rows < 1 || cols < 1)
        cout << "没有数字！";
    int sum = 1;
    
    int** nums = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        nums[i] = new int[cols];
        for(int j = 0; j < cols; ++j)
        {
            nums[i][j] = sum;
            sum++;
        }
    }
    
    return nums;
}

// 打印输入的矩阵
void Print_Original_Matrix(int** matrix, int rows, int cols)
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            //cout << matrix[i][j] << " ";
            printf("%d\t", matrix[i][j]);   // \t有制表符，使得输出间隔整齐
        }
        cout << endl;
    }
}



int main(){

    int cols,rows;
    cout << "请输入行数和列数:";
    cin >> rows >> cols;
    
    int** nums = CreatMatrix(rows,cols);
    
    cout << "原矩阵是:" << endl;
    Print_Original_Matrix(nums, rows, cols);
    cout << endl;
    
    cout << "逆序打印是:";
    PrintMatrix(nums, cols, rows);
    cout << endl;
    
    return 0;
}


