#include <iostream>

using namespace std;

int a[101][101];
long long d[101][101];

int main() {
    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    d[1][1] = 1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            //a[i][k]+k == j
            for(int k=0; k<j; k++) {
                if(k+a[i][k] == j) {
                    d[i][j] += d[i][k];
                }
            }
            //a[k][j]+k == i
            for(int k=0; k<i; k++) {
                if(k+a[k][j] == i) {
                    d[i][j] += d[k][j];
                }
            }
        }
    }

    printf("%lld", d[N][N]);
    return 0;
}