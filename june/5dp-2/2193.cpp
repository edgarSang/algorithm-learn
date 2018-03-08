#include <iostream>


using namespace std;
long long dp[91][2] = {0};

void binar(int n) {
    dp[1][0] = 0;
    dp[1][1] = 1;

    if(n > 1) {
        if(dp[n-1][0] == 0)
        binar(n-1);
        dp[n][0] = dp[n-1][0] + dp[n-1][1];
        dp[n][1] = dp[n-1][0];
    }
}

int main () {
    int n;
    cin >> n;

    binar(n);
    cout << dp[n][0] + dp[n][1] << '\n';

    return 0;
}