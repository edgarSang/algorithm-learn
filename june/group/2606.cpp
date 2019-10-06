#include <cstdio>
#include <vector>

using namespace std;
vector<int> v[101];
int N,T,cnt=0;
bool check[101];

void dfs(int cur) {
    check[cur] = true;
    cnt++;

    for(int i=0; i<v[cur].size(); i++) {
        int next = v[cur][i];
        if(check[next] == false) {
            dfs(next);
        }
    }
}

int main() {    
    scanf("%d", &N);
    
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        int in1, in2;
        scanf("%d %d", &in1, &in2);
        v[in1].push_back(in2);
        v[in2].push_back(in1);
    }
    dfs(1);

    printf("%d\n", cnt-1);
    
    return 0;
}