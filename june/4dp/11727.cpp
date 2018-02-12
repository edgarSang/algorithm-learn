#include <iostream>
#define MAX 1000

using namespace std;
int d[MAX] = {0};

int tail(int n) {
    if(n < 2) {
        return 1;
    }
    
    if(d[n] > 0) return d[n];
    if(n >= 2) {
        d[n] = (tail(n-1) + tail(n-2) * 2) % 10007;
    }

    return d[n];
}


int main() {
    int n;

    cin >> n;
    int out = tail(n);

    cout << out;

    return 0;
}