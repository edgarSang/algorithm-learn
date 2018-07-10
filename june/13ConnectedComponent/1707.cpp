#include <iostream>

#define MAX 20001

int check[MAX][2] = {0,};
using namespace std;

int main() {
    int K,V,E;
    bool bi;
    cin >> K;

    for(int j=1;j<=K;j++) {
        cin >> V >> E;
        bi = true;
        for(int i=1;i<=E; i++) {
            int u,v;
            cin >> u >> v;
            check[u] = 1;
            check[v] = 2;
        }


        bi == true ? cout << "YES" << endl : cout << "NO" << endl;
    }
}