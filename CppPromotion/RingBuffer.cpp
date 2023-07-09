#include "RingBuffer.h"

RingBuffer::RingBuffer() {
    capacity = 10;
    buffer = new int[capacity];
    front = 0;
    rear = 0;
    count = 0;
}

RingBuffer::RingBuffer(int initialCapacity) {
    capacity = initialCapacity;
    buffer = new int[capacity];
    front = 0;
    rear = 0;
    count = 0;
}

RingBuffer::~RingBuffer() {
    delete[] buffer;
}

bool RingBuffer::isEmpty() const {
    return count == 0;
}

bool RingBuffer::isFull() const {
    return count == capacity;
}

int RingBuffer::size() const {
    return count;
}

void RingBuffer::enqueue(int element) {
    if (isFull()) {
        expand();
    }

    buffer[rear] = element;
    rear = (rear + 1) % capacity;
    count++;
}

int RingBuffer::dequeue() {
    if (isEmpty()) {
        std::cout << "Buffer is empty" << std::endl;
        return -1;
    }

    int element = buffer[front];
    front = (front + 1) % capacity;
    count--;

    if (capacity >= 10 && count < capacity / 4) {
        shrink();
    }

    return element;
}

void RingBuffer::expand() {
    int newCapacity = capacity * 2;
    int* newBuffer = new int[newCapacity];

    for (int i = 0; i < count; i++) {
        newBuffer[i] = buffer[(front + i) % capacity];
    }

    delete[] buffer;

    buffer = newBuffer;
    front = 0;
    rear = count;
    capacity = newCapacity;
}

void RingBuffer::shrink() {
    int newCapacity = capacity / 2;
    int* newBuffer = new int[newCapacity];

    for (int i = 0; i < count; i++) {
        newBuffer[i] = buffer[(front + i) % capacity];
    }

    delete[] buffer;

    buffer = newBuffer;
    front = 0;
    rear = count;
    capacity = newCapacity;
}