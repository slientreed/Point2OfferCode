
//
//  Created by mark on 2019/7/6.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 问题：17.打印从1到n的最大n位数。输入数字n，按顺序打印从1到最大的n为十进制数。
 2. 思路：用字符串或者数组表达最大数。
      1. 初始开辟一个n+1大小的字符串；
      2. 用字符串模拟数字的自增，进位，输出。
      3. 当字符串长度超过n+1时，产生溢出。
 */


#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;


void PrintNumber(char* num);
bool Increment(char* num);


// 对当前字符表示的数值加1; 如果加法溢出，返回true
bool Increment(char* num)
{
    bool isOverflow = false;   // 溢出标志位
    int TakeOver = 0;          // 记录进位值
    int length = strlen(num);
    
    for(int i = length - 1; i >= 0; --i)
    {
        int sum = num[i] - '0' + TakeOver;
        if(i == length - 1)   // 每次在增加1
            ++sum;
        
        if(sum >= 10)    // 当某一位累加到10，要产生进位时
        {
            if(i == 0)   // 当前如果在首位，产生溢出
                isOverflow = true;
            else
            {
                sum -= 10;      //
                TakeOver = 1;   // 记录进位
                num[i] = '0' + sum;  // 变回字符
            }
        }
        else
        {
            num[i] = '0' + sum;    // 不会产生进位，直接加1赋值原来位即可
            break;                 // 直接退出循环，打印
        }
    }
    
    return isOverflow;
}



// 打印字符串表示的数字：主要是避免不要打印前面的'0',从第一个非0字符才开始打印，直至字符串的结尾
void PrintNumber(char* num)
{
    bool isBegin0 = true;            // 标志位，当前位为0
    int length = strlen(num);
    
    for(int i = 0; i < length; ++i)
    {
        if(isBegin0 && num[i] != '0')
            isBegin0 = false;
        
        if(!isBegin0)
            printf("%c", num[i]);
    }
    
    printf("\t");              // \t制表符，每次调用该函数输出一次会和上次输出的对齐
}

/*
 // 方法1 ： 非递归
 // 顺序输出n位的所有数字
 void Print_Max_Digits(int n)
 {
 if(n <= 0) return;
 
 char* num = new char[n + 1];
 memset(num, '0', n);
 num[n] = '\0';   // 字符串最后一位是结束符
 
 while(!Increment(num))
 {
 PrintNumber(num);
 }
 
 delete[] num;
 
 }
 */


// ------------------------------------------------------------------------------------------------------------------------------

void PrintDigits_Recu(char* num, int length, int index);

//方法2: 递归, n个0~9数字的全排列: 数字的每一位都可能是0~9的一个数，然后设置下一位；递归终止条件是到数字最后一位
void Print_Max_Digits(int n)
{
    if(n <= 0) return;
    
    char* num = new char[n + 1];
    num[n] = '\0';
    
    for(int i = 0; i < 10; ++i)   // 对每位的0~9递归
    {
        num[0] = i + '0';
        PrintDigits_Recu(num, n, 0);
    }
    
    delete[] num;
}

// 递归输出每一位
void PrintDigits_Recu(char* num, int length, int index)
{
    if(index == length - 1)   // 递归结束，设置到数字的最后一位
    {
        PrintNumber(num);
        return;
    }
    
    for(int i = 0; i < 10; ++i)
    {
        num[index+1] = i + '0';     // 对当前位进行0~9遍历
        PrintDigits_Recu(num, length, index + 1);
    }
}



int main(){

    int n;
    cout << "请输入数字位数：";
    cin >> n;
    Print_Max_Digits(n);
    cout << endl;
    
    return 0;
}


