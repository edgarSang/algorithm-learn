#include <cstdio>
#define MAX 501

int d[MAX];
int m[MAX][MAX];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; n++) {
        scanf("%d %d", &d[i], &d[i+1]);
    }

    for(int len=2; len<=n-1; len++) {
        for(int i=1; i<=n-len+1; i++) {
            int j = i+len-1;
            m[i][j] = 2147483647;
            for(int k=i; k<j; k++) {
                int min = m[i][k] + m[k][j] + d[i-1] * d[k] * d[j];
                if(m[i][j] > min) {
                    m[i][j] = min;
                }
            }
        }
    }

    printf("%d", m[1][n]);

    return 0;
}