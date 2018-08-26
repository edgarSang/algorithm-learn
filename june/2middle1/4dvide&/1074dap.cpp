#include <cstdio>

int N,r,c;
int count;

int power2(int k) {
    return 1 << k;
}
//key 포인트 만약 좌표가 해당 분할에 포함되지 않으면 
//그 해당 분할크기만 + 해주고 안으로 비집고 까들어가지않으면됨
void solve(int x, int y, int n) {
    if(x == r && y == c ){
        printf("%d", count);
        return;
    }
    if(r>=x && r<x+n && c>= y && c<y+n){
        int m = n/2;
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                // printf("x:%d y:%d n:%d \n", i*m+x, j*m+y, m);
                solve(i*m+x, j*m+y, m);
            }
        }
    } else {
        count += n*n;
        return;
    }
}

int main() {
    
    scanf("%d %d %d", &N, &r, &c);

    solve(0,0,power2(N));

    return 0;
}