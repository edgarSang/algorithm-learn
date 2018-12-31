#include <iostream>
#include <cstring>

using namespace std;
int a[2001];
int d[2001][2001];

bool check(int len) {
    for(int i=0; i<len/2; i++) {
        if(a[i] != a[len-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    scanf("%d", &N);
    memset(d, -1, sizeof(d));
    for(int i=1; i<=N; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        int S,E;
        scanf("%d %d", &S,&E);
        int len = E-S;
        if(len == 0) {
            printf("1\n");
        } else if(len == 1) {
            if(d[S][E] != -1) {
                printf("%d\n", d[S][E]);
            } else {
                if(a[S]==a[E]) {
                    d[S][E] = 1;
                    printf("1\n");
                } else {
                    d[S][E] = 0;
                    printf("0\n");
                }
            }
        } else {
            if(a[S] == a[E]) {
                if(d[S+1][E-1]!=-1) {
                    printf("%d", d[S+1][E-1]);
                } else {
                    int tlen = ((E-1)-(S+1))/2;
                    if(check(tlen)) {
                        d[S+1][E-1] = 1;
                        printf("1\n");
                    } else {
                        d[S+1][E-1] = 0;
                        printf("0\n");                        
                    }
                }
            } else {
                d[S][E] = 0;
                printf("0\n");
            }
        }
    }
}