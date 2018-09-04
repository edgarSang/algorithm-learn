#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int A[100000][2];
bool check[100000] = {false,};
int dis[100000] = {99999,};

void bfs(int start, int end) {
    queue<int> q;
    q.push(start);
    dis[start] = 0;
    check[start] = true;

    while(!q.empty()) {
        int top = q.front();
        q.pop();
        
        for(int i=0; i<2; i++) {
            if(check[A[top][i]] == false) {
                check[A[top][i]] = true;
                q.push(A[top][i]);
                dis[A[top][i]] = dis[top]+1 < dis[A[top][i]] ? dis[top] + 1 : dis[A[top][i]]; 
                if(A[top][i] == end) {
                    printf("%d", dis[end]);
                    return;
                }
            }
        }
    }
}

int main() {
    int N,K;
    scanf("%d %d", &N, &K);
    if(N <= K) {
        for(int i=N; i<K; i++){
            A[i][0] = i+1;
            A[i][1] = i*2;
        }
    }

    bfs(N, K);

    return 0;
}