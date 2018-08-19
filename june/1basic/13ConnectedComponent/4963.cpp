#include <iostream>

using namespace std;

int w,h; //w = x , h = y
int map[50][50];

int dir[8][2] = {
                 {-1,-1},{-1,0},{-1,1},
                 {0,-1},        {0,1},
                 {1,-1}, {1,0} ,{1,1},
                };

bool isArea(int y, int x) {
    return ((y>=0 && y<h) && (x>=0 &&x<w));
}

void dfs(int y, int x) {
    //이미 방문했으면2 , key를 궂이 따로둘필요는없다.
    map[y][x] = 2;

    for(int i=0; i<8; i++) {
        int dx = x - dir[i][0]; 
        int dy = y - dir[i][1];

        if(isArea(dy,dx) && map[dy][dx] == 1) {
            dfs(dy,dx);
        }
    }
}

int getIsland() {
    int cnt = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j] == 1) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    return cnt;
}

int main() {

    while(true) {
        scanf("%d %d", &w, &h);
        if(w == 0 && h == 0){
            break;
        }

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                scanf("%1d", &map[i][j]);
            }
        }

        int count = getIsland();

        cout << count << endl;

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                map[i][j] = 0;
            }
        }
    }

    return 0;
}