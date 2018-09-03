#include <iostream>

#define MAX 201
#define mod 1000000000

using namespace std;

long long d[MAX][MAX] = {0};

int main () {
    int k,n;

    cin >> n >> k;

    for(int i=0; i<=n; i++){
        d[1][i] = 1;
    }

    for(int i=1; i<=k; i++) 
        for(int j=0; j<=n; j++)
            for(int c=0; c<=j; c++) {
                d[i][j] += d[i-1][j-c];
                d[i][j] %= mod;
            }

    cout  << d[k][n] << '\n';
}