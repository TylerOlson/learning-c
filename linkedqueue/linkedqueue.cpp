#include "linkedqueue.h"

Queue::Queue() {
    front = nullptr;
}

Queue::~Queue() {
    if (front == nullptr) return;
    if (front->next == nullptr) {
        delete[] front;
        front = nullptr;
    }

    QNode *checker = front;
    QNode *next = front;

    while (checker != nullptr) {
        next = checker->next; //point to next
        delete[] checker;     //delete old
        checker = next;       //set back to next
    }

    // set all back to nullptr
    next = nullptr;
    front = nullptr;
}

std::ostream &operator<<(std::ostream &os, const Queue &q) {
    QNode *checker = q.front;

    while (checker != nullptr) {
        os << checker->data;
        checker = checker->next;
    }

    os << std::endl;
    return os;
}

bool operator==(const Queue &q1, const Queue &q2) {
    if (&q1 == &q2) return true; // if addresses are the same

    if (q1.front == nullptr) {
        if (q2.front == nullptr) return true; // both are null, equal
        return false;                         //one is null, inequal
    }

    QNode *checker1 = q1.front;
    QNode *checker2 = q2.front;

    while (checker1->data == checker2->data) { // while each segment is true, go to next one and check
        if (checker1->next == nullptr) {
            if (checker2->next == nullptr) return true; // both are null, escape and is equal
            return false;                               // only one is null, escape and is inequal
        }
        checker1 = checker1->next;
        checker2 = checker2->next;
    }

    return false;
}

void Queue::Enqueue(char c) {
    QNode *node = new QNode; // create new node
    node->data = c;
    node->next = nullptr;

    if (front == nullptr) { // if there are no objects, set first to node
        front = node;
        return;
    }

    QNode *checker = front; // start checking recursively, start at front

    while (checker->next != nullptr) { // repeat until next node is null
        checker = checker->next;
    }

    checker->next = node; // once node is null, set it to node
}

void Queue::Dequeue() {
    QNode *currentFront = front; // pointer to current front
    if (front == nullptr) return;

    front = front->next;   //shift front to next character
    delete[] currentFront; // delete old front
}