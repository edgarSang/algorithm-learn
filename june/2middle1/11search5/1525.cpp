#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int A[3][3];
int dir[4][2] = {
        {0,-1},
{-1,0},        {1,0},
        {0,1}
};
int cnt = 0;
bool isArea(int y, int x){
    return ((x>=0 && x<3) && (y>=0 && y<3));
}

bool check() {
    int c = 0;
    for(int i=0; i<3; i++) {
        
        for(int j=0; j<3; j++) {
            c += 1;
            if(c < 9 && A[i][j] != c) {
                return false;
            }  
        }
    }

    return true;
}

void bfs() {
    queue<pair<int,int>> q;
    q.push(pair<int,int>(0,0));
    
    while(!q.empty()) {
        if(check()) {
            printf("%d", cnt);
            return;
        }
        pair<int,int> p;
        int x = p.second = q.front().second;
        int y = p.first = q.front().first;

        for(int i=0; i<4; i++) {
            int dy = y + dir[i][0];
            int dx = x + dir[i][1];
            if(isArea(dy, dx) && A[dy][dx] == 0) {
                q.push(pair<int, int>(dy,dx));
                printf("hrere");
                swap(A[y][x], A[dy][dx]);
                cnt ++;
                for(int i=0; i<3; i++) {
                    for(int j=0; j<3; j++) {
                        printf("%d", A[i][j]);
                    }
                }printf("\n");
                printf("\n");
            }
        }
    }
}

int main() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    bfs();
    return 0;
}