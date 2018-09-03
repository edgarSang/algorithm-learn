#include <iostream>

using namespace std;
//3^7 + 1
#define MAX 2188
// -1, 0, 1 카운트수저장
int cnt[3] = {0,};
int A[MAX][MAX];

bool check(int x, int y, int n) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(A[i][j] != A[x][y]) {
                return false;
            }
        }
    }

    return true;
}

void solve(int x, int y, int n) {
    if(check(x,y,n)) {
        cnt[A[x][y] + 1] += 1;
        return;
    } else {
        int m = (n/3);
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++){
                // printf("x:%d y:%d n:%d \n", i*m+x, j*m+y, m);
                solve(i*m+x, j*m+y, m);
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%1d", &A[i][j]);
        }
    }
    solve(1,1,N);
    // for(int i=1; i<=N; i++) {
    //     for(int j=1; j<=N; j++) {
    //         printf("%d", A[i][j]);
    //     }
    // }
    for(int i=0; i<3; i++){
        printf("%d \n", cnt[i]);
    }

    return 0;
}