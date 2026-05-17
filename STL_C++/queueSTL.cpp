#include<iostream>
#include<queue>
using namespace std;

int main() {
    queue<string> q;
    q.push("Shayan");
    q.push("Kumar");
    q.push("Ghosh");

    cout<<"First Element: "<<q.front()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    q.pop();

    cout<<"After pop size: "<<q.size();
    cout<<endl;

    return 0;
}