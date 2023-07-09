#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

class CustomString
{
public:
    // 默认构造函数
    CustomString();

    // 从字符数组构造字符串
    CustomString(const char* s);

    // 拷贝构造函数
    CustomString(const CustomString& other);

    // 析构函数
    ~CustomString();

    // 赋值运算符重载
    CustomString& operator=(const CustomString& other);

    // 获取字符串长度
    int len() const;

    // 连接字符串
    CustomString append(const CustomString& other) const;

    // 比较字符串
    bool isEqual(const CustomString& other) const;


private:
	char* str;
	int length;
};


/*
实现string以下api，内部不能使用string，只能用数组存字符
auto str1 = CustomString("test1");
auto str2 = CustomString("test2, test3");
str1 = "test3";
int len = str1.len();
CustomString sub1 = str1.sub(1, 2);
str1.append("append");
bool equal = str1 == str2;
int index = str1.find("es");
CustomString* ret = str2.split(",");
*/
