#include <cstdio>
#define max 20

long long f[max+1] = {1,};
bool check[max+1] = {false,};

void solve1(int n) {
    long long seq = 0;
    int A[n] = {0,};
    scanf("%lld", &seq);
    for(int i=0; i<n; i++) {
        for(int j=1; j<=n; j++) {
            if(check[j] == true) {
                continue;
            }
            if(f[n-i-1] >= seq) {
                A[i] = j;
                check[j] = true;
                break;
            }
            seq -= f[n-i-1];
        }
    }

    for(int i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
}

void solve2(int n) {
    int A[n] = {0,};
    long long seq = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }

    for(int i=0; i<n; i++) {
        for(int j=1; j<=n; j++) {
            if(check[j] == true) {
                continue;
            }
            if(check[j] == false && A[i] == j) {
                check[j] = true;
                break;
            }
            seq += f[n-i-1];
        }
    }
    // +1을 해주는 이유는 마지막 1개일땐 고려 안하므로.
    printf("%lld", seq+1);
}

int main() {
    int n,exnum; 
    scanf("%d %d", &n, &exnum);
    for(int i=1; i<=n; i++){
        f[i] = f[i-1] * i;
    }

    if(exnum == 1) {
        solve1(n);
    } else {
        solve2(n);
    }

    return 0;
}