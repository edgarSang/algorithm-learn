#include <cstdio>
#include <math.h>
//X값에 대한 Y의 포지션 배열
int yVal[16];
int cnt;
int T;

bool isPromising(int x) {
    
    //현재 x보다 작은것들중에 row가 같거나 대각선상의 ㅇㅆ는게 있는가?
    for(int i=0; i<x; i++) {
        if(yVal[i] == yVal[x]) {
            return false;
        } else if (abs(yVal[x]-yVal[i]) == abs(x-i)) {
            //(x의증가량과 y의 증가량이 같다)
            return false;
        }
    }

    return true;
}

void dfs(int x) {

    //x가 체스판의 끝에 도착했을때
    if(x == T) {
        cnt++;
        return ;
    } else {
    //다음 x의 y위치를 동적으로 변경.
        for(int i=0; i<T; i++) {
            //다음x에 대한 y의 값은 i
            yVal[x] = i;
            if(isPromising(x)) {
                dfs(x+1);
            }
        } 
    }
}

int main() {
    scanf("%d", &T);

    dfs(0);
    

    printf("%d\n", cnt);
    return 0;
}