#include <cstdio>

int a[9][9] = {0,};
//[i] 행에 [j] 값이 있으면 true
bool c[9][10] = {false,};
//[i] 열에 [j] 값이 있으면 true
bool c2[9][10] = {false,};
//[i] 번째 스퀘어에 [j] 값이 있으면 true
bool c3[9][10] = {false,};

//c3 = i번작은 정사각형에 숫자 j가 있으면 true
//x,y는 (x/3)*3 + (y/3) 칸
int square(int x, int y) {
    return (x/3)*3 + (y/3);
}

bool go(int z) {
    if(z == 81) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                printf("%d ", a[i][j]);
            }printf("\n");
        }
        return true;
    }
    int x = z/9;
    int y = z%9;
    if(a[x][y] != 0) {
        return go(z+1);
    } else {
        for(int i=1; i<=9; i++) {
            if(c[x][i] == false && c2[y][i] == false && c3[square(x,y)][i] == false) {
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                a[x][y] = i;
                if(go(z+1)) {
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
    }
    return false;
}

int main() {

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] != 0) {
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i,j)][a[i][j]] = true;
            }
        }
    }
    go(0);

    return 0;
}