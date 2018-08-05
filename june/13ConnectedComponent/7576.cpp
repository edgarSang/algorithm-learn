//입력에서 알아서 띄어쓰기가 들어오면 %1d 쓰지말것 (-1 이 1로인식)
#include <iostream>
#include <queue>

using namespace std;

int map[1000][1000] = {0,};
int dir[4][2] = {
            {-1,0},
    {0,-1},        {0,1},
            {1,0}
};
int M,N; //M = x , N = y;

int min(int a, int b) {
    return a < b ? a : b;
}

bool isArea(int y, int x){
    return ((x>=0 && x<M) && (y>=0 && y<N));
}

int bfs(int y, int x) {
    int distance = 2;
    int maxCnt = 0;
    //일단 시작성공
    map[y][x] = distance;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(y, x));
    pair<int,int> p;

    while(!q.empty()) {
        int qy = p.first = q.front().first;
        int qx = p.second = q.front().second;
        distance++;
        q.pop();

        for(int i=0;i<4;i++) {
            int dy = qy + dir[i][0];
            int dx = qx + dir[i][1];
            
            if(isArea(dy,dx)) {
                if(map[dy][dx] == 0 || !(map[dy][dx] == -1) && (map[dy][dx] > map[qy][qx])) {
                    maxCnt = map[dy][dx] = min(map[qy][qx]+1, distance);
                    q.push(pair<int,int>(dy, dx));
                }
            }

        }
    }

    return maxCnt;
}

void getSolution() {
    int maxCnt = 0;
    int val = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 1) {
                val = bfs(i, j);
                maxCnt = maxCnt == 0 ? val : min(val, maxCnt);
            }
        }
    }

    // 디버깅용
    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<M;j++){
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0) {
                printf("%d",-1);
                return;
            }
        }
    }
    // 시작점이 원래 0 일로쳐야하는데 구분을 위해 2부터시작해서
    maxCnt == 0 ? printf("%d", 0) : printf("%d", maxCnt-2);
}

int main() {
    scanf("%d %d", &M, &N);

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++){
            scanf("%d", &map[i][j]);
        }
    }

    getSolution();

    return 0;
}