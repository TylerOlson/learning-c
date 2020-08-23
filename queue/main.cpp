#include "queue.h"

int main() {
    std::cout << "Starting program" << std::endl;

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

    std::cout << myQueue; // This should print out exactly "lo\n" without the quotes

    myQueue.Enqueue('n');
    
    std::cout << myQueue; // This should print out exactly "lon\n" without the quotes

    Queue myQueue2;
    myQueue2.Enqueue('l');
    myQueue2.Enqueue('o');
    myQueue2.Enqueue('n');

    if(myQueue == myQueue2) {
        std::cout << "This should print" << std::endl;
    }

    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue(); // These should NOT seg fault
    myQueue.Dequeue();
    myQueue.Dequeue();
    myQueue.Dequeue();

    if(myQueue == myQueue2) {
        std::cout << "This should not print" << std::endl;
    }

    std::cout << "Ending program" << std::endl;

    return 0;
}