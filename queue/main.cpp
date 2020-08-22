#include "queue.h"

int main() {
    Queue myQueue;
    myQueue.Enqueue('h');
    myQueue.Enqueue('e');
    myQueue.Enqueue('l');
    myQueue.Enqueue('l');
    myQueue.Enqueue('o');

    std::cout << myQueue; // This should print out exactly "hello\n" without the quotes

    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();

    std::cout << myQueue; // This should print out exactly "he\n" without the quotes

    myQueue.Enqueue('n'); // This should print out exactly "hen\n" without the quotes

    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue(); // These should NOT seg fault
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();

    return 0;
}