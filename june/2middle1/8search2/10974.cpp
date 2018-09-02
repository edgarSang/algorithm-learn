#include <cstdio>
#include <vector>
using namespace std;

bool next_permutation(int *a, int n) {
    int i = n-1;
    while(i>0 && a[i-1] >= a[i]) {
        i -= 1;
    }
    if(i <= 0) return false;
    int j = n-1;
    while(j>0 && a[i-1] >= a[j]) {
        j -= 1;
    }
    swap(a[i-1], a[j]);
    j = n-1;
    while(i<j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for(int i=0; i<n; i++) {
        A[i] = i+1;
    }

    do {
        for(int i=0; i<n; i++) {
            printf("%d ", A[i]);
        }printf("\n");
    } while(next_permutation(A, n));

    return 0;
}