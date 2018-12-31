#include <iostream>
#include <cstring>

using namespace std;

int a[2001];
int d[2001][2001];

int check(int i, int j) {
    if(i == j) {
        return 1;
    } 
    if(j-i == 1) {
        if(a[i] == a[i+1]) return 1;
        else return 0;
    }
    else {
        if(d[i][j] >= 0) return d[i][j];
        if(a[i] != a[j]) return 0;
        else return d[i][j] = check(i+1,j-1);
    }
}

int main() {
    int N,M;
    memset(d, -1, sizeof(d));
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &a[i]);
    }    

    scanf("%d", &M);
    for(int i=1; i<=M; i++) {
        int S,E;
        scanf("%d %d", &S,&E);
        printf("%d\n", check(S,E));
    }

    return 0;
}