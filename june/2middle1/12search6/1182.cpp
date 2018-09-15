#include <cstdio>

int N,S;
int a[21];
int cnt = 0;

void go(int i, int sum) {
    if(i == N) {
        if(sum == S) {
            cnt ++;
        } 
        return;
    }
    go(i+1, sum+a[i]);
    go(i+1, sum);
}

int main() {
    scanf("%d %d", &N, &S);
    for(int i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }

    go(0, 0);
    if(S==0) {
        cnt -= 1;
    }
    
    printf("%d", cnt);
    return 0;
}