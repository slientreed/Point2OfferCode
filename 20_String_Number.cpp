
//
//  Created by mark on 2019/7/7.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：20.表示数值的字符串
 2. 思路：把字符串分成三步份：整数，小数，指数；分别对每部分进行判断即可
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

// 用来扫描字符串中的0~9的数位，无+-符号 (注意这里修改了str指针的值)
bool scanUnsignInterger(char** str)
{
    char* before = *str;   // 用于和原来的长度判断
    
    while(**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);          // 注意这里的指针，把str字符串向后移了
    return *str > before;   // 如果是数字，str指针会后移动，则str的地址会变大；否则和原来相等
}


bool isNumeric(char* str)
{
    if(str == nullptr)
        return false;
    
    if(*str == '+' || *str == '-')   // 整数部分
        ++str;
    bool numeric = scanUnsignInterger(&str);
    
    if(*str == '.')    // 判断小数部分
    {
        ++str;
        numeric = scanUnsignInterger(&str) || numeric;    // 使用||，小数可以没有整数部分，小数点后面也可以没有数字
    }
    
    if(*str == 'e' || *str == 'E')  // 指数部分
    {
        ++str;
        if(*str == '+' || *str == '-')
            ++str;
        numeric = scanUnsignInterger(&str) && numeric;   // 使用&&,指数前面要有数字，e/E后面也要有数字
    }
    
    return numeric && *str == '\0';   // str要到达结尾
    
}


int main(){

    /*
    char* str;
    cout << "输入要判断的字符：";
    cin >> str;
     */
    char str[100];  // 定义一个字符串
    cout << "输入要输入的字符串：";
    cin.getline(str,100);   // 感觉cin.getline()函数限定了大小，不太合适，暂时没想到好办法，除非要挨个输入用数组存起来
    if(isNumeric(str))
        cout << "是数字";
    else
        cout << "不是数字";
    cout << endl;
    
    
    return 0;
}


