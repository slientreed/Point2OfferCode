//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/6/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 问题：判断一个数组里面有没有重复的数字
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isDuplicate(int nums[], int len, int* duplication);

int main() {
    
    int a[] = {2,3,1,0,6,5,4};
    int* res = new int(-1);
    if(!isDuplicate(a, sizeof(a) / sizeof(int), res))
        cout << "没有重复元素" << endl;
    else
        cout << *res << endl;
    
    return 0;
}



/*
// 思路1：把每个数字放回原位子（数字和坐标相等），如果原位已经有存在，则重复
// time: O(n), space: O(1)
 
bool isDuplicate(int nums[], int len, int* duplication){
    
    if(nums == nullptr || len < 1) return false; // 空数组情况
    
    for(int i = 0; i < len; ++i)
    {
        if (nums[i] < 0 || nums[i] > len - 1)  // 数组是否合法，大于0，小于n
            return false;
    }
    
    for (int i = 0; i < len; ++i){
        while(nums[i] != i){
            if (nums[i] == nums[nums[i]]){   // 如果第i个位置上的元素和当前元素相等
                *duplication = nums[i];
                return true;
            }
            int tem = nums[i];
            nums[i] = nums[nums[i]];   //把以当前元素为坐标的元素值放到当前位置
            nums[tem] = tem;           //把当前元素放到以其值为坐标的位置
        }
    }
    return false;
}
 
*/


/*
 // 思路2：哈希表，每次从数组取元素，把哈希表元素值对应位置置为1；如果在此hashmap值为1，则说明该元素重复
 // time: O(n), space: O(n)

bool isDuplicate(int nums[], int len, int* duplication){

    if(nums == nullptr || len < 1) return false; // 空数组情况
    
    for(int i = 0; i < len; ++i)
    {
        if (nums[i] < 0 || nums[i] > len - 1)  // 数组是否合法，大于0，小于n
            return false;
    }
    
    int* hash = new int[len]{0};
    for (int i = 0; i < len; ++i){
        
        if (hash[nums[i]]){
            *duplication = nums[i];
            return true;
        }
        else
            hash[nums[i]] = 1;
    }
    return false;
}
 */

// 思路3： 先对数组排序，然后判断有没有重复元素
// time: O(nlog(n))  space: O(1)

bool isDuplicate(int nums[], int len, int* duplication){
    
    if(nums == nullptr || len < 1) return false; // 空数组情况
    
    for(int i = 0; i < len; ++i)
    {
        if (nums[i] < 0 || nums[i] > len - 1)  // 数组是否合法，大于0，小于n
            return false;
    }
    
    sort(nums,nums+len);  // sort()两个参数：排序数组起始地址，结束地址，排序方法（可选）
    
    for (int i = 0; i < len-1; ++i){
        if (nums[i] == nums[i+1]){
            *duplication = nums[i];
            return true;
        }
    }
    return false;
}

