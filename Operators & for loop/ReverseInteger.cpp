#include<iostream>
using namespace std;

int main() {
    int num;
    cout<<"Enter a Number: ";
    cin>>num;
    int r = 0;
    while(num != 0) {
        int l = num % 10;
        r = r * 10 + l;
        num = num / 10;
    }
    cout<<"Answer is: "<<r<<endl;

    return 0;
}