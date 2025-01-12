#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    // Push operation is efficient (O(1))
    void push(int x) {
        q1.push(x);
    }

    // Pop operation is costly (O(n))
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        // Transfer all elements except the last one from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop(); // Remove the last element, which is the top of the stack
        
        // Swap queues
        swap(q1, q2);
    }

    // Top operation is costly (O(n))
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; // or throw an exception
        }
        // Transfer all elements except the last one from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        q2.push(topElement); // Push the last element to q2
        
        // Swap queues
        swap(q1, q2);
        return topElement;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues stack;

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
