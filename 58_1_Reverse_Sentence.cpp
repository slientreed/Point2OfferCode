
//
//  Created by mark on 2019/7/27.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：58_1. 翻转字符串：翻转句子的顺序，但是单词内字符顺序不变。
 2. 思路：这是翻转字符串问题，经典解法是两次翻转。第一次：翻转句子所有字符串；第二次：翻转每个单词内的字符串。
 
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


char* ReverseSentence(char* pStr)
{
    if(pStr == nullptr)
        return nullptr;
    
    char* pBegin = pStr;
    char* pEnd = pStr;
    while(*pEnd != '\0')     // 找到字符串尾
        pEnd++;
    pEnd--;
    
    // 第一次翻转：翻转整个句子
    ReverseChar(pBegin, pEnd);
    
    // 第二次：翻转句中每个单词
    pBegin = pEnd = pStr;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ')        // 说明首指针还没调整到第一个字符
        {
            pBegin++;
            pEnd++;             // 说明这时候pEnd也指向空格
        }
        else if(*pEnd == ' ' || *pEnd == '\0')    // 判断尾指针是否在最后一个字符的空格上
        {
            ReverseChar(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
            pEnd++;             // 移动尾指针
    }
    
    return pStr;
}



int main()
{
    
    cout << "输入字符串：";
    char str[] = "I am a student.";
    cout << str << endl;
    
    cout << "翻转字符串：";
    ReverseSentence(str);
    cout << str << endl;

    return 0;
}


