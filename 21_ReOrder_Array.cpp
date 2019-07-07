
//
//  Created by mark on 2019/7/7.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：21.调整数组顺序使奇数位于偶数前面，奇数全都到前半部分，偶数全都到后半部分
 2. 思路：1. 双指针
         2. 借用新数组存储
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

// 方法1：使用双指针，但是不稳定，交换后奇偶的顺序变了。
/*
 1.head指向数组第一个数字，只向后移动，tail指向最后一个数字，只向前移动；
 2.head向后移动，直到碰到偶数；tail向前移动，直到碰到奇数；
 3.交换head，tail指向的数字，则交换了奇偶，奇数到前面，偶数到后面
 4.重复步骤2，3，直到尾指针到头指针前面，tail > head时停止。
 */
void ReorderArray(vector<int> &arr)   // 注意这里传递的是地址，直接修改了向量的值
{
    if(arr.size() <= 1)
        return ;
    
    // 容器的迭代器支持大小比较和算术运算
    vector<int>::iterator head = arr.begin();
    vector<int>::iterator tail = arr.end() - 1;
    
    while(head < tail)
    {
        while(head < tail && (*head & 0x1) != 0)   // 向后移动head，直到偶数停止
            head++;
        
        while(head < tail && (*tail & 0x1) != 1)   // 向前移动tail,直到奇数停止
            tail--;
        
        if(head < tail)
        {
            swap(*head,*tail);    // 交换指针指向的值
        }
    }
    
}


// 方法2.使用一个赋值数组空间，空间复杂度增加为O(n)，但是重新排序之后数组是稳定的，原来数字的顺序不变。
void ReorderArray_arr(vector<int> &arr)
{
    if(arr.size() <= 1)
        return;
    
    vector<int> temp;   // 创建一个新向量，用于存放偶数
    vector<int>::iterator begin;
    begin = arr.begin();
    
    for(;begin != arr.end();) // 遍历向量元素
    {
        if((*begin & 0x1) == 0)   // 如果是偶数，存到temp向量中
        {
            temp.push_back(*begin);
            arr.erase(begin);
        }
        else
            begin++;
    }
    
    vector<int>::iterator start = temp.begin();   // 合并奇偶向量，得到稳定的重排数组
    for(;start != temp.end(); start++)
        arr.push_back(*start);
}



int main(){

    vector<int> arr{1,2,3,4,5,6};
    
    /*
     int n,num;
    cout << "要输入几个数字：";
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        while(cin >> num)
            arr.push_back(num);
    }
    cout << endl;
    */
    
    cout << "原数组是：";
    for(int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    
    cout << "奇偶排后：";
    ReorderArray_arr(arr);
    for(int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}


