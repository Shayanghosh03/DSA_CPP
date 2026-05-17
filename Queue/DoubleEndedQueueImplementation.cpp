#include <iostream>
using namespace std; 
class Deque {
    int* arr;
    int size;
    int qfront;
    int rear;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if((qfront == 0 && rear == size - 1) || (rear == (qfront - 1 + size) % size)) {
            return false;
        } else if(qfront == -1) {
            qfront = rear = 0;
        } else if(qfront == 0 ) {
            qfront = size - 1;
        } else {
            qfront--;
        }
        arr[qfront] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if((qfront == 0 && rear == size - 1) || (rear == (qfront - 1 + size) % size)) {
            return false;
        } else if(qfront == -1) {
            qfront = rear = 0;
        } else if(rear == size - 1 && qfront != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(qfront == -1) {
            return -1;
        }
        int ans = arr[qfront];
        arr[qfront] = -1;
        if(qfront == rear) {
            qfront = rear = -1;
        } else if(qfront == size - 1) {
            qfront = 0;
        } else {
            qfront++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(qfront == -1) {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(qfront == rear) {
            qfront = rear = -1;
        } else if(rear == 0) {
            rear = size - 1;
        } else {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(qfront == -1) {
            return -1;
        }
        return arr[qfront];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(qfront == -1) {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        return qfront == -1;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        return ((qfront == 0 && rear == size - 1) || (rear == (qfront - 1 + size) % size));
    }
};