#include <iostream>
#include <vector>
#include <stack>
#define MAX 20001

using namespace std;

int check[MAX] = {0,};
vector<int> A[MAX];

bool checkBi(int s) {
    if(check[s] == 2) {
        if(!A[s].size()) {
            return true;
        } else {
            return false;
        }
    }
    check[s] = 1;
    
    for(int i=0;i<A[s].size();i++){
        if(check[A[s][i]] == 1) {
            return false;
        } else {
            check[A[s][i]] = 2;
        }
    }
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
        for(int i=1;i<=Ecnt;i++) {
            int u, v;
            cin >> u >> v;
            A[u].push_back(v);            
        }
        for(int i=1;i<=Vcnt;i++) {
            if(checkBi(i) == false) {
                bi = false;
                break;
            }
        }
        fill_n(check, MAX, 0);
        bi == true ? cout << "YES" << endl : cout << "NO" << endl;
    }
}