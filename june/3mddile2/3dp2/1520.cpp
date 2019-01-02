#include <iostream>
#include <cstring>

using namespace std;

int N,M;

int a[501][501];
int d[501][501];

int dir[4][2] = {
            {-1, 0},
    {0, -1},        {0, 1},
            {1, 0},
};


// bool isArea(int y, int x) {
//     return (y>0 && y<=N) && (x>0 &&  x<=M);
// }

int go(int y, int x) {
    if(y==N && x==M) return 1;
    if(d[y][x] >= 0) return d[y][x];
    d[y][x] = 0;
    for(int i=0; i<4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];

        if(dy>0 && dy<=N && dx>0 &&  dx<=M) {
            if(a[y][x] > a[dy][dx]) {
                d[y][x] += go(dy, dx);
            }
        }
    }

    return d[y][x];
}

int main() {
    scanf("%d %d", &N, &M);
    memset(d,-1,sizeof(d));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    go(1, 1);
    printf("%d \n", d[1][1]);
    
    return 0;
}
