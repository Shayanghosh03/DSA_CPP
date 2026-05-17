#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<string> s;
    s.push("Shayan");
    s.push("Kumar");
    s.push("Ghosh");

    cout<<"Top Elemnt: "<<s.top()<<endl;
    s.pop();
    cout<<"Top Elemnt: "<<s.top()<<endl;
    cout<<"Size: "<<s.size()<<endl;
    cout<<"Empty or not"<<s.empty()<<endl;

    return 0;
}