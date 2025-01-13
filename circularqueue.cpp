#include <iostream>
#include <vector>
using namespace std;

class Queue {
    int front;  // Index of the front of the queue
    int back;   // Index of the back of the queue
    vector<int> v;
    int cs;     // Current size
    int ts;     // Total size (capacity)

public:
    Queue(int n) : front(0), back(-1), cs(0), ts(n) {
        v.resize(n);
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        back = (back + 1) % ts;
        v[back] = data;
        cs++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % ts;
        cs--;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // or throw an exception
        }
        return v[front];
    }

    bool isEmpty() {
        return cs == 0;
    }

    bool isFull() {
        return cs == ts;
    }
};

int main() {
    Queue qu(3); // Create a queue with capacity of 3

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);
    qu.enqueue(500);

    while (!qu.isEmpty()) {
        cout << qu.getFront() << " ";
        qu.dequeue();
    }
    cout << endl;

    return 0;
}
