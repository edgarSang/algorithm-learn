#include <iostream>
#include <vector>
#include <stack>
#define MAX 20001

using namespace std;

int check[MAX] = {-1,};
vector<int> A[MAX];

bool checkBi(int start) {
    stack<int> s;
    s.push(start);
    int toggle = 0;
    check[start] = toggle;
    
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        // cout << endl;
        // cout << top << "|";
        for(int i=0;i<A[top].size();i++){
            // 이 부분에서 top과 비교해서 접근한 모든노드가 나옴
            // cout << A[top][i] << " ";
            if(check[A[top][i]] == check[top]) {
                //인접했는데 이전 노드와 check value가 같다면 false 리턴
                return false;
            } else if(check[A[top][i]] == -1){
                //check는 0,1만 가짐 미방문시 -1 
                toggle = (toggle + 1) % 2;
                // cout << toggle << " ";
                check[A[top][i]] = toggle;
                s.push(top);
                s.push(A[top][i]);
                break;
            }
        }
    }
    // cout << endl;
    // for(int i=1; i<=4; i++) {
    //     cout << check[i] << " ";
    // }
    return true;
}

// TODO:  그래프 1-2 2-3 3-4 는 이분그래프인가?
// 1-2 2-1은 이분그래프인가?
int main() {
    int K,Vcnt,Ecnt;
    bool bi;
    cin >> K;

    for(int j=1;j<=K;j++) {
        cin >> Vcnt >> Ecnt;
        bi = true;
        //initialize vector and check
        for (int i=1; i<=Vcnt; i++) {
            A[i].clear();
            check[i] = -1;
        }
        for(int i=1;i<=Ecnt;i++) {
            int u, v;
            cin >> u >> v;
            A[u].push_back(v);
            A[v].push_back(u);
        }
        for(int i=1; i<=Vcnt;i++){
            if(check[i] == -1) {
                bi = checkBi(i);
                if(bi == false) 
                    break;
            }
        }
        // for (int i=1; i<=Vcnt; i++) {
        //     cout << check[i] << " ";
        // }
        bi == true ? cout << "YES" << endl : cout << "NO" << endl;
    }
}