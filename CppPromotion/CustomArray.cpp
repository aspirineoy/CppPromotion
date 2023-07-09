#include "CustomArray.h"
// ���캯��
CustomArray::CustomArray() {
    capacity = 10;
    size = 0;
    arr = new int[capacity];
}

// ��������
CustomArray::~CustomArray() {
    delete[] arr;
}

// �������캯��
CustomArray::CustomArray(const CustomArray& other) {
    capacity = other.capacity;
    size = other.size;
    arr = new int[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

// ��ֵ���������
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

// ���Ԫ��
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

// ɾ��Ԫ��
void CustomArray::remove(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

// ��ȡԪ�ظ���
int CustomArray::getSize() const {
    return size;
}

// ��ȡָ��λ�õ�Ԫ��
int CustomArray::get(int index) const {
    if (index >= 0 && index < size) {
        return arr[index];
    }
    else {
        return -1;
    }
}