#include <cstdio>
#include <math.h>

int xVal[16] = {0,};

int cntNqueue(int x, int y, int N, int cnt) {
    for(int i=0; i<N; i++) {
        if(xVal[i] == x || abs(y-i) == abs(x-xVal[i])) {
            return cnt;
        }
    }
    if(N-1 == y) {
        return cnt+1;
    }

    for(int i=0; i<N; i++) {
        xVal[y+1] = i;
        cntNqueue(i, y+1, N, cnt);
    }
    return cnt;
}

int main() {
    int N, cnt=0, total=0;
    scanf("%d" , &N);

    for(int i=0; i<N; i++) {
        xVal[0] = i;
        cnt += cntNqueue( 0, i, N, 0); 
    }

    printf("%d\n", cnt);
    return 0;
}