#include <iostream>

class Queue {
private:
    char *data;
    int size;

public:
    Queue();                                                           // standard constructor
    ~Queue();                                                          // standard destructor
    friend std::ostream &operator<<(std::ostream &os, const Queue &q); // overloaded << operator
    friend bool operator==(const Queue &q1, const Queue &q2);          // overloaded == operator (IsEqual())
    void Enqueue(char c);                                              // inserts a character at the end of the queue
    void Dequeue();                                                    // removes a character from the front of the queue
    int Size();                                                        // returns the current size of the queue
};