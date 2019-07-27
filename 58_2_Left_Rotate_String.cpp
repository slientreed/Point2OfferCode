
//
//  Created by mark on 2019/7/27.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：58_2. 左旋字符串。把字符串前面若干个字符串转移到字符串尾部。
 2. 思路：这是字符串翻转的加强版。把字符串分成前面一部分，后面一部分，这就是上个的翻版。分两步：先翻转局部，在整体翻转
 
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

// 辅助函数，翻转字符串中的一段
void ReverseChar(char* pBegin, char* pEnd)
{
    if(pBegin == nullptr || pEnd == nullptr)
        return;
    
    while(pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        
        pBegin++;
        pEnd--;
    }
}


char* LeftRotateString(char* pStr, int n)
{
    if(pStr == nullptr)
        return nullptr;
    
    int length = strlen(pStr);
    if(length > 0 && n > 0 && n < length)
    {
        char* pFirst_start = pStr;            // 记录各段的开头和结尾
        char* pFirst_end = pStr + n - 1;
        char* pSecond_start = pStr + n;
        char* pSecond_end = pStr + length - 1;
        
        // 分别翻转两段
        ReverseChar(pFirst_start, pFirst_end);
        ReverseChar(pSecond_start, pSecond_end);
        
        // 整体翻转
        ReverseChar(pFirst_start, pSecond_end);
    }
    
    return pStr;
}



int main()
{
    
    cout << "输入字符串：";
    char str[] = "abcdeft";
    cout << str << endl;
    
    cout << "翻转字符串：";
    LeftRotateString(str,2);
    cout << str << endl;

    return 0;
}


