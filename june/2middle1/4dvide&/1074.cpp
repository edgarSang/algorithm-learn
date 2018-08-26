#include <cstdio>
#include <math.h>

int count = 0;
bool getAns = false;
int r,c;
bool search(int x, int y, int n) {
    for(int i=x;i<x+n;i++) {
        for(int j=y;j<y+n;j++) {
            count ++;
            if(r==x && c==y) {
                return true;
            }
        }
    }
    return false;
}

void solve(int x, int y, int n) {
    if(n == 1) {
        getAns = search(x, y, n);
        if(getAns){
            //처음이 0부터 시작이니까
            printf("%d", count-1);
        }
        return;
    } else {
        int m = n/2;
        if(!getAns)
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                // printf("x:%d y:%d n:%d \n", i*m+x, j*m+y, m);
                solve(i*m+x, j*m+y, m);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d %d %d", &N, &r, &c);

    solve(0,0,pow(2, N));

    return 0;
}