#include <cstdio>
#include <algorithm>
#define MAX 8

using namespace std;


int A[MAX] = {0,};
// int f[max] = {0,};

bool next_permutation(int n) {
    int i = n-1;
    while(i>0 && A[i-1] >= A[i]) {
        i -= 1;
    }
    if(i<=0) {
        return false;
    }
    int j = n-1;
    while(i>0 && A[i-1] >= A[j]) {
        j -= 1;
    }
    swap(A[i-1],A[j]);
    j = n-1;
    while(i < j) {
        swap(A[i], A[j]);
        i += 1;
        j -= 1;
    }

    return true;
}

int main() {
    int n;
    scanf("%d" , &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, A+n);
    int max = 0;

    do {
        int total = 0;
        //n-1이 범위일경우 n이 0일경우 무한루프에빠질수도 있다
        for(int i=1; i<n; i++) {
            total += abs(A[i-1]-A[i]);
        }
        max = max > total ? max : total;
    } while(next_permutation(n));

    printf("%d\n", max);

    return 0;
}