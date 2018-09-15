#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

char a[21][21];
int check[91] = {false,};
int R,C;
string his;
stack<int> s;
int cnt = 0;
int ans = 0;
int dir[4][2] = {
        {-1,0},
{0,-1},           {0,1},
        {1,0}
};

bool isArea(int y, int x) {
    return (x>=0 && x<R) && (y>=0 && y<C);
}

void go(int y, int x) {
    int idx = a[y][x];
    check[idx] = true;

    for(int i=0; i<4; i++) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        int dIdx = a[dy][dx];
        if(isArea(dy,dx) && check[dIdx] == false) {
            cnt ++;
            ans = ans > cnt ? ans : cnt;
            go(dy, dx);
        }
    }

    //백트레킹
    check[idx] = false; 
    cnt --;
}

int main() {
    scanf("%d %d", &C, &R);

    for(int i=0; i<C; i++) {
        for(int j=0; j<R; j++) {
            scanf(" %c", &a[i][j]);
        }
    }

    go(0, 0);
    printf("%d", ans+1);
    return 0;
}