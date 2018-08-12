#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct node {
    int to;
    int distance;
    node(int to, int distance) : to(to), distance(distance) {}
}; // 마지막줄은 node는 그냥 생성자임 입력받을시엔 v.push(node(1,2)); 식으로 생성.

vector<node> v[100001];
int check[100001] = {0,};
int distanceArr[100001] = {0,};

int bfs(int start) {
    int maxNode = start;
    queue<int> q;
    q.push(start);
    memset(check, 0, sizeof(int));
    memset(distanceArr, 0, sizeof(int));

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(int i=0;i<v[front].size();i++) {
            node &n = v[front][i];
            
            if(check[n.to] == 0) {
                check[n.to] = 1;
                distanceArr[n.to] = distanceArr[front] + n.distance;
                // maxNode = distanceArr[n.to] > distanceArr[maxNode] ? n.to : maxNode;
                q.push(n.to); 
            }
        }
    }

    return maxNode;
}

int main () {
    int V,max;

    cin >> V;
    for(int i=1; i<=V; i++) {
        int j;
        cin >> j;
        while(true) {
            int t,d;
            cin >> t;
            if(t == -1) {
                break;
            }
            cin >> d;
            v[j].push_back(node(t,d));
        }
    }
 
    bfs(1);
    for(int i=1; i<=V; i++) {
        max = distanceArr[i] > max ? i : max;
    }
    bfs(max);
    max = 0;
    for(int i=1; i<=V; i++) {
        max = distanceArr[i] > max ? distanceArr[i] : max;
    }
    cout << max << "\n";
    
    return 0;
}