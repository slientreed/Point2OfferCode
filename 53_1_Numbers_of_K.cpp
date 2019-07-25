
//
//  Created by mark on 2019/7/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：53_1. 数字在排序数组中出现的次数
 2. 思路：1. 先用二分找出要找的数字，然后来回搜索，找到重复的次数；由于重复的个数可能为n，所以复杂度： O（n）
         2. 不断用二分法；先找到k出现的第一个和最后一个位置。然后两者位置差就是重复次数。  time:O(logn)
            1. 找第一个位置：找到和k相等的数，判断它前一个，如果不相等，则找到第一个；如果相等，则在前半段，在前半段中迭代寻找；
            2. 找最后一个位置：同样类似与1
 
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


int GetFirstIndex(vector<int> arr, int k, int start, int end);
int GetLastIndex(vector<int> arr, int k, int start, int end);

// 由第一个和最后一个元素索引计算重复个数
int GetNumberofK(vector<int> arr, int k)
{
    if(arr.size() == 0)
        return 0;
    
    int sum = 0;
    int first = GetFirstIndex(arr, k, 0, arr.size() - 1);
    int last = GetLastIndex(arr,k, 0, arr.size() - 1);
    
    if(first > -1 && last > -1)
        sum = last - first + 1;
    
    return sum;
}

// 改进二分法计算第一个索引，主要是当相等的时候，判断前一个如果不相等k，即是第一个，否则在前一段内；
int GetFirstIndex(vector<int> arr, int k, int start, int end)
{
    if(start > end)
        return -1;
    
    int mid = start + (end - start) / 2;
    int mid_data = arr[mid];
    
    if(mid_data == k)
    {
        if((mid >= 0 && arr[mid - 1] != k) || mid == 0)
            return mid;
        else
            end = mid - 1;
    }
    else if(mid_data > k)
        end = mid - 1;
    else
        start = mid + 1;
    
    return GetFirstIndex(arr, k, start, end);
}

// 类似于取第一个值的索引
int GetLastIndex(vector<int> arr, int k, int start, int end)
{
    
    if(start > end)
        return -1;
    
    int mid = start + (end - start) / 2;
    int mid_data = arr[mid];
    
    if(mid_data == k)
    {
        if((mid < arr.size() - 1 && arr[mid + 1] != k) || mid == arr.size() - 1)
            return mid;
        else
            start = mid + 1;
    }
    else if(mid_data < k)
        start = mid + 1;
    else
        end = mid - 1;
    
    return GetLastIndex(arr, k, start, end);
}


int main()
{
    
    vector<int> arr{1,2,3,3,3,3,4,5};
    int sum = GetNumberofK(arr, 3);
    cout << "3出现次数：" << sum << endl;
    
    return 0;
}


