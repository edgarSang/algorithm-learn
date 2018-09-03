#include <cstdio>

using namespace std;

void solve(int n) {
    int cnt = 0;

    for(int c=0; c*3<=n; c++) {
        for(int j=0; j*2<=n; j++) {
            for(int i=0; i<=n; i++) {    
                if(i+j+c == n) {
                    if(j != 0 || c != 0) {
                        cnt = 
                    } else if (j != 0 && c != 0){
                        
                    }
                }
            }
        }
    }
    printf("%d\n", cnt);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int in;
        scanf("%d", &in);
        solve(in);
    }

    return 0;
}