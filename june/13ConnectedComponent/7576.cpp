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
queue<pair<int, int>> q;

int bfs() {
    int distance = 1;
    int maxCnt = 0;

    pair<int,int> p;

    while(!q.empty()) {
        int qy = p.first = q.front().first;
        int qx = p.second = q.front().second;
        distance++;
        q.pop();

        for(int i=0;i<4;i++) {
            int dy = qy + dir[i][0];
            int dx = qx + dir[i][1];
            
            // 1일때마다 bfs를 새로 실행하지않고 한번에 큐에 넣고 bfs를 시작하면
            // || (map[dy][dx] > map[qy][qx]) 
            // 위 조건이 필요가없다. 왜냐하면 시작점에서 번갈아가면서 bfs 가 돌며, 번갈아가며
            // 채우면서 결국에는 접점에서 만나기때문이다.
            if(isArea(dy,dx) && !(map[dy][dx] == -1) ) {
                if(map[dy][dx] == 0) {
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
                q.push(pair<int, int>(i, j));
            }
        }
    }

    maxCnt = bfs();

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
    maxCnt == 0 ? printf("%d", 0) : printf("%d", maxCnt-1);
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