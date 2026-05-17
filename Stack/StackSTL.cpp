#include<iostream>
#include<stack>
using namespace std;
int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    
    s.pop();
    s.pop();
    cout<<"Top of the stack is "<<s.top()<<endl;
    cout<<"Size of the stack "<<s.size()<<endl;
    
    if(s.empty()) {
        cout<<"Stack is empty"<<endl;
    } else {
        cout<<"Stack is not empty"<<endl;
    }
    
    return 0;
}