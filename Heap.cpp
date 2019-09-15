#include <iostream>
using namespace std;


void swap(int* a, int src, int dest) {
    int t = a[src];
    a[src] = a[dest];
    a[dest] = t;
}

void maxHeaplify(int* heap, int N, int i){
    int right = 2 * i + 1;
    int left = 2 * i;
    int largest = i;

    if (left < N && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < N && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap, largest, i);
        maxHeaplify(heap, N, largest);
    }
}


int main(){
    int n;
    cin >> n;
    int heap[n];
    for (int i = 0;i < n;i++) {
        cin >> heap[i];
    }
    
    for (int i = n/2;i >=0 ;i--) {
        maxHeaplify(heap, n, i);
    }

    for (int i = 0;i < n ;i++) {
        cout << heap[i] << " ";
    }
    return 0;
}