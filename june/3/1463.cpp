#include <iostream>

#define MAX 1000000
using namespace std;

int cnt = 0;
int d[MAX] = {0};

int toOne(int n) {
    for (int i = 0; i < 10 ; i ++) {
        cout << d[i] << " ";
    }
    cout << "\n";
    if(n == 1) {
        return 0;
    }
    if(d[n] > 0) return d[n];
    d[n] = toOne(n-1) + 1;
    
    if(n%2 == 0) {
        int temp = toOne(n / 2) + 1;
        if(d[n] > temp) d[n] = temp;
    }
    
    if(n%3 == 0) {
        int temp = toOne(n / 3) + 1;
        if(d[n] > temp) d[n] =  temp;
    }
    
    return d[n];
}

int main () {
    int n;
    cin >> n;

    cout << '\n' << toOne(n);

    return 0;
}