#pragma once
#include<iostream>

class CustomList
{
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;
    int size;

public:
    // 构造函数
    CustomList();

    // 析构函数
    ~CustomList();

    // 拷贝构造函数
    CustomList(const CustomList& other);

    // 赋值运算符重载
    CustomList& operator=(const CustomList& other);

    // 在头部插入元素
    void insertAtHead(int element);

    // 在尾部插入元素
    void insertAtTail(int element);

    // 在指定位置插入元素
    void insertAt(int index, int element);

    // 删除指定位置的元素
    void removeAt(int index);

    // 获取链表大小
    int getSize() const;

    // 获取指定位置的元素
    int getElementAt(int index) const;
};

