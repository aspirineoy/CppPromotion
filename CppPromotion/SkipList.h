#pragma once
#include <iostream>
#include <cstdlib>

// 跳表节点结构
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
    int maxLevel; // 最大层级
    int currentLevel; // 当前层级
    SkipNode* head; // 头节点

public:
    SkipList(int maxLevel);

    ~SkipList();

    // 随机生成节点层级
    int randomLevel() {
        int level = 0;
        while (rand() % 2 == 0 && level < maxLevel) {
            level++;
        }
        return level;
    }

    // 向跳表中插入元素
    void insert(int value);

    // 从跳表中删除元素
    void remove(int value);

    // 在跳表中搜索元素
    bool search(int value);
};
