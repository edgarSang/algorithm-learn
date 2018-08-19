#include <iostream>

#define MAX 1001

using namespace std;
int d[MAX][10] = {0};

int upstair(int n) {
    for(int j=0; j<10; j++){
        d[1][j] = 1;
    }
    if(n > 1){
        for(int i=2; i<=n; i++){
            for(int j=0; j<10; j++) {
                for(int c=0; c<=j; c++) {
                    d[i][j] = (d[i][j] + d[i-1][c]) % 10007;
                }
            }
        }
    }
}

int main() {
    int n,result = 0;

    cin >> n;
    
    upstair(n);

    for(int j=0; j<10; j++){
        result = (result + d[n][j]) % 10007;
    }
    cout << result << '\n';
    
    return 0;
}