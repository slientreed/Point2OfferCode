
//
//  Created by mark on 2019/7/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：53_3. 数组中数值和下标相等的元素。有序数组，找出任意一个数值等于下标的元素
 2. 思路：二分法；如果数值等于下标，找到；小于，则在左半边；大于，在右半边
 
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

int GetNumberSameAsIndex(int* nums, int length)
{
    if(nums == nullptr || length < 0)
        return -1;
    
    int left = 0;
    int right = length - 1;
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] == mid)
            return mid;
        else if(nums[mid] > mid)       // 数值比索引大，在左半边
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    return -1;
}

int main()
{
    
    int nums[] = {-3,-1,1,3,5};
    int miss = GetNumberSameAsIndex(nums, 5);
    cout << miss << endl;
    
    return 0;
}


