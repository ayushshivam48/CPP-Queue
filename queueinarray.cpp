#include <iostream>
#include<vector>
using namespace std;

class Queue {
    int front = -1;
    int back;
    vector<int> v;

public:
    Queue(){
        this->back = -1;
        this->front = -1;
    }

    void enqueue(int data){
        v.push_back(data);
        this->back++;
        if(this->back == 0) this->front = 0;
    }

    void dequeue(){
        if(this->front == this->back){
            this->front = -1;
            this->back = -1;
            this->v.clear();
        }else this->front++;
    }

    int getFront(){
        if(this->front == -1) return -1;
        return this->v[this->front];
    }

    bool isEmpty(){
        return this->front == -1;
    }
};

int main() {
    Queue qu; // Create a queue with capacity of 5

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(400);

    while (!qu.isEmpty()) {
        cout << qu.getFront() << " ";
        qu.dequeue();
    }
    return 0;

   
}
