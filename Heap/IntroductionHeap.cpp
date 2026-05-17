#include<iostream>
using namespace std;
class Heap {
    public:
    int arr[100];
    int size;
    Heap() {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parent = index / 2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
            } else {
                return;
            }
        }
    }
    void print() {
        for(int i = 1; i <= size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void deleteHeap() {
        if(size == 0) {
            cout<<"Nothing to delete"<<endl;
            return ;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while(i < size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i +1;
            if(leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }
};
void heapify(int arr[], int n, int i) {
    int large = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if(left < n && arr[large] < arr[left]) {
        large = left;
    }
    if(right < n && arr[large] < arr[right]) {
        large = right;
    }
    if(large != i) {
        swap(arr[large], arr[i]);
        heapify(arr, n, large);
    }
}
int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deleteHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 53, 50};
    int n = 5;
    for(int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    cout<<"Printing the array:"<<endl;
    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}