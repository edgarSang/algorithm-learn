#include <iostream>

using namespace std;
#define MAX 1000
int A[MAX] = {0};
int tempArr[MAX] = {0};

inline void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick(int A[], int start, int end) {
    int pivot = start;
    int left = start+1;
    int right = end;
    if(start < end) {
        while(true){
            while(A[left] < A[pivot]) {
                if(left > right) break;
                left ++;
            }
            while(A[right] > A[pivot]) {
                if(left > right) break;
                right --;
            }

            if(left > right) break;
            swap(&A[left], &A[right]);
        }

        swap(&A[pivot], &A[right]);
        quick(A, start, right-1);
        quick(A, right+1, end);
    }
    return;
}

void merge_sort(int start, int mid, int last) {
    int left = start;
    int right = mid+1;
    int tIdx = start;

    while(left <= mid && right <= last) {
        if(A[left] < A[right]) {
            tempArr[tIdx++] = A[left++];
        } else {
            tempArr[tIdx++] = A[right++];
        }
    }

    if(left > mid) {
        for(int i=right;i<=last;i++){
            tempArr[tIdx++] = A[i];
        }
    } else {
        for(int i=left;i<=mid;i++){
            tempArr[tIdx++] = A[i];
        }
    }

    for(int i=start;i<=last;i++){
        A[i] = tempArr[i];
    }
    return;
}


void merge_split(int start, int last) {
    int mid = (start + last) / 2;
    
    if(start < last) {
        merge_split(start, mid);
        merge_split(mid+1, last);
        merge_sort(start, mid, last);
    }
    
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){ 
        scanf("%d", &A[i]);
    }
    merge_split(0, n-1);

    for(int i=0;i<n;i++) {
        printf("%d\n" , A[i]);
    }

    return 0;
}