#include <iostream>
#include <vector>

using namespace std;
int N, M, V;
int A[10][10] = {0,};
int check[10] = {0,};

void dfs(int v) {
    check[v] = 1;
    cout << v << " ";
    for(int i=1; i<=N; i++) {
        if(A[v][i] == 1 && !check[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> N >> M >> V;
    
    for(int i=1; i<=M; i++) {
        int u, e;
        cin >> u >> e;
        A[u][e] = A[e][u] = 1;
    }
    dfs(V);

    return 0;
}

    // vector<int> A[10];

    // for(int i=0; i<=N; i++){
    //     int u, e;
    //     scanf("%d %d", &u, &e);
    //     A[u].push_back(e); 
    //     A[e].push_back(u);
    // }

    // int A[N][N];
    //인접 행렬로 입력받기.
    // int A[N+1][N+1] = {0,};
    // for(int i=1; i<=M; i++) {
    //     cin >> u >> e;
    //     A[u][e] = A[e][u] = 1;
    // } 