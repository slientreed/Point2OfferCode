
//
//  Created by mark on 2019/7/22.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：48.找字符串中最长的不包含重复字符的子字符串
 2. 思路：动态规划。从左到右扫描字符，计算第i个字符为结尾不包含重复字符的最长长度，如果前面没出现过，则f(i)=f(i-1)+1;如果出现过：
         分成两种情况：1. d <= f(i-1),说明上次出现的字符在上个最长字符序列中，更新d为两个重复字符之间的距离
                     2. d > f(i-1),说明重复的字符没在上个最长子序列中，继续向后遍历，d加1即可；
 
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


// 动态规划，分成两种情况：
// 1. 重复距离d比上个重复的子序列小
// 2. 重复距离d比上个重复的子序列大，继续累加

int longSubstingWithoutDuplicaton(const string &str)
{
    int curLength = 0;
    int maxLength = 0;
    
    int* position = new int[26];       // 记录每个字符是否出现，未出现为-1，出现过则置为在字符串中出现的位置
    for(int i = 0; i < 26; ++i)
        position[i] = -1;
    
    for(int i = 0; i < str.length(); ++i)
    {
        int prev = position[str[i] - 'a'];        // 记录上个重复字符出现的字符
        if(prev < 0 || i - prev > curLength)       // 未重复字符，或者重复距离比前面子序列大（情况2）
            ++curLength;
        else
        {
            if(curLength > maxLength)
                maxLength = curLength;
            
            curLength = i - prev;          // 情况1，更新最大距离d
        }
        
        position[str[i] - 'a'] = i;     // 记录上个重复字符的位置
    }
    
    delete[] position;
    return maxLength;
}



int main()
{
    string str = "arabcacfr";
    int maxLen = longSubstingWithoutDuplicaton(str);
    cout << maxLen << endl;
    
    return 0;
}


