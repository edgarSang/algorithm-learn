#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int check[100001] = {0,};
int parent[100001] = {0,};

vector<int> v[100001];

void bfs(int start) {
    int d = 1;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int front = q.front();

        q.pop();
        for(int i=0; i < v[front].size(); i++) {
            if(check[v[front][i]] == 0) {
                check[v[front][i]] = 1;
                parent[v[front][i]] = front;
                q.push(v[front][i]);
            }
        }
    }

}

int main() {
    int N;
    cin >> N;

    for(int i=1;i<=N-1;i++) {
        int c,e;

        cin >> c >> e;

        v[c].push_back(e);
        v[e].push_back(c);
    }
    bfs(1);
    for(int i=2; i<=N; i++) {
        
        cout << parent[i] << "\n";
    }

    return 0;
}