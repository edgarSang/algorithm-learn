#include <iostream>
#include <cstdio>
#define MAX 100001
using namespace std;

int maxHeap[MAX] = {0, };
int hn;

inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insert(int a) {
    maxHeap[++hn] = a;
    for(int i=hn; i>1; i/=2) {
        if(maxHeap[i] > maxHeap[i/2]) {
            //자식이 부모보다 크면 바꾼다
            swap(maxHeap[i], maxHeap[i/2]);
        } else {
            break; //이미 다른곳은 정렬되어있기때문에 브레이크
        }
    }
}

int pop() {
    int ret = maxHeap[1];
    maxHeap[1] = maxHeap[hn];
    maxHeap[hn--] = 0;

    for(int i=1; i*2 <= hn;) {
        if(maxHeap[i] > maxHeap[i*2] && maxHeap[i] > maxHeap[i*2+1]) {
            break; // maxHeap[i]가 양쪽자식보다 다 클경우
        } else if(maxHeap[i] < maxHeap[i*2]) {
            swap(maxHeap[i], maxHeap[i*2]);
            i = i*2;
        } else {
            swap(maxHeap[i], maxHeap[i*2+1]);
            i = i*2+1;
        }
    }

}
 
int main() {
    int T;
    scanf("%d", &T);

    for(int i=0; i<T; i++) {
        int tmp;
        scanf("%d", &tmp);

        if(tmp == 0) {
            if(hn==0) {
                printf("0\n");
            } else {
                printf("%d\n", pop());
            }
        } else {
            insert(tmp);
        }
    }

    return 0;
}