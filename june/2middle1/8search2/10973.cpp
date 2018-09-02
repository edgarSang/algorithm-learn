#include <cstdio>
#include <vector>

using namespace std;

bool pre_permutation(int *A, int n) {
    int i = n-1;
    while(i > 0 && A[i] > A[i-1]) {
        i -= 1;
    }
    if(i <= 0) return false;
    int j = n-1;
    while(A[j] >= A[i-1]) {
        j -= 1;
    }
    swap(A[j],A[i-1]);
    j = n-1;
    while(i<j) {
        swap(A[i], A[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n] = {0,};

    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }

    if(pre_permutation(A,n)) {
        for(int i=0; i<n; i++) {
            printf("%d ", A[i]);
        }
    } else {
        printf("-1");
    }
    printf("\n");

    return 0;
}