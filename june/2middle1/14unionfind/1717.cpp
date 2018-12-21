#include <cstdio>
#define MAX 1000000

using namespace std;
int p[MAX] = {0,};

int find(int x) {
    if(x == p[x]) {
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
    int n,m;

    scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++) {
        p[i] = i;
    }
    for(int i=0; i<m; i++) {
        int c,x,y;
        scanf("%d %d %d", &c, &x, &y);

        if(c == 0) {
            unionFind(x,y);
        } else {
            int px = find(x);
            int py = find(y);

            if(px == py) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}