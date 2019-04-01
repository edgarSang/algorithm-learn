#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct node {
    int to;
    int distance;
    node(int to, int distance) : to(to), distance(distance) {};
};

bool check[10001];
vector<node> v[10001];
int endpoint = 0;
int length = 0;
//1.끝을 먼저 찾는다.
//2.끝노드에서 dfs를 해서 다음 끝노드와의 거리중 가장 큰 distance를 찾는다?

void dfs(int n, int total) {
    if(total > length) {
        endpoint = n;
        length = total;
    }

    for(int i=0; i<v[n].size(); i++) {
        int to = v[n][i].to;
        int distance = v[n][i].distance;

        if(check[to] == false) {
            check[to] = true;
            dfs(to, total+distance);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(node(b,c));
        v[b].push_back(node(a,c));
    }
    memset(check, false, sizeof(check));
    dfs(1,0);
    length = 0;
    memset(check, false, sizeof(check));
    dfs(endpoint,0);

    printf("%d\n", length);
    return 0;
}

