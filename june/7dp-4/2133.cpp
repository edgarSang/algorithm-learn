#include <iostream>
#define MAX 31

using namespace std;

int d[MAX] = {0};

int main() {
    int n;
    cin >> n;

    //왜 d[0] 은 1인것인?
    d[0] = 1;
    d[2] = 3;
    for(int i=3; i<=n; i++) {
        if(i%2 != 0) continue;
        d[i] = 3 * d[i-2];
        for(int j=4; 0<=i-j; j++) {
            if(j%2 != 0) continue;
            d[i] += 2 * d[i-j];
        }
    }
    
    cout << d[n] << '\n';
    return 0;
}