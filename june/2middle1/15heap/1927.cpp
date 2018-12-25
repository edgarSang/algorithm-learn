#include <iostream>

#define MAX 1000001

int minHeap[MAX] = {0,};
int nh = 0;

inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void push(int x) {
    minHeap[++nh] = x;
    
    for(int i=nh; i>1; i/=2) {
        if(minHeap[i] < minHeap[i/2]) {
            swap(minHeap[i], minHeap[i/2]);
        } else {
            break;
        }
    }

}

int pop() {
    int ret = minHeap[1];
    minHeap[1] = minHeap[nh];
    minHeap[nh--] = 0;


    for(int i=1; i*2<=nh;) {
        if(minHeap[i] < minHeap[i*2] && (minHeap[i] < minHeap[i*2+1]  || minHeap[i*2+1] == 0)) {
            break;
        } else if (minHeap[i*2] < minHeap[i*2+1] || minHeap[i*2+1] == 0) {
            swap(minHeap[i], minHeap[i*2]);
            i = i*2;
        } else {
            swap(minHeap[i], minHeap[i*2+1]);
            i = i*2+1;
        }
    }

    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        int in;
        scanf("%d", &in);

        if(in == 0) {
            if(nh == 0) {
                printf("0\n");
            } else {
                int ret = pop();
                printf("%d\n", ret);
            }
        } else {
            push(in);
        }
    }
    return 0;
}