#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int, string> m;

    m[1] = "Shayan";
    m[13] = "san";
    m[3] = "Ghosh";

    for(auto i : m) {
        cout<<i.first<<" ";
    }
    cout<<endl;
    for(auto i : m) {
        cout<<i.second<<" ";
    }
    cout<<endl;

    m.insert({5, "Bheem"});

    for(auto i : m) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Finding 13: "<<m.count(13)<<endl;

    cout<<"Erase 13"<<endl;
    m.erase(13);

    auto it = m.find(1);

    for(auto i = it; i != m.end(); i++) {
        cout<<(*i).first<<endl;
    }

    return 0;
}