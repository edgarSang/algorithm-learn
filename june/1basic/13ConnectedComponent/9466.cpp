#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> v;
int check[100001] = {0,}; //check[n] 에는 n의 cnt가저장
int step[100001] = {0,}; // step[n] 에는 n의 start 가저장

//(n은 탐색 노드, cnt는 싸이클 주기의 노드수, ss싸이클 주기의 시작값)
int dfs(int n, int cnt, int startStep) {
    if(check[n]) {
        if(step[n] == startStep) {
            return cnt - check[n];
        }
        return 0;
    }
    check[n] = cnt;
    step[n] = startStep;

    return dfs(v[n], cnt+1, startStep);
}

int main() {
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++) {
        // 인덱스가 헷갈릴것같아서 v[0] 채워줌 나중에 사이즈에서뺌
        v.push_back(0);
        int n,e;
        int sum = 0;
        cin >> n;
        //숫자 입력받고
        for(int j=1; j<=n; j++) {
            cin >> e;
            v.push_back(e);
        }
        //search가 0인게 없도록 순회함.
        for(int j=1; j<=n; j++) {
            if(step[j] == 0) {
                sum += dfs(j, 1, j);
            }
        }
        
        cout << v.size()-sum-1 << endl;

        v.clear();
        for (int j=1; j<=n; j++) {
            check[j] = 0;
            step[j] = 0;
        }
    }


    return 0;
}