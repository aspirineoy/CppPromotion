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
    // ���캯��
    CustomList();

    // ��������
    ~CustomList();

    // �������캯��
    CustomList(const CustomList& other);

    // ��ֵ���������
    CustomList& operator=(const CustomList& other);

    // ��ͷ������Ԫ��
    void insertAtHead(int element);

    // ��β������Ԫ��
    void insertAtTail(int element);

    // ��ָ��λ�ò���Ԫ��
    void insertAt(int index, int element);

    // ɾ��ָ��λ�õ�Ԫ��
    void removeAt(int index);

    // ��ȡ�����С
    int getSize() const;

    // ��ȡָ��λ�õ�Ԫ��
    int getElementAt(int index) const;
};

