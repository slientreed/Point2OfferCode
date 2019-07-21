
//
//  Created by mark on 2019/7/21.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：46. 把数字转化为字符串。一串数字有多少种向字符串翻译的方法。
 2. 思路：递归，f(i) = f(i+1) + g * f(i+2)
 
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


// 递归的循环版本

int GetTransCount(const string& number);

int GetTranslation(int number)
{
    
    if(number < 0)
        return 0;
    
    string numberInString = to_string(number);
    return GetTransCount(numberInString);
    
}

int GetTransCount(const string& number)
{
    int length = number.length();
    int* counts = new int[length];
    int count = 0;
    
    for(int i = length - 1; i >= 0; --i)
    {
        count = 0;
        if(i < length - 1)
            count = counts[i + 1];
        else
            count = 1;
        
        if(i < length - 1)    // 从倒数第二位开始
        {
            int digit1 = number[i] - '0';
            int digit2 = number[i+1] - '0';
            int converted = digit1 * 10 + digit2;
            if(converted >= 10 && converted <= 25)       // 判断当前两位数在不在（10，25）之间
            {
                if(i < length - 2)
                    count += counts[i+2];
                else
                    count += 1;
            }
        }
        
        counts[i] = count;
    }
    
    count = counts[0];
    delete[] counts;
    
    return count;
}





// 递归的递归版本

int GetTranslation_Recur(string number);

int GetTranslation_Recur(int number)
{
    if(number<0)
        return 0;
    if(number==1)
        return 1;
    return GetTranslation_Recur(to_string(number));
}

//动态规划，从右到左计算。
//f(r-2) = f(r-1)+g(r-2,r-1)*f(r);
//如果r-2，r-1能够翻译成字符，则g(r-2,r-1)=1，否则为0
int GetTranslation_Recur(string number) {
    int f1 = 0,f2 = 1,g = 0;
    int temp;
    for(int i=number.length()-2;i >= 0;i--){
        int digit1 = number[i] - '0';
        int digit2 = number[i+1] - '0';
        int converted = digit1 * 10 + digit2;
        if(converted >= 10 && converted <= 25)
            g = 1;
        else
            g = 0;
        
        temp = f2;
        f2 = f2+g*f1;
        f1 = temp;
    }
    return f2;
}


int main()
{
    cout << "输入一个数字：";
    int number;
    cin >> number;
    int count = GetTranslation_Recur(number);
    cout << "总数是：" << count << endl;
    
    
    return 0;
}


