
//
//  Created by mark on 2019/7/22.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：50. 第一个只出现一次的字符。
 2. 思路：借助哈希表，键值时字符，值时字符出现的次数。扫描两次数组，第一次是统计字符次数，第二次是判断对应字符出现的值。
         这里实现一个简单的哈希表，定义256大小的数组，根据ASCII码值作为数组的下标对应数组的一个数字；数组中存储每个字符出现的次数。
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


char FirstNotRepeating(char* pString)
{

    if(pString == nullptr)
        return '\0';
    
    const int tableSize = 256;
    unsigned int hashTable[tableSize];         // 创建一个数组
    for(int i = 0; i < tableSize; ++i)
        hashTable[i] = 0;
    
    char* pHashKey = pString;
    while(*(pHashKey) != '\0')
        hashTable[*(pHashKey++)]++;        // 把字符对应的次数加1,统计每个字符出现次数
    
    pHashKey = pString;
    while(*pHashKey != '\0')         // 查找第一个次数为1的字符
    {
        if(hashTable[*pHashKey] == 1)
            return *pHashKey;
        
        pHashKey++;
    }
    
    return '\0';
}




int main()
{
    char* str = "abaccdeff";
    char res = FirstNotRepeating(str);
    cout << res << endl;
    
    return 0;
}


