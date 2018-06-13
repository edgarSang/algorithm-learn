#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick(int arr[], int start, int end) {
    int pivot = start;
    int left = start + 1;
    int right = end;

    // for(int i=0; i<5; i++) {
    //     cout << arr[i] << " ";
    // } cout << endl;
    // cout << "left: " << left << " right: " << right << " pivot: " << pivot << endl;

    while(1) {
        while(arr[left] < arr[pivot]){ left++; }
        while(arr[right] > arr[pivot]){ right--; }

        if(left > right) break;
        swap(&arr[left], &arr[right]);
    }

    if(start < end) {
        swap(&arr[pivot], &arr[right]);
        for(int i=0; i<5; i++) {
            cout << arr[i] << " ";
        } cout << endl;
        cout << "left: " << left << " right: " << right << " pivot: " << pivot << endl;
        
        quick(arr, start, right-1);
        quick(arr, right+1, end);
    }

    return;
}

int main() {
    int arr[] = {3, 2, 5, 4, 1};

    quick(arr, 0, sizeof(arr)/sizeof(*arr)-1);
    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    } cout << endl;
    
    return 0;
}