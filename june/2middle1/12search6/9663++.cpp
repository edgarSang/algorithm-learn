#include <cstdio>
#include <math.h>

//Y에 대한 x의 인덱스
int xVal[16] = {0,};

int cntNqueue(int x, int y, int N, int cnt) {
    //y를 다르게 주면서 이전 y값들의 위치에서 공격받는 퀸이있는지 찾는다.
    for(int i=0; i<y; i++) {
        //이전 퀸들의 x값과 행이 같거나 대각선위치에 있으면(기울기가 같으면)
        //2.불가능한조건
        if(xVal[i] == x || abs(y-i) == abs(x-xVal[i])) {
            return cnt;
        }
    }

    //1.종료조건
    if(y == N-1) {
        return cnt+1;
    }

    //다음 탐색조건
    for(int i=0; i<N; i++) {
        xVal[y+1] = i;
        cnt = cntNqueue(i, y+1, N, cnt);
    }
    return cnt;
}

int main() {
    int N, cnt=0, total=0;
    scanf("%d" , &N);

    //x를 다르게 주는조건
    for(int i=0; i<N; i++) {
        xVal[0] = i;
        cnt += cntNqueue( i, 0, N, 0); 
    }

    printf("%d\n", cnt);
    return 0;
}