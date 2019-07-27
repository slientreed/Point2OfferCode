
//
//  Created by mark on 2019/7/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：56_2. 数组中有的出现三次，其中只有一个出现一次，找出这一个。
 2. 思路：不能直接异或了。如果一个数字出现三次，则二进制的每一位也出现三次。
         所以，把数组中所有数字二进制表示的每一位都加起来，某一位的和能被3整除，则出现一次的该位为0，不能整除该位为1；
 
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


// 设置一个32位数组，存放所有元素每位为1的累加和

int FindNumberAppearOnce(vector<int> data)
{
    if(data.size() == 0)
        return NULL;
    
    vector<int> bitSum{0};  // 记录所有元素某一位为1的个数和
    
    for(int i = 0; i < data.size(); ++i)
    {
        int mask = 1;
        for(int j = 31; j >= 0; j--)     // 遍历当前数字的所有32位
        {
            int bit = data[i] & mask;   // 看当前数字某一位是否为1
            if(bit != 0)
                bitSum[j]++;
            mask = mask << 1;         // 判断下一位
        }
    }
    
        int res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res = res << 1;
            res += bitSum[i] % 3;      // 得到res第i位是否为1
        }
        
    return res;
}


int main()
{
    
    vector<int> data{2,1,2,1,1,2,5};
    int res = FindNumberAppearOnce(data);
    cout << "一个的数字是:" << res << endl;
    
    return 0;
}


