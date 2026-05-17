#include<iostream>
#include<set>
using namespace std;

int main() {
    set<int> s;

    
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(6);

    for(int i : s) {
        cout<<i<<" ";
    }
    cout<<endl;

    s.erase(s.begin());

    for(int i : s) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.empty()<<endl;

    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    for(auto i : s) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"3 is present or not: "<<s.count(3)<<endl;
    
    set<int>::iterator itr = s.find(3);
    cout<<"value present at itr: "<<*itr<<endl;

    return 0;
}