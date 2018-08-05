#include <iostream>
#include <algorithm>

using namespace std;

int map[25][25] = {0,};
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int n;
int houseNumber [323] = {0,};
int cnt = 0;

bool isInside(int y, int x) {
    return ((y >= 0 && y <n) && (x >= 0 && x <n));
}

void dfs(int y, int x, int key) {
    map[y][x] = key;

    for(int i=0; i<4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];

        if(isInside(dy, dx) && map[dy][dx] == 1) {
            dfs(dy, dx, key);
        }
    }
}

void getSolution(){
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(map[i][j] == 1) {
                cnt++;
                dfs(i, j, cnt+1);
            }
        }
    }

    // dfs후 맵에 뭐가 들었는지 확인하기 위함임
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++)
    //         printf("%1d", map[i][j]);
    //     printf("\n");
    // }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(map[i][j] > 1) {
                houseNumber[map[i][j] - 2] ++;
            }
        }
    }
}

int main() {

    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            scanf("%1d", &map[i][j]);
    }

    getSolution();

    cout << cnt << endl;
    sort(houseNumber, houseNumber+cnt);
    for(int i=0;i<cnt;i++){
        cout << houseNumber[i] << endl;
    }

    return 0;
}