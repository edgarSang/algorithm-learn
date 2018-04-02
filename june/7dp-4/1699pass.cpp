#include <iostream>
#include <math.h>
#define MAX 100001

template <typename T>
inline T compMin (T a, T b){
    return a < b ? a : b;
}

using namespace std;

int d[MAX] = {0};

int main() {
    int n;

    cin >> n;

    for(int i=1; i<=n; i++){
        d[i] = i;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j*j<=i; j++){
            d[i] = compMin(d[i-j*j] + 1, d[i]);
        }
    }

    cout << d[n] << '\n';
    return 0;
}