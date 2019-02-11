//이문제 에서 가장중요한건 연속된 파일을 합친다는것이다.
//1.연속된 파일만 합칠 수 있다, 파일은 2개의 연속된 파일을 합치는것이다
//N^3 다이나믹을 생각해볼수있다
//D[I][J] = i~j 번을 합치는 최소비용, k번째에서 나눠줘야한다.
//D[i][j] = D[i][k] + D[k+1][j] + (A[i]~[j]의 합); i<= k <= j-1
//
#include <iostream>
#include <cstring>

using namespace std;

int a[501];
int s[501];
int d[501][501];

int go(int i,int j) {
    if(i==j) {
        return 0;
    }
    if(d[i][j] != -1) {
        return d[i][j];
    }
    int &ans = d[i][j];
    for(int k=i; k<=j-1; k++) {
        //s[j] - s[i-1] 이 의미하는바는?
        int temp = go(i, k) + go(k+1, j) + s[j] - s[i-1];
        if(ans == -1 || ans > temp) {
            ans = temp;
        }
    }
    return ans;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        memset(d,-1,sizeof(d));
        memset(s,0,sizeof(s));
        int K;
        scanf("%d", &K);
        for(int j=1; j<=K; j++) {
            scanf("%d", &a[j]);
            //s[j] 는 j까지의 합
            s[j] = s[j-1] + a[j];
        }
        
        printf("%d\n", go(1, K));
    }

    return 0;
}