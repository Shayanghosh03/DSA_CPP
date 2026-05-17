#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int, int> count;
    int maxFreq = 0;
    int ans = 0;

    for(int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i = 0; i < arr.size(); i++) {
        if(maxFreq == count[arr[i]]) {
            ans = arr[i];
            break;
        }
    }
    return ans;

}