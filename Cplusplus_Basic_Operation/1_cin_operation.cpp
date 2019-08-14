//
//  main.cpp
//  pointer2offer
//
//  Created by mark on 2019/6/25.
//  Copyright © 2019年 mark. All rights reserved.
//

/*
 说明：
 1. 判断回文数问题
 2. C++程序设计13.7章的例题
 3. 主要用来理解c++程序的 输入 , cin操作
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*1. string的方法
bool is_palindrome(const string& s);
 
int main() {
    
    for(string s; cin>>s;){   // 这里cin会一直等待输入，程序不停止
    
        if(!is_palindrome(s))
            cout << s << "不是回文数\n";
        else
            cout << s << "是回文数\n";
    }
    
    return 0;
}


bool is_palindrome(const string& s)   // 1. string实现
{

    int first = 0;
    int last = s.length()-1;
    while(first < last){
        if(s[first] != s[last])
            return false;
        ++first;
        --last;
    }
    
    return true;
}
*/




/*
bool is_palindrome(const char s[], int n);
istream& read_word(istream& is, char* buffer, int max);

int main() {
    
    constexpr int max = 128;
    for(char s[max]; read_word(cin, s, max);){   // 这里cin是作为istream的输入吗？？？我不太明白这点
        
        if(!is_palindrome(s,strlen(s)))
            cout << s << "不是回文数\n";
        else
            cout << s << "是回文数\n";
    }
    
    return 0;
}



bool is_palindrome(const char s[], int n){     // 数组方法实现
    int first = 0;
    int last = n - 1;
    while(first < last){
        if(s[first] != s[last])
            return false;
        ++first;
        --last;
    }
    return true;
}

istream& read_word(istream& is, char* buffer, int max){   // 安全地把字符读入数组的方法，从is最多读取max-1个字符存入buffer
    is.width(max);                          // 设置istream的宽度，避免下一个 >> 读入导致缓冲区溢出
    is >> buffer;                           // 读取空白间隔的单词
    return is;
}
*/




bool is_palindrome(const char* first, const char* last);
istream& read_word(istream& is, char* buffer, int max);

int main(){

    constexpr int max = 128;
    for(char s[max]; read_word(cin, s, max);){   // 这里cin是作为istream的输入吗？？？我不太明白这点
        
        if(!is_palindrome(s,&s[strlen(s)-1]))
            cout << s << "不是回文数\n";
        else
            cout << s << "是回文数\n";
    }
    
    return 0;
}


bool is_palindrome(const char* first, const char* last){     // 指针方法实现
    
    while(first < last){
        if(*first != *last)
            return false;
        ++first;
        --last;
    }
    return true;
}


istream& read_word(istream& is, char* buffer, int max){   // 安全地把字符读入数组的方法，从is最多读取max-1个字符存入buffer
    is.width(max);                          // 设置istream的宽度，避免下一个 >> 读入导致缓冲区溢出
    is >> buffer;                           // 读取空白间隔的单词
    return is;
}






