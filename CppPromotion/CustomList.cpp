#include "CustomList.h"

// 构造函数
CustomList::CustomList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// 析构函数
CustomList::~CustomList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// 拷贝构造函数
CustomList::CustomList(const CustomList& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;

    Node* current = other.head;
    while (current != nullptr) {
        insertAtTail(current->data);
        current = current->next;
    }
}

// 赋值运算符重载
CustomList& CustomList::operator=(const CustomList& other) {
    if (this != &other) {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;

        Node* current = other.head;
        while (current != nullptr) {
            insertAtTail(current->data);
            current = current->next;
        }
    }
    return *this;
}

// 在头部插入元素
void CustomList::insertAtHead(int element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head == nullptr) {
        tail = newNode;
    }
    else {
        head->prev = newNode;
    }

    head = newNode;
    size++;
}

// 在尾部插入元素
void CustomList::insertAtTail(int element) {
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
    }

    tail = newNode;
    size++;
}

void CustomList::insertAt(int index, int element)
{
    if (index < 0 || index >= size) {
        std::cout << "Index out of range" << std::endl;
        return;
    }

    Node* current = head;
    if (index == 0) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
    }
    else {
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->prev->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }
    }

    delete current;
    size--;
}

int CustomList::getSize() const
{
    return size;
}

int CustomList::getElementAt(int index) const
{
    if (index < 0 || index >= size) {
        std::cout << "Index out of range" << std::endl;
        return -1;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}
