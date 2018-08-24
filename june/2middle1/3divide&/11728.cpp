#include <iostream>

using namespace std;

int A[2000000] = {0,};

int main() {
    int N, M;
    int li = 0;
    int ti = 0;
    int ri = 0;

    cin >> N >> M;

    int left[N];
    int right[M];

    for(int i=0; i<N; i++) {
        int in;
        cin >> in;
        left[i] = in;
    }
    for(int i=0; i<M; i++) {
        int in;
        cin >> in;
        right[i] = in;
    }

    while(li < N && ri < M) {
        if(left[li] < right[ri]) {
            A[ti++] = left[li++];
        } else {
            A[ti++] = right[ri++];
        }
    }

    while(li < N) {
        A[ti++] = left[li++];
    }
    while(ri < M) {
        A[ti++] = right[ri++];
    }       
        
    for(int i=0; i<ti; i++) {
        cout << A[i] << " ";
    }
    
    return 0;
}