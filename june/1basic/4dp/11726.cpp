#include <iostream>
#define MAX 1000;
using namespace std;

int d[1000] = {0};

int tail(int N) {
    if (N < 2) {
        return 1;
    } 
    if(d[N] > 0) return d[N];
    d[N] = (tail(N-1) + tail(N-2)) % 10007;
    return d[N];
}

int main() {
    int N;
    cin >> N;

    int out = tail(N);
    
    cout <<  out;
}