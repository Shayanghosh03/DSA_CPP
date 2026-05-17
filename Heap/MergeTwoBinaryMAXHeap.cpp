#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Step-1 Merge both array into one
    vector<int> ans;
    for(auto i : arr1) {
        ans.push_back(i);
    }
    for(auto i : arr2) {
        ans.push_back(i);
    }
    int size = ans.size();

    // Step-2 Build heap using marged array
    for(int i = size / 2 - 1; i >= 0; i--) {
        heapify(ans, size, i);
    }

    return ans;
}