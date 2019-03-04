#include <cstdio>
#include <cstring>

using namespace std;

int map[10][10];
int check[10];
int m = 10 * 1000000;
int N;

void go(int start, int cur, int cnt, int sum) {
    if(sum >= m) return;
    if(cnt == N) {
        if(cur==start && m > sum) {
            m = sum;
        }
        return;
    }
    for(int i=0; i<N; i++) {
        if(map[cur][i] == 0) continue;

        if(check[i] == 0) {
            check[i] = 1;
            go(start, i, cnt+1, sum+map[cur][i]);
            check[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    for(int i=0; i<N; i++) {
        memset(check, 0, sizeof(check));
        go(i, i, 0, 0);
    }

    printf("%d\n", m);

    return 0;
}