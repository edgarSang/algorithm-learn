//D[n][l] = n 자리 이친수 마지막자리[L]
//D[n][0] = D[n-1][0] + D[n-1][1]
//D[n][1] = D[n-1][0]
#include <iostream>
#define MAX 91

using namespace std;

long long d[MAX][2] = {0};

int main() {
    int n;
    int result = 0;
    cin >> n;

    for (int i = 1; i <= n ; i ++) {
        if (i == 1) {
            d[i][0] = 0;
            d[i][1] = 1;
        }
        else {
            d[i][0] = d[i-1][0] + d[i-1][1];
            d[i][1] = d[i-1][0];
        }
    }

    cout << d[n][0] + d[n][1] << '\n';
    return 0;
}