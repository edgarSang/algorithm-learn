#include <cstdio>
#include <algorithm>

using namespace std;

int W[10][10];
int A[10] = {0,};
bool next_permutation(int n) {
    int i = n-1;
    while(i>0 && A[i-1] >= A[i]) {
        i -= 1;
    }
    if(i<=0) {
        return false;
    }
    int j = n-1;
    while(j>0 && A[i-1] >= A[j]) {
        j -= 1;
    }
    swap(A[i-1],A[j]);
    j = n-1;
    while(i<j){
        swap(A[i],A[j]);
        i += 1;
        j -= 1;
    }

    return true;
}

int main() {
    int n;
    int min = 9000000;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        A[i] = i;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            scanf("%d", &W[i][j]);
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++){
    //         printf("%2d ", W[i][j]);
    //     }printf("\n");
    // }

    do {
        int total = 0;
        bool ok = true;
        for(int i=0; i<n-1; i++) {
            if(W[A[i]][A[i+1]] == 0) {
                ok = false;
            } else {
                total += W[A[i]][A[i+1]];   
            }
        }
        if(ok && W[A[n-1]][A[0]] != 0) {
            total += W[A[n-1]][A[0]];
            min = min < total ? min : total;
        }
    } while(next_permutation(n));
    
    printf("%d", min);

    return 0;
}