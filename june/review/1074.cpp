#include <cstdio>

using namespace std;

int N, r, c, cnt;

int power2(int n) {
    return 1 << n;
}

void go(int n, int x, int y) {
    
    if(x==r && y==c) {
        printF("%d", cnt);
    } else if(r >= x && r <= x+n && c >= y&& c <= y+n) {
        //분할된 N*N 사각형의 길이구나!
        int m = n/2;    
        for(int i=0; i<2; i++) {
            for(int j=0; j<2; j++) {
                solve(m, i*x+m, j*y+m);
            }
        }
    } else {
        count += n*n;
    }
}

int main() {
    
    scanf("%d %d %d", &N, &r, &c);
    
    go(power2(N), 0, 0);

    return 0;
}