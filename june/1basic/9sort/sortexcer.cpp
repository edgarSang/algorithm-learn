#include <iostream>

using namespace std;

void merge_sort(int arr[], int start, int mid, int last) {
    int temp[100];
    int tempIndex = start;
    int l = start;
    int r = mid + 1;

    while(l <= mid && r <= last) {
        if (arr[l] < arr[r]) {
            temp[tempIndex] = arr[l++];
            tempIndex++;
        } else {
            temp[tempIndex] = arr[r++];
            tempIndex++;
        }
    }

    if(mid < l) {
        for(int i=r; i<=last; i++) {
            temp[tempIndex] = arr[i];
            tempIndex++;
        }
    } else {
        for(int i=l; i<=mid; i++) {
            temp[tempIndex] = arr[i];
            tempIndex++;
        }
    }
    
    for(int i=start; i<=last; i++) {
        arr[i] = temp[i];
    }
    
    return;
}

void merge (int arr[], int start, int last) {
    int mid = (start+last) / 2;

    if(start < last) {
        merge(arr, start, mid);
        merge(arr, mid+1, last);
        merge_sort(arr, start, mid, last);
    }

    return;
}

inline void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick(int arr[], int start, int end) {
    int pivot = start;
    int left = start+1;
    int right = end;

    while(1) {
        while(arr[left] < arr[pivot]) { left++; }
        while(arr[right] > arr[pivot]) { right--; }

        //실수1 left > right로만 했었음
        if(left > right) break;

        swap(&arr[left], &arr[right]);
    }

    if(start < end) {
        swap(&arr[start], &arr[right]);
        quick(arr, start, right-1);
        quick(arr, right+1, end);
    }
}


int main() {
    int arr[] = {5,1,2,3,4};

    quick(arr, 0, sizeof(arr)/sizeof(*arr)-1);

    for(int i=0; i<sizeof(arr)/sizeof(*arr); i++) {
        cout << arr[i] << " ";
    } cout << endl;
    return 0;
}