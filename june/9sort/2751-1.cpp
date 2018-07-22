#include <iostream>

using namespace std;

int A[1000] = {0,};

void swap(int * a, int * b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int arr[], int start, int last) {
    int pivot = start;
    int left = start+1;
    int right = last;

    while (true) {
        while(arr[left] < arr[pivot]) { left++; }
        while(arr[pivot] < arr[right]) { right--; }
        
        if(left > right) { break; }

        swap(&arr[left], &arr[right]);
    }

    if(start < last) {
        swap(&arr[pivot] , &arr[right]);
        quickSort(arr, left, right-1);
        quickSort(arr, right+1, last);
    }
}

void merge_sort(int arr[], int start, int mid ,int last) {
    int temp[last+1] = {0,};
    int left = start;
    int right = mid+1;
    int tempCur = start;

    while(left <= mid && right <= last) {
        if(arr[left] < arr[right]) {
            temp[tempCur] = arr[left++];
            tempCur ++;
        } else {
            temp[tempCur] = arr[right++];
            tempCur ++;
        }
    }

    if(left <= mid) {
        for(int i=left; i<=mid; i++) {
            temp[tempCur] = arr[i];
            tempCur ++;
        }
    } else {
        for(int i=right; i<=last; i++){
            temp[tempCur] = arr[i];
            tempCur ++;
        }
    }

    for(int i=start; i<=last; i++) {
        arr[i] = temp[i];
    }
}

void merge_split(int arr[], int start, int last) {
    int mid = (start + last) / 2;
    
    if(start < last) {
        merge_split(arr, start, mid);
        merge_split(arr ,mid+1, last);
        merge_sort(arr, start, mid, last);
    }
}


int main() {
    int arr[] = {2,1,3,5,4};
    //quickSort(arr, 0, sizeof(arr) / sizeof(&arr) - 1);
    merge_split(arr, 0, sizeof(arr) / sizeof(&arr) - 1);

    for(int i = 0; i < sizeof(arr) / sizeof(&arr) ; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}