
//
//  Created by mark on 2019/7/24.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：51. 数组中的逆序对
 2. 思路：用排序的思想，逆序就是把大小交换过来；每交换一次，就是一个逆序对正序的过程。
         1. 把数组分成两个数组，分别统计出数组内部的逆序对数目；
         2. 然后在统计出两个相邻数组之间的逆序对数目；
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



// 这个是参考github中的代码，感觉更加清晰
// https://github.com/gatieme/CodingInterviews/tree/master/036-%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E9%80%86%E5%BA%8F%E5%AF%B9

int MergeElem(vector<int> &elem, int start, int mid, int end, vector<int> &temp);
int InversePairsCore(vector<int> &elem, int start, int end, vector<int> &temp);

int InversePairs(vector<int> elem)
{

    if(elem.size() == 0)
        return 0;
    
    vector<int> temp(elem.size());
    int count = InversePairsCore(elem, 0, elem.size() - 1, temp);
    
    return count;
}

//
int InversePairsCore(vector<int> &elem, int start, int end, vector<int> &temp)
{
    int sum = 0;
    if(start < end)
    {
        int mid = (start + end) / 2;
        sum += InversePairsCore(elem, start, mid, temp);   // 找左半段的逆序对数目
        sum += InversePairsCore(elem, mid + 1, end, temp); // 找右半段的逆序对数目
        sum += MergeElem(elem, start, mid, end, temp);      // 分别找完左右两个半段数组后，各自有序。然后找两段之间的逆序对。
    }
    
    return sum;
}

// 数组的归并操作，计算两个数组之间的逆序对
int MergeElem(vector<int> &elem, int start, int mid, int end, vector<int> &temp)
{
    // [start, mid]:数组左半段；  [mid+1, end]:数组右半段
    
    int i = mid;
    int j = end;
    int k = 0;
    int count = 0;
    
    // i,j分别指向两段数组的尾部，比较，把较小的放到临时数组中去
    while(i >= start && j > mid)
    {
        if(elem[i] > elem[j])          // 前面一个数组大于后面对应位置，后面位置之前全为逆序对
        {
            temp[k++] = elem[i--];    // 从临时数组最后一个位置排序
            count += j - mid;
        }
        else
            temp[k++] = elem[j--];
    }
    
    while(i >= start)            // 前一半数组还未比较完
        temp[k++] = elem[i--];
    
    while(j > mid)
        temp[k++] = elem[j--];
    
    for(i = 0; i < k; ++i)     // 把排序后的元素放入原数组中
        elem[end-i] = temp[i];
    
    return count;
}




// 这个是参考书中的代码
int InversePairsCore_book(int* data, int* temp, int start, int end);

int InversePairs_book(int* data, int length)
{
    if(data == nullptr || length < 0)
        return 0;
    
    int* temp = new int[length];
    for(int i = 0; i < length; i++)
        temp[i] = data[i];
    
    int count = InversePairsCore_book(data, temp, 0, length - 1);
    delete[] temp;
    
    return count;
}


int InversePairsCore_book(int* data, int* temp, int start, int end)
{
    if(start == end)
    {
        temp[start] = data[start];
        return 0;
    }
    
    int length = (end - start) / 2;
    
    int left = InversePairsCore_book(temp, data, start, start + length);          // 归并左半段
    int right = InversePairsCore_book(temp, data, start + length + 1, end);       // 归并右半段
    
    int i = start + length;     // 前段数组最后一个
    int j = end;               //  后段数组最后一个
    int k = end;
    int count = 0;
    while(i >= start && j >= start + length + 1)
    {
        if(data[i] > data[j])     // 前半段大，产生逆序对
        {
            temp[k--] = data[i--];
            count += j - start - length;
        }
        else
            temp[k--] = data[j--];
    }
    
    for(;i >= start;i--)
        temp[k--] = data[i];
    for(;j >= start + length + 1; j--)
        temp[k--] = data[j];
    
    return left + right + count;
}



int main()
{
    
    vector<int> elem{7,5,6,4};
    int sum1 = InversePairs(elem);
    cout << "逆序对个数是：" << sum1 << endl;
    
    int elem2[] = {7,5,6,4};
    int sum = InversePairs_book(elem2,4);
    cout << "逆序对的个数是：" << sum << endl;
    
    return 0;
}


