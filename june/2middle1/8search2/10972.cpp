#include <cstdio>
#include <vector>
using namespace std;

bool next_permutation(int *A,int n) {
    int i = n-1;
    while (i > 0 && A[i-1] >= A[i]) {
        i -= 1;
    }
    //마지막순열
    if(i <= 0) { return false; }
    int j = n-1;
    while(A[j] <= A[i-1]) {
        j -= 1;
    }
    swap(A[i-1], A[j]);
    j = n-1;
    while(i<j) {
        swap(A[i], A[j]);
        i += 1; 
        j -= 1;
    } 
    return true;
}

int main() {
    int N;
    scanf("%d", &N);
    int A[N] = {0,};
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }

    if(next_permutation(A,N)) {
        for(int i=0; i<N; i++){
            printf("%d ", A[i]);
        }
    } else {
        printf("-1");
    }

    return 0;
}