#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

class CustomString
{
public:
    // Ĭ�Ϲ��캯��
    CustomString();

    // ���ַ����鹹���ַ���
    CustomString(const char* s);

    // �������캯��
    CustomString(const CustomString& other);

    // ��������
    ~CustomString();

    // ��ֵ���������
    CustomString& operator=(const CustomString& other);

    // ��ȡ�ַ�������
    int len() const;

    // �����ַ���
    CustomString append(const CustomString& other) const;

    // �Ƚ��ַ���
    bool isEqual(const CustomString& other) const;


private:
	char* str;
	int length;
};


/*
ʵ��string����api���ڲ�����ʹ��string��ֻ����������ַ�
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
