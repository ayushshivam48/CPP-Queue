#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, capacity, size;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->front = 0;
        this->rear = -1;
        this->size = 0;
        this->arr = new int[capacity];
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity; // Circular increment
        arr[rear] = data;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % capacity; // Circular increment
        size--;
    }

    int getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size == capacity;
    }

    int frontElement() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // or throw an exception
        }
        return arr[front];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        int i = front;
        for (int count = 0; count < size; count++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Queue qu(5); // Create a queue with capacity of 5

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.enqueue(50);

    cout << "Queue contents: ";
    qu.display();

    qu.dequeue();
    qu.enqueue(60);

    cout << "Queue contents after dequeue and enqueue: ";
    qu.display();

    cout << "Front element: " << qu.frontElement() << endl;
    cout << "Queue size: " << qu.getSize() << endl;

    return 0;
}
