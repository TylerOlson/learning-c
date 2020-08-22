#include <iostream>

class Queue {
private:
    char *data;

public:
    Queue();  // standard constructor
    ~Queue(); // standard destructor
    friend std::ostream &operator<<(std::ostream &os, const Queue &q);
    void Enqueue(char c); // inserts a character at the end of the queue
    void Dequeue();       // removes a character from the front of the queue
};