#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int num;
    cout<<"Enter the decimal number: ";
    cin>>num;
    int ans = 0;
    int i = 0;
    while(num != 0) {
        int bit = num & 1;
        ans = ans + (bit * pow(10, i));
        num = num >> 1;
        i++;
    }
    cout<<"Binary form is: "<<ans;

    return 0;
}