#include <iostream>
#define MAX 101
using namespace std;

int p[MAX] = {0,};

int find(int x) {
    if(p[x] == x) {
        return x;
    } else {
        return p[x] = find(p[x]);
    }
}

void unionFind(int x, int y) {
    int px = find(x);
    int py = find(y);

    p[py] = px;
}

int main() {
    int N,T,cnt = 0;
    scanf("%d %d", &N, &T);
    for(int i=0; i<=N; i++) {
        p[i] = i;
    }

    for(int i=1; i<=T; i++) {
        int x,y;
        scanf("%d %d", &x, &y);
        unionFind(x, y);
    }

    for(int i=2; i<=N; i++) {
        if(find(p[i]) == find(p[1])) cnt++;
    }

    printf("%d", cnt);
    
    return 0;
}