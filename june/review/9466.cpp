#include <cstdio>
#include <cstring>

using namespace std;

int t,n,cnt;
int a[100001];
bool check[100001], isFinishied[100001];

void dfs(int cur) {
    check[cur] = true;

    if(check[a[cur]] == false) {
        dfs(a[cur]);
    } else if(isFinishied[a[cur]] == false){
        for(int i=a[cur]; i != cur; i = a[i]) {
            // printf("a[i]:%d cur:%d\n", a[i], i);
            cnt ++;
        }
        cnt++;
    }

    isFinishied[cur] = true;
}

int main() {
    scanf("%d", &t);

    while(t--) {
        scanf("%d" , &n);
        memset(a, 0 ,sizeof(a));
        memset(check, false ,sizeof(check));
        memset(isFinishied, false ,sizeof(isFinishied));
        cnt = 0;

        
        for(int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }

        for(int i=1; i<=n; i++) {
            if(check[i] == false) {
                dfs(i);
            }
        }

        printf("%d\n", n-cnt);
    }

    return 0;
}