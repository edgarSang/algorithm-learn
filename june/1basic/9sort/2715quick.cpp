#include <iostream>

using namespace std;

template <typename T>
inline T comp(T a, T b) {
    return a < b;
}

inline void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick(int arr[], int start, int end) {
    int pivot = start;
    int left = start + 1;
    int right = end;


    cout << "start: " <<start << " end: " << end << endl;
    cout << "left: " <<left << " right: " << right << endl;
    while(1) {
        for(int i = 0; i < 5 ; i++) {
            cout << arr[i] << " ";
        }cout << endl;
        
        while(arr[left] < arr[pivot]) { left ++; }
        while(arr[right] > arr[pivot]) { right --; }

        if(right < left) break;

        swap(&arr[left], &arr[right]);
    }

    //여기를  right left 로 줘버렸더니  무한루프에 빠져버렸다 왜 일까? --> 여기에오면 무조건 left < right 일수밖에없다.
    //난 이 if문을 태워야하고 , 인자를 left right에서만 생각했기때문에, 인자가 1개일때도(0, 1) 무한루프에 빠져버린것이다.
    //start , end로 인자를 보내버리면, 인자가 1개일때 빼고는 이 이프문을 다 탄다.
    if(start < end) { 
        swap(&arr[start], &arr[right]); // 피봇, right 스왑.
        for(int i = 0; i < 5 ; i++) {
            cout << arr[i] << " ";
        } cout << endl;
        quick(arr, start, right-1);
        quick(arr, right+1, end);
    }

    return;
}

int main() {
    int arr[] = {2,1,3,5,4};

    quick(arr, 0, sizeof(arr) / sizeof(&arr) - 1);

    for(int i = 0; i < sizeof(arr) / sizeof(&arr) ; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}