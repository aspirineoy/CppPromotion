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

    // ��������
    ~CustomArray();

    // �������캯��
    CustomArray(const CustomArray& other);

    // ��ֵ���������
    CustomArray& operator=(const CustomArray& other);

    // ���Ԫ��
    void add(int element);

    // ɾ��Ԫ��
    void remove(int index);

    // ��ȡԪ�ظ���
    int getSize() const;

    // ��ȡָ��λ�õ�Ԫ��
    int get(int index) const;
};

