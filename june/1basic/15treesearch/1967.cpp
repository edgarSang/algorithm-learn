#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int check[10001] = {0,};
int distanceArr[10001] = {0,};

struct Node {
    int to;
    int distance;
    Node(int to, int distance) : to(to), distance(distance) {}
};
vector<Node> v[10001];

int bfs(int start) {
    memset(check, 0, sizeof(check));
    memset(distanceArr, 0, sizeof(distanceArr));
    int maxNode = start;
    int maxVal = 0;

    queue<int> q;
    q.push(start);
    check[start] = 1;

    while(!q.empty()) {
        int top = q.front();
        q.pop();
        
        for(int i=0; i<v[top].size(); i++) {
            Node & n = v[top][i];
            
            if(check[n.to] == 0) {
                check[n.to] = 1;
                distanceArr[n.to] = distanceArr[top] + n.distance;
                q.push(n.to);
                if(distanceArr[n.to] > maxVal){
                    maxVal = distanceArr[n.to];
                    maxNode = n.to;
                }
            }
        }
    }

    return maxNode;
}

int main() {
    int N;
    cin >> N;

    for(int i=0; i<N-1; i++) {
        int j, c, e;
        cin >> j >> c >> e;
        v[j].push_back(Node(c,e));
        v[c].push_back(Node(j,e));
    }

    int maxNode = bfs(1);

    cout << distanceArr[bfs(maxNode)] << endl;
}