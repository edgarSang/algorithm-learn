#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> A[10];
int check[10] = {0};

void dfs(int v) {
    stack<int> s;
    s.push(v);
    
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        cout << top << " ";
        check[top] = 1;

        for(int i=0; i<A[top].size(); i++) {
            if(check[A[top][i]] == 0)
                s.push(A[top][i]);
        } 
    }
};

void bfs(int v) {
    queue<int> q;
    q.push(v);

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        cout << front << " ";
        for(int i=0; i<A[front].size(); i++) {
            if(check[A[front][i]] == 0) {
                check[A[front][i]] = 1;
                q.push(A[front][i]);
            }
        }
    }
}

int main() {
    int n, v, m;
    cin >> n >> m >> v;

    for(int i=1; i<=m; i++) {
        int u, s;
        cin >> u >> s;
        A[u].push_back(s);
    }

    bfs(v);
}