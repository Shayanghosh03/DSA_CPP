// Subtract the product and sum of digits of an integer..
#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int prod = 1, sum = 0;
    while(n != 0) {
        int digit = n % 10;
        prod = prod * digit;
        sum = sum + digit;
        n = n % 10;
    }
    int ans = prod - sum;

    cout<<"Answer is: "<<ans;

    return 0;
}