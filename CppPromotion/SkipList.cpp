#include "SkipList.h"


SkipList::SkipList(int maxLevel)
{
	this->maxLevel = maxLevel;
	currentLevel = 0;
	head = new SkipNode(0, maxLevel);
}

SkipList::~SkipList()
{
    SkipNode* node = head->next[0];
    while (node != nullptr) {
        SkipNode* nextNode = node->next[0];
        delete node;
        node = nextNode;
    }
    delete head;
}

void SkipList::insert(int value)
{
    SkipNode** update = new SkipNode * [maxLevel + 1];
    SkipNode* node = head;

    // 查找插入位置并记录路径
    for (int i = currentLevel; i >= 0; i--) {
        while (node->next[i] != nullptr && node->next[i]->value < value) {
            node = node->next[i];
        }
        update[i] = node;
    }

    node = node->next[0];

    // 若节点已存在，则更新值
    if (node != nullptr && node->value == value) {
        node->value = value;
        delete[] update;
        return;
    }

    // 随机生成节点层级
    int level = randomLevel();

    // 如果新节点的层级大于当前层级，则更新路径中的节点指针
    if (level > currentLevel) {
        for (int i = currentLevel + 1; i <= level; i++) {
            update[i] = head;
        }
        currentLevel = level;
    }

    // 创建新节点
    node = new SkipNode(value, level);

    // 更新节点指针
    for (int i = 0; i <= level; i++) {
        node->next[i] = update[i]->next[i];
        update[i]->next[i] = node;
    }

    delete[] update;
}

void SkipList::remove(int value)
{
    SkipNode** update = new SkipNode * [maxLevel + 1];
    SkipNode* node = head;

    // 查找删除位置并记录路径
    for (int i = currentLevel; i >= 0; i--) {
        while (node->next[i] != nullptr && node->next[i]->value < value) {
            node = node->next[i];
        }
        update[i] = node;
    }

    node = node->next[0];

    // 若节点存在，则删除
    if (node != nullptr && node->value == value) {
        for (int i = 0; i <= currentLevel; i++) {
            if (update[i]->next[i] != node) {
                break;
            }
            update[i]->next[i] = node->next[i];
        }
        delete node;

        // 更新当前层级
        while (currentLevel > 0 && head->next[currentLevel] == nullptr) {
            currentLevel--;
        }
    }

    delete[] update;
}

bool SkipList::search(int value)
{
    SkipNode* node = head;

    // 从最高层级开始向下搜索
    for (int i = currentLevel; i >= 0; i--) {
        while (node->next[i] != nullptr && node->next[i]->value < value) {
            node = node->next[i];
        }
    }

    node = node->next[0];

    // 若找到目标节点，则返回true
    return (node != nullptr && node->
        value == value);
}
