
//
//  Created by mark on 2019/7/18.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：38. 全排列问题
 2. 思路：递归，固定一个，然后交换
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



using namespace std;


/*
 // 原书方法：指针用的很好，要多理解啊
 
void PermutationRecursive(char* pStr, char* pBegin);

// 全排列字符串
void Permutation(char* pStr)
{
    if(pStr == nullptr)
        return;
    
    PermutationRecursive(pStr, pStr);
    
}

// 递归交换字符
void PermutationRecursive(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
        printf("%s\n", pStr);
    else
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char temp = *pCh;                  // 这里pBegin,pCh用于向后递归，交换最后两个字符
            *pCh = *pBegin;
            *pBegin = temp;
            
            PermutationRecursive(pStr, pBegin+1); // 向后递归，直到最后两个字符，交换
            
            temp = *pCh;                      // 用于递归返回后，把交换的字符放回在交换回来
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}
*/

// 参考网上代码

bool isDuplicate(string& str, int begin, int end);
void PermutationRecursion(string str, int begin, vector<string> res);

vector<string> Permutation(string str, vector<string> res)
{
    res.clear();
    
    if(str.empty() == true)
        return res;
    
    PermutationRecursion(str,0,res);
    sort(res.begin(), res.end());
    return res;
}

void PermutationRecursion(string str, int begin, vector<string> res)
{
    if(str[begin] == '\0')
    {
        res.push_back(str);
        cout << str << endl;
    }
    else
    {
        for(int i = begin; str[i] != '\0'; ++i)
        {
            if(!isDuplicate(str,begin,i))
            {
                swap(str[i], str[begin]);  // 递归到最后，返回递归的时候，开始交换最后两个字符
                //cout <<"swap " <<str[i] <<"(" <<i <<")" <<" and " <<str[begin] <<"(" <<begin <<")" <<endl;
                PermutationRecursion(str, begin + 1, res);
                swap(str[i], str[begin]);   // 输出str后，再交换回来
            }
        }
    }
}

// 判断一个字符串，是否有跟最后一个字符重复的元素
bool isDuplicate(string& str, int begin, int end)
{
    for(int i = begin; i < end; ++i)
    {
        if(str[i] == str[end])
            return true;
    }
    return false;
}

int main(){

    
    vector<string> res;
    char str[] = "abc";
    Permutation(str, res);
    
    // 迭代器遍历vector
    for(vector<string>::iterator iter = res.begin(); iter != res.end(); ++iter)
        cout << *iter << endl;
    
    return 0;
}


