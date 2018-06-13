#include <iostream>

using namespace std;

void merge(int arr[], int start, int last) {
    int mid = (start+last) / 2;

    if(start < last) {
        cout << "start: " << start << " last: " << last << " mid: " << mid << endl;
        merge(arr, start, mid);
        merge(arr, mid+1, last);
    }

    return;
}

int main() {
    int arr[] = {5,1,2,4,3};

    merge(arr, 0, sizeof(arr)/sizeof(*arr) - 1);
    return 0;
}