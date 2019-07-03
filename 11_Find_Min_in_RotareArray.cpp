//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/7/2.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：找旋转数组（把一个有序数组最开始的若干元素搬到数组末尾）的最小数字；
 2. 思路：旋转数组分成两块，每块是分别有序的，所以二分查找；
         1. 指向数组第一个元素的首指针，和最后一个元素的尾指针；
         2. 找到中间元素，和首指针与尾指针的值相比；
         3. 如果中间值大于首指针值，mid属于前一部分数组，最小值位于mid后面，首指针移动到 mid；
         4. 如果中间值小于尾指针值，mid属于后一部分数组，最小值位于mid前面，尾指针移动到 mid;
         5. 重复2，3，4 步骤，最终首指针指向前一块的最后一个元素，尾指针指向后一块数组的第一个元素，两者相邻；尾指针指向的即是最小元素。
 
 3. 扩展：注意当重复元素过多，head,tail，mid三个指针值相等时，要使用顺序遍历head,tail之间的元素了。
 
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
// 1. 顺序查找。从首元素逐个查找，逐渐增大，最大值后一个即是最小值
int FindMin(vector<int>& nums)
{
    if(nums.size() == 0)
        return 0;
    
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > nums[i+1])
            return nums[i+1];
    }
    
    return nums[0];
}
*/

int FindinOrder(vector<int>& nums,int head, int tail);

// 2. 折半查找思路
int FindMin(vector<int>& nums)
{
    int length = nums.size();
    if(length <= 0)
        return 0;
    
    int head = 0, tail = length - 1;
    int mid = head;
    
    if(nums[head] < nums[tail])
        cout << "数组未翻转";
    while( nums[head] >= nums[tail] )
    {
        // 尾指针和首指针差1，说明找到最小元素：尾指针所指即是
        if(tail - head == 1)
        {
            mid = tail;
            break;
        }
        
        mid = (head + tail) / 2;
        
        // 这里有个逻辑问题：[1,0,1,1,1]这样数列当出现head,mid,tail三个值相等时，无法判断最小值在前一部分还是后一部分，只能采用顺序查找（head,tail）之间的数；
        if(nums[head] == nums[mid] && nums[mid] == nums[tail])
            return FindinOrder(nums,head,tail);      // 调用顺序查找函数
        
        if(nums[mid] >= nums[head])  // mid大于首指针，说明最小值在后一部分
            head = mid;
        else if(nums[mid] <= nums[tail])  // mid小于尾指针，说明最小值在mid前面
            tail = mid;
    }
    
    return nums[mid];
}

//顺序查找函数
int FindinOrder(vector<int>& nums,int head, int tail)
{
    int res = nums[head];
    for(int i = head; i < tail; ++i)
    {
        if(nums[i] < res)
            res = nums[i];
    }
    
    return res;
}

int main(){

    
    vector<int> nums{1,0,1,1,1};
    cout << "最小值是：" << FindMin(nums) << endl;
    
    return 0;
}
