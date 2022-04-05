#include "queue.h"

Queue::Queue() {
    data = nullptr;
    size = 0;
}

Queue::~Queue() {
    delete[] data;
    size = 0;
}

std::ostream &operator<<(std::ostream &os, const Queue &q) {
    for (int i = 0; i < q.size; i++) {
        os << q.data[i];
    }

    os << std::endl;

    return os;
}

bool operator==(const Queue &q1, const Queue &q2) {
    if (q1.size != q2.size) {
        return false;
    }

    for (int i = 0; i < q1.size; i++) {
        if (q1.data[i] != q2.data[i]) {
            return false;
        }
    }

    return true;
}

void Queue::Enqueue(char c) {
    char *newdata = new char[size + 1];

    for (int i = 0; i < size; i++) {
        newdata[i] = data[i];
    }

    newdata[size] = c;
    delete[] data;  // deletes old data
    data = newdata; // sets data pointer to new data
    size++;
}

void Queue::Dequeue() {
    if (size - 1 < 0) {
        return;
    }

    char *newdata = new char[size - 1];

    for (int i = 0; i < size - 1; i++) {
        newdata[i] = data[i + 1];
    }

    delete[] data;
    data = newdata;
    size--;
}

int Queue::Size() {
    return size;
}
