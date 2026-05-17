#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {

    // Creation
    unordered_map<string, int> m; // When we use the unorderd_map then data will be print random order

    // Insertion 
    // Type -> 1
    pair<string, int> pair1 = make_pair("Shayan", 1);
    m.insert(pair1);

    // Type -> 2
    pair<string, int> pair2("Ghosh", 3);
    m.insert(pair2);

    // Type -> 3
    m["Kumar"] = 2;

    // Search
    cout<<m["Shayan"]<<endl;
    cout<<m.at("Ghosh")<<endl;
    cout<<m["unknownKey"]<<endl;
    cout<<m.at("unknownKey")<<endl;

    // Size
    cout<<m.size()<<endl;

    // To check Present
    cout<<m.count("Kumar")<<endl; // If present then output will be 1
    cout<<m.count("AbsentKey")<<endl; // If not present then output will be 0

    // Erase
    m.erase("Kumar");
    cout<<m.size()<<endl;

    // Access the data
    for(auto i : m) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    // Using iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()) {
        cout<<it -> first<<" "<<it -> second<<endl;
        it++;
    }
    cout<<endl;


    //Map
    map<string, int> mp;
    pair<string, int> p1 = make_pair("San", 1);
    mp.insert(p1);
    pair<string, int> p2("Hello", 2);
    mp.insert(p2);
    mp["Hiiii"] = 0;

    for(auto i : mp) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}