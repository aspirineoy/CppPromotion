#pragma once
#include<iostream>
class RingBuffer
{
private:
    int* buffer;
    int capacity;
    int front;
    int rear;
    int count;

public:
    RingBuffer();
    explicit RingBuffer(int initialCapacity);
    ~RingBuffer();

    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void enqueue(int element);
    int dequeue();
    void expand();
    void shrink();
};

