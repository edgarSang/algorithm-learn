#include <iostream>
#include <queue>

using namespace std;

int map[100][100] = {0,};
int check[100][100] = {0,};
int dir[4][2] = {
        {-1,0},
{0,-1},         {0,1},
        {1,0}
};
int N;
queue<pair<int,int>> q;

bool isArea(int y, int x){ 
    return ((y>=0 && y<N) && (x>=0 && x<N));
}

int min(int a, int b) {
    return a<b? a:b;
}

int bfs() {
    int minVal = 0;
    while(!q.empty()) {
        pair<int, int> p;
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop(); 

        for(int i=0;i<4;i++) {
            int dy = qy + dir[i][0];
            int dx = qx + dir[i][1]; 

            // 다른섬임을 어떻게 구분할까?
            // if(map[dy][dx] == -1) {
            //     return map[qy][qx];
            // }
            if(isArea(dy,dx) && map[dy][dx] == 0) {
                // bfs 시에 0릏 어떻게 최단거리로 초기화시켜야할까?
                map[dy][dx] = map[qy][qx]+1;
                q.push(pair<int, int>(dy, dx));
            }
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                printf("%d ", map[i][j]);
            }printf("\n");
        }printf("\n");
    }
}

void dfs(int y, int x, int cnt) {

    for(int i=0; i<4;i++) {
        int dy = y - dir[i][0];
        int dx = x - dir[i][1];

        if(isArea(dy,dx) && check[dy][dx] == 0 && map[dy][dx] == 1) {
            check[dy][dx] = 1;
            //맨처음 찾은 섬을 무슨수로 초기화 시킬까?
            if(cnt == 1) {
                q.push(pair<int, int> (dy, dx));
            } else {
                map[dy][dx] = -1;
            }
            
            dfs(dy, dx);
        }
    }
}

void getDfsLocation() {
    int cnt = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j] == 1) {
                map[i][j] == -1;
                dfs(i,j,cnt+1);
            }
        }
    }
}


int main(){
    scanf("%d", &N);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &map[i][j]);
        }
    }

    getDfsLocation();

    int cnt = bfs();

    printf("%d", cnt);

    return 0;
}