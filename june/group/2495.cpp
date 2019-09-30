#include <cstdio>
#include <string.h>

using namespace std;

int A[10];

int main() {
    int T = 3;
    
    while(T--) {
        int cur=0, dap=0,cnt=1;
        memset(A,0,sizeof(A));
        scanf("%1d", &cur);
        for(int i=0; i<8; i++) {
            int in;
            scanf("%1d", &in);
            if(cur == in) {
                if(i == 7) {
                    printf("*cnt : %d cur: %d in:%d \n", cnt, cur, in);
                    A[cur] = A[cur] > cnt ? A[cur] : cnt;
                    break;
                }
                cnt ++;
            } else {
                //22121212 같은경우를 대비하여
                printf("cnt : %d cur: %d in:%d \n", cnt, cur, in);
                A[cur] = A[cur] > cnt ? A[cur] : cnt;
                cur = in;
                cnt = 1;
            }
        }

        for(int i=0; i<10; i++) {
            dap = A[i] > dap ? A[i] : dap;
        }
        printf("%d\n", dap);
    }

    return 0;
}