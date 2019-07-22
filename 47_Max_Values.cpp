
//
//  Created by mark on 2019/7/22.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：47.礼物最大值。在一个二维矩阵，只能上下左右走，找累积和最大的路径
 2. 思路：动态规划，不断找当前位置最大值，并存储。f(i,j) = max(f(i-1,j), f(i,j-1)) + nums[i,j]. f(i,j)代表走到（i,j）所能拿到的最大值。
 
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


// 动态规划，利用递归公式，创建一个辅助二维数组，数组中（i，j）表示元素到达坐标(i,j)的格子能拿到的礼物价值总和的最大值。

int getMaxValue(int* values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    
    int** maxValues = new int*[rows];
    for(int i = 0; i < rows; i++)
        maxValues[i] = new int[cols];
    
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;
            
            if(i > 0) up = maxValues[i - 1][j];      // 当前上面一个
            if(j > 0) left = maxValues[i][j - 1];    // 当前左边一个
            
            maxValues[i][j] = max(left, up) + values[i * cols + j];          // 当前位置最大值

            //cout << "(" << i << "," << j << ")" << "->";
        }
    }
    int max_value = maxValues[rows - 1][cols - 1];
    
    
    // 输出每个位置当前最大值
    cout << "每个位子最大值是：" << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << maxValues[i][j] << " ";
        }
        cout << endl;
    }
    
    // 输出路径
    cout << "走的路径是：";
    int i = 0, j = 0;
    while(i < rows-1 && j < cols-1)
    {
        cout << maxValues[i][j] << " ";
        if(maxValues[i+1][j] > maxValues[i][j+1])
            i++;
        else
            j++;
    }
    while(i < rows)
        cout << maxValues[i++][j] << " ";
    i--;
    while(j < cols)
        cout << maxValues[i][j++] << " ";
    cout << endl;
    
    for(int i = 0; i < rows; i++)
        delete[] maxValues[i];
    delete[] maxValues;
    
    return max_value;
    
}



int main()
{
    
    
    int values[] = {1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5};
     
    int max_value = getMaxValue(values, 4, 4);
    cout << "最大值是：" << max_value << endl;
    
    return 0;
}


