#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> A[1001];
int check[1001];
int CC = 0;
void dfs(int v) {
    check[v] = 1;
    
    for(int i=0; i<A[v].size(); i++){
        if(check[A[v][i]] == 0) {
            dfs(A[v][i]);
        }
    }
}

int main() {
    int N,M;
    cin >> N >> M;
    std::fill_n(check, N, 0);

    for(int i=0;i<M;i++) {
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
    for(int i=1; i<=N; i++) {
        if(check[i] == 0) {
            dfs(i);
            CC++;
        }
    }
    cout << CC << endl;
}