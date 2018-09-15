#include <cstdio>

int a[20];

int main(){
    int n, s;
    int ans = 0;
    scanf("%d %d", &n, &s);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    //모든 가능한 부분 집합을 순회함. (공집합빼고)
    for(int i=1; i<(1<<n); i++) {
        int sum = 0;
        for(int k=0; k<n; k++) {
            //k가 i의 부분집합이라면.
            if(i&(1<<k)) {
                sum += a[k];
            }
        }
        if(sum == s) {
            ans += 1;
        }
    }

    printf("%d", ans);
    return 0;
}