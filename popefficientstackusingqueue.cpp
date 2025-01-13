#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
    queue<int> q;

public:
    // Push operation is costly (O(n))
    void push(int x) {
        int size = q.size();
        q.push(x);
        // Rotate the elements to maintain stack order
        for (int i = 0; i < size; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    // Pop operation is efficient (O(1))
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        q.pop();
    }

    // Top operation is efficient (O(1))
    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // or throw an exception
        }
        return q.front();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackUsingQueue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl; // Output: 30

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // Output: 20

    stack.push(40);
    cout << "Top element after push: " << stack.top() << endl; // Output: 40

    return 0;
}
