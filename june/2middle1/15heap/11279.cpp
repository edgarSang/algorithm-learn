#include <iostream>
#define MAX 100001

int maxHeap[MAX] = {0,};
//들어갈자리임
int hn;

inline void swap(int &a, int&b) {
    int temp = a;
    a = b;
    b = temp;
}

void push(int x) {
    maxHeap[++hn] = x;
    for(int i=hn; i>1; i/=2) {
        if(maxHeap[i] > maxHeap[i/2]) {
            swap(maxHeap[i], maxHeap[i/2]);
        } else {
            break;
        }
    }
}

int pop() {
    int ret = maxHeap[1];
    maxHeap[1] = maxHeap[hn];
    maxHeap[hn--] = 0;

    for(int i=1; i*2 <= hn;) {
        if(maxHeap[i] > maxHeap[i*2] && maxHeap[i] > maxHeap[i*2+1]) {
            break;
        } else if(maxHeap[i*2] > maxHeap[i*2+1]) {
            swap(maxHeap[i], maxHeap[i*2]);
            i = i*2;
        } else {
            swap(maxHeap[i], maxHeap[i*2+1]);
            i = i*2+1;
        }
    }

    return ret;
}

int main() {
    int N;

    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        int in;
        scanf("%d", &in);
        if(in == 0) {
            if(hn==0) {
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