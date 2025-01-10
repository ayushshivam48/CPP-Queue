#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class Deque {
    Node* head;
    Node* tail;
    int size;

public:
    Deque() : head(nullptr), tail(nullptr), size(0) {}

    ~Deque() {
        while (!isEmpty()) {
            popFront();
        }
    }

    void pushBack(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void popBack() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void pushFront(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void popFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    int getFront() const {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1; // or throw an exception
        }
        return head->data;
    }

    int getBack() const {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1; // or throw an exception
        }
        return tail->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushFront(2);

    cout << "Deque contents: ";
    dq.display();

    dq.popFront();
    dq.popBack();

    cout << "Deque contents after popping front and back: ";
    dq.display();

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Back element: " << dq.getBack() << endl;
    cout << "Deque size: " << dq.getSize() << endl;

    return 0;
}
