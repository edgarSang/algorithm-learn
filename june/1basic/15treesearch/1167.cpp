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
int V;

int bfs(int start) {
    memset(check, 0, sizeof(check));
    memset(distanceArr, 0, sizeof(distanceArr));
    int maxNode = start;
    int max = 0;
    queue<int> q;
    q.push(start);
    // for(int i=1 ;i<=V; i++) {
    //     cout << distanceArr[i] << "\n";
    // }
    //시작에 초기값을 안넣어줬었음
    check[start] = 1;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(int i=0;i<v[front].size();i++) {
            node &n = v[front][i];
            
            if(check[n.to] == 0) {
                check[n.to] = 1;
                distanceArr[n.to] = distanceArr[front] + n.distance;
                //맥스 노드 를 저장하는 로직을 넣어줘야함.
                if(distanceArr[n.to] > max) {
                    max = distanceArr[n.to];
                    maxNode = n.to;
                }
                q.push(n.to); 
            }
        }
    }

    return maxNode;
}

int main () {
    int max = 0;

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
    
    max = bfs(1);

    cout << distanceArr[bfs(max)] << "\n";
    
    return 0;
}