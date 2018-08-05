#include <iostream>
#include <queue>

using namespace std;

int n,m; // n=x, m=y
int map[100][100];

int dir[4][2] = {
                            {-1,0},
                    {0,-1},         {0,1},
                            {1,0}
                };

int min(int a, int b) {
    return a < b ? a : b;
}

bool isArea(int y, int x) {
    return ((y>=0 && y < m) && (x>=0 && x<n));
}

void bfs(int y, int x, int distance) {
    map[y][x] = distance;
    queue<pair<int,int>> q;
    q.push(pair<int, int>(y, x));

    while(!q.empty()) {
        distance = distance + 1;
        pair<int, int> p;
        int qy = p.first = q.front().first;
        int qx = p.second = q.front().second;
        
        q.pop();
        for(int i=0;i<4;i++) {
            int dy = qy + dir[i][0];
            int dx = qx + dir[i][1];
            
            if(isArea(dy, dx) && map[dy][dx] == 1) {
                // map[dy][dx] = map[dy][dx] > 1 ? min(map[dy][dx], distance) : distance;
                map[dy][dx] = min(map[qy][qx]+1, distance);
                q.push(pair<int, int>(dy,dx));
            }
        }
    }

}

int main() {

    //헷갈려서 문제가 제공하는 n 하고 m 하고 바뀜
    scanf("%d %d", &m, &n);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    
    // 기존 시작 거리에서 1만큼을 더더함 distance 계산을위해
    bfs(0, 0, 1 + 1);

    // 디버깅용 출력
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d", map[i][j]);
    //     }printf("\n");
    // }

    cout << map[m-1][n-1] - 1 << endl;

    return 0;
}


// 4 6
// 110110
// 110110
// 111111
// 111101
// --------------
// 23011120
// 54010130
// 67891415
// 13121110016
// 15


// 2번째 예제인데

// 22
// 2- 이런식으로 시작해야함.