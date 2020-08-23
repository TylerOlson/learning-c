#include "linkedqueue.h";

Queue::Queue() {}
Queue::~Queue() {}

std::ostream &operator<<(std::ostream &os, const Queue &q) {} // overloaded << operator
bool operator==(const Queue &q1, const Queue &q2) {}          // overloaded == operator (IsEqual())

void Queue::Enqueue(char c) {} // inserts a character at the end of the queue
void Queue::Dequeue() {}       // removes a character from the front of the queue