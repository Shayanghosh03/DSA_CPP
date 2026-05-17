#include<iostream>
#include<list>
using namespace std;

int main() {
    list<int> l;
    l.push_back(10);
    l.push_front(20);
    l.push_back(45);
    l.push_front(67);
    l.push_back(98);
    l.push_front(66);

    for(int i : l) {
        cout<<i<<" ";
    }
    cout<<endl;
    l.erase(l.begin());

    cout<<"After erase the list is:"<<endl;
    for(int i : l) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Size of the list is: "<<l.size()<<endl;

    //Copy
    cout<<"Copy list:"<<endl;
    list<int> n(l);
    for(int i : n) {
        cout<<i<<" ";
    }
    cout<<endl;

    list<int> a(5, 100);
    for(int i : a) {
        cout<<i<<" ";
    }
    cout<<endl;

    l.front();
    l.back();
    
    return 0;
}