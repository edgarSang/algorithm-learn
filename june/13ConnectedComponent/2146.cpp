#include <iostream>
#include <queue>

using namespace std;

int map[100][100] = {0,};
int check[100][100] = {-1,};
int dir[4][2] = {
        {-1,0},
{0,-1},         {0,1},
        {1,0}
};
int N;
queue<pair<int,int>> q;

int min(int a, int b) {
    return a < b ? a : b;
}

bool isArea(int y, int x){ 
    return ((y>=0 && y<N) && (x>=0 && x<N));
}

int bfs() {
    int minVal = 0;
    while(!q.empty()) {
        pair<int, int> p;
        int qy = p.first = q.front().first;
        int qx = p.second = q.front().second;
        q.pop(); 

        for(int i=0;i<4;i++) {
            int dy = qy + dir[i][0];
            int dx = qx + dir[i][1]; 

            if(isArea(dy,dx) && map[dy][dx] == 0) {
                map[dy][dx] = map[qy][qx];
                check[dy][dx] = check[qy][qx]+1;
                q.push(pair<int, int>(dy, dx));
                // 디버깅용
                // for(int i=0;i<N;i++){
                //     for(int j=0;j<N;j++){
                //         printf("%d", map[i][j]);
                //     }
                // }
            }

            if(isArea(dy,dx) && map[dy][dx] > 0 && map[dy][dx] != map[qy][qx]) {
                minVal = minVal == 0 ? check[dy][dx]+check[qy][qx] : min(minVal, check[dy][dx]+check[qy][qx]); 
            }
        }
    }

    return  minVal;
}

void dfs(int y, int x, int key) {
    map[y][x] = key;
    check[y][x] = 0;
    q.push(pair<int, int>(y, x));
    
    for(int i=0; i<4;i++) {
        int dy = y - dir[i][0];
        int dx = x - dir[i][1];

        if(isArea(dy,dx) && map[dy][dx] == 1) {
            dfs(dy, dx, key);
        }
    }
}

void getDfsLocation() {
    int cnt = 1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j] == 1) {
                cnt++;
                dfs(i,j,cnt);
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

    int rtn = bfs();

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n");
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         printf("%d ", check[i][j]);
    //     }
    //     printf("\n");
    // }
    

    cout << rtn << endl;
    return 0;
}