#include <iostream>

#define MAX 1000

int heap[MAX] = {0,};
int hn = 0;

inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void push(int x) {
    heap[++hn] = x;
    //컬플릿 트리 부모에서 노드 위치가 n일때 부모는 n/2이다.
    for(int i=hn; i>1; i/=2) {
        if(heap[i/2] < heap[i]) {
            swap(heap[i/2], heap[i]);
        } else {
            break;
        }
    }
    //1.맨 마지막에 넣고
    //2.부모와 비교후 더 작으면 부모와 스왑
}

void pop() {
    heap[1] = heap[hn];
    heap[hn--] = 0;
    for(int i=1; i*2 <= hn;) {
        //힙 자기 왼쪽자식과 왼쪽자식보다 크면 끝
        if(heap[i] > heap[i*2] && heap[i] > heap[i*2+1]) {
            break;
        }
        //자기 왼쪽자식보다 작으면 swap 
        else if(heap[i] < heap[i*2]) {
            swap(heap[i], heap[i*2]);
            i = i*2;
        } else {
            swap(heap[i], heap[i*2+1]);
            i = i*2+1;
        }
    }
    //부모를 맨 마지막 요소와 바꾼후
    //자식과 비교해서 작을경우 내려감.
}

int main() {


    return 0;
}