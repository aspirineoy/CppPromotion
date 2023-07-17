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

    // ���Ҳ���λ�ò���¼·��
    for (int i = currentLevel; i >= 0; i--) {
        while (node->next[i] != nullptr && node->next[i]->value < value) {
            node = node->next[i];
        }
        update[i] = node;
    }

    node = node->next[0];

    // ���ڵ��Ѵ��ڣ������ֵ
    if (node != nullptr && node->value == value) {
        node->value = value;
        delete[] update;
        return;
    }

    // ������ɽڵ�㼶
    int level = randomLevel();

    // ����½ڵ�Ĳ㼶���ڵ�ǰ�㼶�������·���еĽڵ�ָ��
    if (level > currentLevel) {
        for (int i = currentLevel + 1; i <= level; i++) {
            update[i] = head;
        }
        currentLevel = level;
    }

    // �����½ڵ�
    node = new SkipNode(value, level);

    // ���½ڵ�ָ��
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

    // ����ɾ��λ�ò���¼·��
    for (int i = currentLevel; i >= 0; i--) {
        while (node->next[i] != nullptr && node->next[i]->value < value) {
            node = node->next[i];
        }
        update[i] = node;
    }

    node = node->next[0];

    // ���ڵ���ڣ���ɾ��
    if (node != nullptr && node->value == value) {
        for (int i = 0; i <= currentLevel; i++) {
            if (update[i]->next[i] != node) {
                break;
            }
            update[i]->next[i] = node->next[i];
        }
        delete node;

        // ���µ�ǰ�㼶
        while (currentLevel > 0 && head->next[currentLevel] == nullptr) {
            currentLevel--;
        }
    }

    delete[] update;
}

bool SkipList::search(int value)
{
    SkipNode* node = head;

    // ����߲㼶��ʼ��������
    for (int i = currentLevel; i >= 0; i--) {
        while (node->next[i] != nullptr && node->next[i]->value < value) {
            node = node->next[i];
        }
    }

    node = node->next[0];

    // ���ҵ�Ŀ��ڵ㣬�򷵻�true
    return (node != nullptr && node->
        value == value);
}
