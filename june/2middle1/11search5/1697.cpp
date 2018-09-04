#include <cstdio>
#include <queue>

using namespace std;

bool check[200001] = {false,};
int dis[200001] = {0,};

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    dis[start] = 0;
    check[start] = true;

    while(!q.empty()) {
        int f = q.front();
        q.pop();
        if(f == end) {
            printf("%d", dis[end]);
            return;
        }

        if(f-1 >= 0 && check[f-1] == false) {
            check[f-1] = true;
            dis[f-1] = dis[f] + 1;
            q.push(f-1);
        }

        if(f+1 <= 100000 && check[f+1] == false) {
            check[f+1] = true;
            dis[f+1] = dis[f] + 1;
            q.push(f+1);
        }

        if(f*2 <= 200000 && check[f*2] == false) {
            check[f*2] = true;
            dis[f*2] = dis[f] + 1;
            q.push(f*2);
        }
    }
}

int main() {
    int N,K;
    scanf("%d %d", &N, &K);
    bfs(N, K);

    return 0;
}