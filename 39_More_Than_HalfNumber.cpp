
//
//  Created by mark on 2019/7/19.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：39. 数组中出现次数超过一半的数字。
 2. 思路：1. 基于Partation快排查找法，找中位数，一定是超过一半的数字
         2. 数组特点：超过一般的数字肯定比其他所有的数字出现次数和还多。每次和前面一个数字相等加1，不相等减1.
         3.使用map来建立数字到出现次数的映射
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

using namespace std;



// 划分函数，返回枢轴在排序数组中该在的位置。index为第几大元素
int Partition(int data[], int length, int left, int right)
{
    if(data == nullptr || length <= 0 || left < 0 || right >= length)
        return NULL;
    
    int i = left, j = right;
    int pivot = data[left];          // 选取第一个元素为枢轴，也可以随机选取
    
    while(i < j)
    {
        while(i < j && pivot <= data[j])
            j--;
        swap(data[j], data[i]);     // 找到比当前枢轴小的，交换放到枢轴左侧
    
        while(i < j && pivot >= data[i])
            i++;
        swap(data[i], data[j]);
    }
    
    data[i] = pivot;   // 把枢轴放到应该在的位置
    return i;          // 返回pivot所在的位置
}


// 判断当前的数字是否超过一半
template<typename T>
bool CheckMoreHalf(T nums, int length, int number)
{
    int times = 0;
    for(int i = 0; i < length; ++i)
    {
        if(nums[i] == number)
            times++;
    }
    
    bool isMoreThanHalf = true;
    if(times * 2 <= length)
        isMoreThanHalf = false;
    
    return isMoreThanHalf;
}



// 方法1 --------------------------------------------------------------------------------
// 找超过一半的数字
int MoreThanHalfNum1(int* nums, int length)
{
    
    if(nums == nullptr || length <= 0)   // 检查输入的数组是否无效
        return 0;
    
    int mid = length >> 1;
    int left = 0, right = length - 1;
    int index = Partition(nums, length, left, right);
    
    while(index != mid)
    {
        if(index > mid)
        {
            right = index - 1;
            index = Partition(nums, length, left, right);
        }
        else
        {
            left = index + 1;
            index = Partition(nums, length, left, right);
        }
    }
    
    int res = nums[mid];
    if(!CheckMoreHalf(nums,length,res))
        res = 0;
    
    return res;
}

// 方法2 --------------------------------------------------------------------------------
/*
 1. 保存两个数字，一个是当前判断重复的数字，一个是重复的次数；
 2. 向后遍历，如果后一个和当前相等，次数加1，否则减1；如果次数减为0，选取下一个数字为判断数字；
 3. 因为是超过半数的数字，所以最后次数大于1的判断数字为所求。
 */
int MoreThanHalfNum2(vector<int> nums)
{
    if(nums.size() == 0)
        return 0;
    
    int num = nums[0], count = 1;
    
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == num)
            count++;
        else
            count--;
        
        if(count == 0)           // 更换判断数字
        {
            num = nums[i];
            count = 1;
        }
        
    }
    
    if(!CheckMoreHalf(nums, nums.size(), num))
        num = 0;
    
    return num;
}


// 3.使用map来建立数字到出现次数的映射
int MoreThanHalfNum3(vector<int> nums)
{
    map<int, int> hmap;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(hmap.find(nums[i]) != hmap.end())       // 在map中查找是否有和当前相等的元素，有数目加1，没有置为1.
            hmap[nums[i]] += 1;
        else
            hmap[nums[i]] = 1;
    }
    
    // 迭代查找个数最多的元素
    for(map<int,int>::iterator iter = hmap.begin(); iter != hmap.end(); iter++)     // 迭代map，查找个数最多的元素
    {
        if(iter->second * 2 > nums.size())              // 迭代器，iter->second标志值，iter->first表示键
            return iter->first;
    }
    return 0;
}



int main()
{
    
    int nums[] = {1,2,3,2,2,2,5,4,2};
    int res1 = MoreThanHalfNum1(nums, 9);
    
    vector<int> numbers{3,2,3,2,2,3,5,3,3};
    int res2 = MoreThanHalfNum2(numbers);
    cout << "超过一半数字是：" << res1 << endl;
    cout << "超过一半数字是：" << res2 << endl;
    
    int res3 = MoreThanHalfNum3(numbers);
    cout << "方法3：" << res3 << endl;
    
    return 0;
}


