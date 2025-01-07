#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL; // Initialize next to NULL
    }
};

class Queue {
    Node* head;
    Node* tail;
    int size; // To track the number of elements

public:
    Queue() {
        this->head = NULL; // Initialize head to NULL
        this->tail = NULL; // Initialize tail to NULL
        this->size = 0; // Initialize size to 0
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (this->tail == NULL) {
            // If the queue is empty
            this->head = this->tail = newNode;
        } else {
            // Add the new node at the end and update the tail
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void dequeue() {
        if (this->head == NULL) {
            // Queue is empty
            return;
        } else {
            // Remove the front node and update head
            Node* oldHead = this->head;
            this->head = this->head->next;
            if (this->head == NULL) {
                // If the queue becomes empty, update tail as well
                this->tail = NULL;
            }
            delete oldHead;
            this->size--;
        }
    }

    int getSize() {
        return this->size;
    }

    bool isEmpty() {
        return this->head == NULL;
    }

    int front() {
        if (this->head == NULL) return -1;
        return this->head->data;
    }
};

int main() {
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);

    while (!qu.isEmpty()) {
        cout << qu.front() << " ";
        qu.dequeue();
    }
    return 0;
}
