#include <iostream>
#include <vector>
#include <stack>
#define MAX 20001

int check[MAX] = {0,};
vector<int> v[MAX];
using namespace std;

bool checkBi(int s) {
    check[s] = 1;

    for(int i=0;i<=v[s].size();i++){
        if(check[v[s][i]] == 1)
            return false;
    }
    return true;
}

int main() {
    int K,Vcnt,Ecnt;
    bool bi;
    cin >> K;

    for(int j=1;j<=K;j++) {
        cin >> Vcnt >> Ecnt;
        bi = true;
        for(int i=1;i<=Ecnt; i++) {
            int u, v;
            cin >> u >> v;
            v[u].push_back(v);            
        }

        bi == true ? cout << "YES" << endl : cout << "NO" << endl;
    }
}