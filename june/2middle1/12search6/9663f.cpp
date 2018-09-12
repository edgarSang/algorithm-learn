#include <cstdio>
#include <math.h>


int cntNqeen(int x, int y, int N) {
    for(int i=0; i<N; i++) {
        if(i==x) {
            
        }
    }
}

int main() {
    int N, cnt=0, total=0;
    scanf("%d" , &N);   

    for(int i=0; i<N; i++) {
        cnt += cntNqeen(i, 0, N);
    }

    printf("%d\n", cnt);
    return 0;
}