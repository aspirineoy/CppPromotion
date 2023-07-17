#pragma once
#include <iostream>
#include <cstdlib>

// ����ڵ�ṹ
struct SkipNode {
    int value;
    SkipNode** next;

    SkipNode(int value, int level) {
        this->value = value;
        next = new SkipNode * [level + 1];
        for (int i = 0; i <= level; i++) {
            next[i] = nullptr;
        }
    }

    ~SkipNode() {
        delete[] next;
    }
};

class SkipList {
private:
    int maxLevel; // ���㼶
    int currentLevel; // ��ǰ�㼶
    SkipNode* head; // ͷ�ڵ�

public:
    SkipList(int maxLevel);

    ~SkipList();

    // ������ɽڵ�㼶
    int randomLevel() {
        int level = 0;
        while (rand() % 2 == 0 && level < maxLevel) {
            level++;
        }
        return level;
    }

    // �������в���Ԫ��
    void insert(int value);

    // ��������ɾ��Ԫ��
    void remove(int value);

    // ������������Ԫ��
    bool search(int value);
};
