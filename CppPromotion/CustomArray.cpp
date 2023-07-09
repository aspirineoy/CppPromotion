#include "CustomArray.h"
// 构造函数
CustomArray::CustomArray() {
    capacity = 10;
    size = 0;
    arr = new int[capacity];
}

// 析构函数
CustomArray::~CustomArray() {
    delete[] arr;
}

// 拷贝构造函数
CustomArray::CustomArray(const CustomArray& other) {
    capacity = other.capacity;
    size = other.size;
    arr = new int[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

// 赋值运算符重载
CustomArray& CustomArray::operator=(const CustomArray& other) {
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// 添加元素
void CustomArray::add(int element) {
    if (size == capacity) {
        capacity *= 2;
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    arr[size] = element;
    size++;
}

// 删除元素
void CustomArray::remove(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

// 获取元素个数
int CustomArray::getSize() const {
    return size;
}

// 获取指定位置的元素
int CustomArray::get(int index) const {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    else {
        return -1;
    }
}