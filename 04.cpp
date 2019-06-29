//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/6/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 二维数组查找问题：给定一个二维数组，每行从左到右变大，每列从上到下变大；在二维数组中查找给定的数字n是否存在
 2. 思路：从右上角开始查找，如果大于n，则n不在该列，--col；小于n则说明n不在该行,++row;
 3. 类似折半查找的变形，O（n）
 4.注意main()中的输入输出，我是按照一维向量存储的，可视化不方便，有时间改进
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool find(int* matrix, int rows, int columns, int number);
int main(){

    int rows, columns,n;
    cout << "请输入行和列：" << endl;
    cin >> rows >> columns;
    cout << "请输入要查找的值：" << endl;
    cin >> n;
    
    int matrix[rows*columns];
    cout << "输入" << rows*columns << "个矩阵值" << endl;
    for(int i = 0; i < rows*columns; ++i){
        cin >> matrix[i];
    }
    cout <<"查找结果为：" << find(matrix, rows, columns, n) << endl;
    return 0;
}

// 从左下角开始比较
bool find(int* matrix, int rows, int columns, int number){
    
    bool find = false;
    
    if( matrix != nullptr && rows > 0 && columns > 0)
    {
        int row = rows - 1;
        int col = 0;
        while (row < rows && row > 0)
        {
            if(matrix[row * columns + col] == number)
            {
                find = true;
                break;
            }
            else if(matrix[row * columns + col] > number)
                --row;
            else
                ++col;
        }
    }
    return find;
}




/*
 //从右上角开始比较
bool find(int* matrix, int rows, int columns, int number){

    bool find = false;
    
    if( matrix != nullptr && rows > 0 && columns > 0)
    {
        int row = 0;
        int col = columns - 1;
        while (row < rows && col >= 0)
        {
            if(matrix[row * columns + col] == number)
            {
                find = true;
                break;
            }
            else if(matrix[row * columns + col] > number)
                --col;
            else
                ++row;
        }
    }
    return find;
}
*/
