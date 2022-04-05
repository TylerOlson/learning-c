#ifndef LINKEDQUEUE
#define LINKEDQUEUE
#include <iostream>

struct QNode {
    char data;
    QNode *next;
};

class Queue {
private:
    QNode *front;

public:
    Queue();                                                           // standard constructor
    ~Queue();                                                          // standard destructor
    friend std::ostream &operator<<(std::ostream &os, const Queue &q); // overloaded << operator
    friend bool operator==(const Queue &q1, const Queue &q2);          // overloaded == operator (IsEqual())
    void Enqueue(char c);                                              // inserts a character at the end of the queue
    void Dequeue();                                                    // removes a character from the front of the queue
};
#endif