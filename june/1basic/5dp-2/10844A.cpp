#include <iostream>
#define MAX 101
#define MOD 1000000000

using namespace std;
long long d[MAX][10] = {0};

int stair (int n) {    
    if(n > 1) {
        if(d[n][0] == 0) stair(n-1);
        for (int i = 0; i < 10; i++) {
            if(i == 0) d[n][i] = d[n-1][i+1] % MOD;
            else if(i == 9) d[n][i] = d[n-1][i-1] % MOD;
            else{
                d[n][i] = (d[n-1][i-1] + d[n-1][i+1]) % MOD;
            } 
        }
    }
}

int main () {
    int N = 0;
    long long result = 0;
    
    cin >> N;
    // row 1 init
    for(int i = 1; i < 10; i++) {
        d[1][i] = 1;
    }

    stair(N);
    for(int i=0; i < 10; i++) {
        result = (result + d[N][i]) % MOD ;
    }

    cout << result << endl;
}