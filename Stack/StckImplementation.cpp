#include<iostream>
using namespace std;
class Stack {
    public:
    int* arr;
    int top;
    int size;

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data) {
        if(size - top > 1) {
            top++;
            arr[top] = data;
        } else {
            cout<<"Stack is OverFlow"<<endl;
        }
    }
    void pop() {
        if(top >= 0) {
            top--;
        } else {
            cout<<"Stack is underflow"<<endl;
        }
    }
    int peek() {
        if(top >= 0 && top < size) {
            return arr[top];
        } else {
            cout<<"Stack is Empty"<<endl;
        }
    }
    bool empty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }
};
int main () {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    cout<<"Top of the stack "<<s.peek()<<endl;

    if(s.empty()) {
        cout<<"Stack is empty"<<endl;
    } else {
        cout<<"Stack is not empty"<<endl;
    }

    return 0;
}