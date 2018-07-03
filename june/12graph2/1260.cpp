#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<algorithm>  

#define MAX 1005

using namespace std;

vector<int> A[MAX];
int check[MAX] = {0};
int N,M,V;

void dfs(int start){
    stack<int> s;
    s.push(start);
    check[start] = 1;
    printf("%d ",start);

    while(!s.empty()) {
        int top = s.top();
        s.pop();

        for(int i=0;i<A[top].size();i++) {
            if(check[A[top][i]] == 0) {
                printf("%d ", A[top][i]);
                check[top] = 1;
                s.push(top);
                s.push(A[top][i]);
                break;
            }
        }
    }
}

void bfs(int start) {
    queue<int> q;
    std::fill_n(check, MAX, 0);
    q.push(start);
    check[start] = 1;

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        printf("%d ",front);

        for(int i=0;i<A[front].size();i++){
            if(check[A[front][i]] == 0) {
                check[A[front][i]] = 1;
                q.push(A[front][i]);
            }
        }
    }
}

int main() {
    
    scanf("%d %d %d", &N,&M,&V);

    for(int i=1;i<=M;i++){
        int node,e;
        scanf("%d %d", &node ,&e);
        A[node].push_back(e);
        A[e].push_back(node);
    }
    for (int i = 1; i <= MAX; i++)  
        sort(A[i].begin(), A[i].end());  

    dfs(V);
    printf("\n");
    bfs(V);

    return 0;
}