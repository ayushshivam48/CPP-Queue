#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Queue{
    stack<int> st;
public:
    Queue(){}

    void push(int x){  //enqueue
        this->st.push(x);
    }

    void pop(){   //dequeue
    if(this->st.empty()) return;
        stack<int> tmp;
        while(this->st.size()>1){
            tmp.push(st.top());
            st.pop();
        }
        //now stack size is 1 , and we are at the bottom element
        this->st.pop();
        while(!tmp.empty()){
            this->st.push(tmp.top());
            tmp.pop();
        }
    }

    bool empty(){
        return this->st.empty();
    }

    int front(){
        if(this->st.empty()) return -1;
        stack<int> tmp;
        while(this->st.size()>1){
            tmp.push(st.top());
            st.pop();
        }
        //now stack size is 1 , and we are at the bottom element
        int result = this->st.top();
        while(!tmp.empty()){
            this->st.push(tmp.top());
            tmp.pop();
        }
        return result;
    }
};

int main() {
    Queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.pop();
    while (!qu.empty()) {
        cout << qu.front() << " ";
        qu.pop();
    }
    return 0;
}
