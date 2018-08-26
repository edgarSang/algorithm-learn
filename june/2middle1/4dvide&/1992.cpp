#include <cstdio>

#define MAX 64

int A[MAX][MAX];

bool check(int x, int y, int n) {
    for(int i=x; i<x+n; i++) {
        for(int j=y; j<y+n; j++) {
            if(A[x][y] != A[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void solve(int x, int y, int n) {
    if(check(x, y, n)) {
        printf("%d", A[x][y]);
    } else {
        int m = n/2;
        printf("(");
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                solve(m*i+x, m*j+y, m);
            }
        }
        printf(")");
    }
}
//입력되는 숫자가 띄어쓰기가 안되어있어서 삽질했었음.
int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%1d", &A[i][j]);
        }
    }

    solve(0, 0, n);

    return 0;
}