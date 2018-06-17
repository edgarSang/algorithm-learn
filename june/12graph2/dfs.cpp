#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
int N, M, V;
int check[1001] = {0};
vector<int> A[1001];

// void dfsMatrix(int v) {
//     cout << v << " ";
//     check[v] = 1;
//     for(int i=1; i<=N; i++){
//         if(arr[v][i] == 1 && !check[i])
//             dfs(i);
//     }
// }

void dfsList(int v) {
    std::fill_n(check, M, 0);
    stack<int> s;
    s.push(v);

    while(!s.empty()) {
        int top = s.top();
        s.pop();
        
        if(check[top]) continue;
        check[top] = 1;
        cout << top << " ";

        for(int i=0; i<A[top].size(); i++) {
            if(check[A[top][i]] == 0) {
                s.push(A[top][i]);
            }
        }
    }
}

void bfsList(int v) {
    std::fill_n(check, M, 0);
    queue<int> q;
    check[v] = 1;
    q.push(v);

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for(int i=0;i<A[x].size();i++) {
            if(check[A[x][i]] == 0) {
                check[A[x][i]] = 1;
                q.push(A[x][i]);
            }
        }
    }
}

int main() {
    cin >> N >> M >> V;
    
    for(int i=1;i<=M;i++) {
        int u,e;
        cin >> u >> e;
        A[u].push_back(e);
        A[e].push_back(u);
    }
    dfsList(V);
    cout << endl;
    bfsList(V);
    
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


        // stack<int> s;
    // s.push(v);
    
    // while(!s.empty()) {
    //     int top = s.top();
    //     s.pop();
        
    //     if(check[top]) continue;

    //     check[top] = 1;
    //     cout << top << " ";

    //     for(int i=0;i<A[top].size();i++) {
    //         if(!check[A[top][i]]) {
    //             s.push(A[top][i]);
    //         }
    //     }
        
    // }