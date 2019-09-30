#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

string A[251];
bool check[251][251];
int w,s,R,C,ts,tw;
int dir[4][2] = {//y,x
            {-1,0},
    {0,-1},         {0,1},
            {1,0}    
};

bool isArea(int y, int x) {
    return y>=0 && y<R && x>=0 && x<C;
}

void go(int y, int x)  {
    
    check[y][x] = true;

    if(A[y][x] == 'v') {
        tw++;
    } else if(A[y][x] == 'o') {
        ts++;
    }

    for(int i=0; i<4; i++) {
        int dy = y + dir[i][0];
        int dx = x + dir[i][1];
        
        if(isArea(dy,dx) && A[dy][dx] != '#' && check[dy][dx] != true) {
            go(dy,dx);
        }
    }
}

int main() {

    cin >> R >> C;
    
    for(int i=0; i<R; i++) {
        cin >> A[i];
    }

    // for(int i=0; i<R; i++) {
    //     for(int j=0; j<C; j++) {
    //         printf("%c", A[i][j]);   //y,x
    //     }printf("\n");
    // }printf("\n");

    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(A[i][j] != '#' && check[i][j] == false) {
                ts = tw = 0;
                //ts는 탐색도중 찾은 양의 숫자이다.
                go(i,j);
                if(ts > tw) {
                    s += ts;
                } else {
                    w += tw;
                }
                // printf("ts: %d, tw: %d start(%d,%d)\n ", ts, tw, i, j);
            }
        }
    }

    cout << s << " " << w << endl;

    return 0;
}