#include<iostream>
#include<queue>
using namespace std;

int main() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(40);

    cout<<"Front is "<<d.front()<<endl;
    cout<<"Back is "<<d.back()<<endl;

    d.pop_back();
    d.pop_front();

    cout<<"Front is "<<d.front()<<endl;
    cout<<"Back is "<<d.back()<<endl;

    return 0;
}