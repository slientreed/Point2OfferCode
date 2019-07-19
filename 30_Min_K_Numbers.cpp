
//
//  Created by mark on 2019/7/19.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：40.找数组中最小的k个数。
 2. 思路：1. 利用partition函数，选取第k个为枢轴，一轮过后，枢轴前面的都是最小的k个数。space:O(n)
         2. 创建一个k大小的容器，遍历数组，每次拿k中最大元素和数组中元素比较，更新其中的数字。如果容器使用数组/向量：O(nk)；如果容器使用最大堆/红黑树：O(nlogk)
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




// 划分函数，返回枢轴在排序数组中该在的位置。index为第几大元素
int Partition(vector<int> &nums, int left, int right)        // 引用传值，否则函数返回无法修改
{
    if(nums.size() == 0)
        return NULL;
    
    int i = left, j = right;
    int pivot = nums[left];          // 选取第一个元素为枢轴，也可以随机选取
    
    while(i < j)
    {
        while(i < j && pivot <= nums[j])
            j--;
        swap(nums[j], nums[i]);     // 找到比当前枢轴小的，交换放到枢轴左侧
    
        while(i < j && pivot >= nums[i])
            i++;
        swap(nums[i], nums[j]);
    }
    
    nums[i] = pivot;   // 把枢轴放到应该在的位置
    return i;          // 返回pivot所在的位置
}


// 方法1----------------------------------------------------------------------------------------------------------------
// 使用partiton函数：时间复杂度低，不消耗空间；但是会打乱原来数组的顺序

vector<int> GetkLeastNumbers1(vector<int> &nums, int k)         // 注意传值要传引用
{
    vector<int> res;
    res.clear();
    
    if(nums.size() == 0 || nums.size() < k)
        return res;
    
    int left = 0, right = nums.size() - 1;
    int index = Partition(nums, left, right);
    while(index != k - 1)                       // 使用partiton函数，找到第k大元素，则其前面的即是
    {
        if(index > k - 1)
        {
            right = index - 1;
            index = Partition(nums, left, right);
        }
        else
        {
            left = index + 1;
            index = Partition(nums, left, right);
        }
    }
    
    for(int j = 0; j < k; ++j)
        res.push_back(nums[j]);
    
    return res;
}


// 方法2 ----------------------------------------------------------------------------------------------------------------
// 开辟使用一个容器，存放当前最小的k元素，然后不断向后遍历。使用数组容器

typedef multiset<int, std::greater<int> >            intSet;             // 引用了库函数中的容器
typedef multiset<int, std::greater<int> >::iterator  setIterator;       // 设置了greater遍历器，每次返回当前set最大值

void GetkLeastNumbers2(const vector<int> &nums, intSet &res, int k)
{
    res.clear();
    
    if(k < 1 || nums.size() < k)
        return;
    
    for(vector<int>::const_iterator iter = nums.begin(); iter != nums.end(); iter++)
    {
        if(res.size() < k)
            res.insert(*iter);
        else
        {
            setIterator iterGreatest = res.begin();   // 获取当前容器最大值
            if(*iter < *(res.begin()))
            {
                res.erase(iterGreatest);       // 删除容器内最大值
                res.insert(*iter);             // 加入当前遍历的较小值
            }
        }
    }
}





int main()
{
    
    vector<int> input1{4,5,1,6,2,7,3,8};
    vector<int> res = GetkLeastNumbers1(input1, 4);
    for(vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
        cout << *iter << " " ;
    cout << endl;
    
    
    vector<int> input2{4,5,1,6,2,7,3,8};
    intSet res2;                                                         // 注意是set类型
    GetkLeastNumbers2(input2, res2, 4);
    for(setIterator iter = res2.begin(); iter != res2.end(); iter++)        // set迭代
        cout << *iter << " " ;
    cout << endl;
    
    
    return 0;
}


