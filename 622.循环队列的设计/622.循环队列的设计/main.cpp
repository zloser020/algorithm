#include<iostream>
using namespace std;
#include<vector>
class MyCircularQueue {
private:
    vector<int>arr;
    int size;
    int capacity;
    int front;
    int end;
public:
    MyCircularQueue(int k) {
        this->capacity = k + 1;
        this->arr = vector<int>(capacity);
        this->size = 0;
        this->front = 0;
        this->end = 0;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        size++;
        arr[end] = value;
        end = (end + 1) % capacity;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        size--;
        front = (front + 1) % capacity;
        return true;
    }

    int Front() {
        if (!isEmpty()) {
            return arr[front];
        }
        return -1;
    }

    int Rear() {
        if (!isEmpty()) {
            return arr[(end - 1 + capacity) % capacity];
        }
        return -1;
    }

    bool isEmpty() {
        return size == 0 ? true : false;
    }

    bool isFull() {
        return size == capacity - 1 ? true : false;
    }
};