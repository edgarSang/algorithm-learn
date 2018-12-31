#include <iostream>
#include <queue>

using namespace std;

int N,M;
int dir[3][2] = {
                {1,0},
        {0,1},  {1,1}
};
int map[1001][1001];
int check[1001][1001];

bool isArea(int y, int x) {
    return (y >= 1 && y <= N) && (x >= 1 && x <= M);
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    int result = 0;
    
    while(!q.empty()) {
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();
        result += map[qy][qx];
        for(int i=0; i<3; i++) {
            int dy = qy - dir[i][1];
            int dx = qx - dir[i][0];

            if(isArea(dy,dx) && check[dy][dx] == 0) {
                check[dy][dx] = 1;
                q.push({dy,dx});
            }
        }
    }
}

int main() {   
    scanf("%d %d", &N, &M);
    for(int i=1; i<N; i++) {
        for(int j=1; j<M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    bfs(1, 1);
}