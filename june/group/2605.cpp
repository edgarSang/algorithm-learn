#include <cstdio>
#include <iostream>

using namespace std;
int A[101];

int main() {
    int T;
    scanf("%d", &T);

    for(int i=1; i<=T; i++) {
        int in;
        scanf("%d", &in);
        if(in == 0) {
            A[i] = i;
        } else {
            for(int j=i; j>i-in; j--) {
                A[j] = A[j-1];
            }
            A[i-in] = i;
            // printf("i:%d, in:%d, j:%d\n", i,in,i-in);
            // for(int j=1; j<=i; j++) {
            //     printf("%d ", A[j]);
            // }printf("\n\n");
        }
    }

    for(int i=1; i<=T; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}