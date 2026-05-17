#include<iostream>
#include<queue>
using namespace std;
int main() {
    queue<int> q;
    q.push(12);
    q.push(11);
    q.push(56);
    q.push(23);
    cout<<"Size of the queue is "<<q.size()<<endl;
    cout<<"Front of the queue is "<<q.front()<<endl;


    q.pop();
    q.pop();
    cout<<"Size of the queue is "<<q.size()<<endl;
    cout<<"Front of the queue is "<<q.front()<<endl;

    if(q.empty()) {
        cout<<"Queue is empty"<<endl;
    } else {
        cout<<"Queue is not empty"<<endl;
    }


    return 0;
}