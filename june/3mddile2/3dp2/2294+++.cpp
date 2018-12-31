//덧셈을 미니멈으로만 바꿔라
#include <iostream>
#include <cstring>

int a[101];
int d[10001];

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    memset(d,-1,sizeof(d));

    d[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=1; j<=k; j++) {
            //d[j-a[i]] != -1 의 의미가 무엇인지 잘생각해보기
            if(j>=a[i] && d[j-a[i]] != -1) {
                //아직 초기화가 안됐으면 초기화.
                if(d[j] == -1) {
                    d[j] = d[j-a[i]] + 1;
                } else {
                    d[j] = d[j] < d[j-a[i]] + 1 ? d[j] : d[j-a[i]] + 1;
                }
            }
        }
    }    

    printf("%d", d[k]);

    return 0;
}