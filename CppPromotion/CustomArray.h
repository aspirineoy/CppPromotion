#pragma once
#include<iostream>
using namespace std;

class CustomArray
{
private:
    int* arr;
    int size;
    int capacity;
     
    CustomArray();

    // 析构函数
    ~CustomArray();

    // 拷贝构造函数
    CustomArray(const CustomArray& other);

    // 赋值运算符重载
    CustomArray& operator=(const CustomArray& other);

    // 添加元素
    void add(int element);

    // 删除元素
    void remove(int index);

    // 获取元素个数
    int getSize() const;

    // 获取指定位置的元素
    int get(int index) const;
};

