#include<iostream>
#include<deque>
using namespace std;

int main() {
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(50);
    d.push_front(80);

    cout<<"Before pop"<<endl;
    for(int i : d) {
        cout<<i<<" ";
    }
    cout<<endl;

    d.pop_front();
    d.pop_back();

    cout<<"After pop"<<endl;
    for(int i : d) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"First Index Element: "<<d.at(1)<<endl;
    cout<<"Front: "<<d.front()<<endl;
    cout<<"Back: "<<d.back()<<endl;
    cout<<"Empty or not: "<<d.empty()<<endl;

    cout<<"Before erase the Size: "<<d.size()<<endl;
    d.erase(d.begin(), d.begin() + 2);
    cout<<"After erase the size: "<<d.size()<<endl;

    for(int i : d) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}