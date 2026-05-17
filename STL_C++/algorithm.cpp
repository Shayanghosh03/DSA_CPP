#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(10);
    v.push_back(8);
    v.push_back(9);

    cout<<"Binary Search: "<<binary_search(v.begin(), v.end(), 6)<<endl;
    cout<<"Lower Bound: "<<lower_bound(v.begin(), v.end(), 5) - v.begin()<<endl;

    cout<<"Upper Bound: "<<upper_bound(v.begin(), v.end(), 5) - v.begin()<<endl;

    int a = 3;
    int b = 5;
    cout<<"Max: "<<max(a,b)<<endl;
    cout<<"Min: "<<min(a,b)<<endl;

    swap(a,b);

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    string str = "Shayan";
    reverse(str.begin(), str.end());

    cout<<str<<endl;
    
    cout<<"Before Rotate: "<<endl;
    for(int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    rotate(v.begin(), v.begin() + 2, v.end());

    cout<<"After rotate: "<<endl;
    for(int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;

    sort(v.begin(), v.end());
    cout<<"After sort the array: "<<endl;
    for(int i : v) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}