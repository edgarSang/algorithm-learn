#include <iostream>

using namespace std;
int temp[100] = {0};

void merge_sort(int arr[], int start, int mid, int last) {
    int l = start;          //분할된것중 왼쪽배열의 인덱스
    int r = mid+1;          //분할된것중 오른쪽배열의 시작인덱스
    int tempIndex = start;   //새로 병합할 템프배열의 인덱스
    
    
    // start 가 middle보다 작거나같으면서, 
    //m+1이 last보다 작거나같을떄까지 반복.
    while(l <= mid && r <= last) {
        if(arr[l] <= arr[r]) {
            temp[tempIndex] = arr[l++];
        } else {
            temp[tempIndex] = arr[r++];
        }
        tempIndex++;
    }


    //한쪽 배열이 이미 Flsuh 됐을경우
    //나머지 배열을 temp에 모두넣어줌
    if(l > mid) {
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


    //정렬된 배열을 다시 원래 arr에 넣어줌
    for(int i = start; i <= last; i++) {
        arr[i] = temp[i];
    }
    for(int i=0; i<=4; i++) {
            cout << arr[i] << " ";
    } cout << endl;
}

void merge(int arr[], int start, int last) {
    int mid = (start+last) / 2;

    if(start < last) {
        // for(int i=start;i<=last; i++) {
        //     cout << arr[i] << " ";
        // } cout << endl;
        merge(arr, start, mid);
        merge(arr, mid+1, last);
        merge_sort(arr, start, mid, last);
    }

    return;
}


int main() {
    int arr[] = {5,1,2,4,3};

    merge(arr, 0, sizeof(arr)/sizeof(*arr)-1);
    for(int i=0; i < sizeof(arr)/sizeof(*arr); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}