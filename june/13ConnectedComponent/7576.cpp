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
    //일단 시작성공
    map[y][x] = distance;
    queue<pair<int, int>> q;
    q.push(pair<int, int>(y, x));

    while(!q.empty()) {
        pair<int,int> p;
        int qy = p.first = q.front().first;
        int qx = p.second = q.front().second;
        distance++;
        q.pop();

        for(int i=0;i<4;i++) {
            int dy = qy + dir[i][0];
            int dx = qx - dir[i][1];
            
            if(isArea(dy,dx) && !(map[dy][dx] == -1)) {
                if(map[dy][dx] == 0 || (map[dy][dx] > map[qy][qx])) {
                    map[dy][dx] = min(map[qy][qx]+1, distance);
                    q.push(pair<int,int>(dy, dx));
                }
            }

        }
    }

    return 0;
}

int getSolution() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 1) {
                bfs(i, j);
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

}

int main() {
    scanf("%d %d", &M, &N);

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++){
            scanf("%1d", &map[i][j]);
        }
    }

    getSolution();

    return 0;
}