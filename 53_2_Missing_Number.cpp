
//
//  Created by mark on 2019/7/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：53_2. 0~n-1中缺失的数字。
 2. 思路：1. 用公式求出n个数的累加和s1，然后累加数组中所有的数字和s2，s1-s2即为所求。
         2. 转化求在排序数组中，第一个值和下标不相等的元素。二分法：元素值和下标相等：查右半边；不相等且前一个相等，即为所求；不相等且前一个也不等，在左半边。
 
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

int GetMissingNumber(int* nums, int length)
{
    if(nums == nullptr || length <= 0)
        return -1;
    
    int left = 0;
    int right = length - 1;
    
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] != mid)
        {
            if(mid == 0 || nums[mid - 1] == mid - 1)        // mid不相等，且前一个也不相等，mid为所求
                return mid;
            else
                right = mid - 1;
        }
        else
            left = mid + 1;
    }
    
    if(left == right)          //说明right没动，最后一个缺失了
        return length;
    
    return -1;
}


int main()
{
    
    int nums[] = {0,1,2,3,4,6,7};
    int miss = GetMissingNumber(nums, 7);
    cout << miss << endl;
    
    return 0;
}


