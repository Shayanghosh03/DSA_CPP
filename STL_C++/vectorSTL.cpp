#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> v;
    cout<<"Capacity of the vector: "<<v.capacity()<<endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    cout<<"Capacity of the vector: "<<v.capacity()<<endl;
    cout<<"Actual size of the vector: "<<v.size()<<endl;

    cout<<"Element at 2nd position: "<<v.at(2)<<endl;
    cout<<"Element ar fornt position: "<<v.front()<<endl;
    cout<<"Element at back position: "<<v.back()<<endl;

    cout<<"Before pop: "<<endl;
    for(int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    v.pop_back();
    cout<<"After pop:"<< endl;
    for(int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Clear the vector
    v.clear();
    if(v.empty()) {
        cout<<"Empty"<<endl;
    } else {
        cout<<"Not Empty"<<endl;
    }

    vector<int> a(5,1);
    cout<<"Vector with initialize with 1:"<<endl;
    for(int i : a) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Copy
    vector<int> c(a);
    cout<<"Copy vector:"<<endl;
    for(int i : c) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}