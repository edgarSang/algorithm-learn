#include <iostream>
#define MAX 101

using namespace std;

long long d[MAX] = {0};

int main() {
    int T, n;
    cin >> T;

    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    d[5] = 2;

    while(T--){
        cin >> n;
        for(int i=6; i<=n; i++){
            if(d[i] == 0) {
                d[i] = d[i-1] + d[i-5];
            }
        }
        cout << d[n] << '\n';
    }

    return 0;
}