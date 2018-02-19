#include <iostream>

#define MAX 12

using namespace std;
int d[MAX] = {0};

int onePlus(int n) {
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    
    if(n < 4) return d[n];
    if(d[n-1] == 0) {
        onePlus(n-1);
    }
    d[n] = d[n-1] + d[n-2] + d[n-3];
    
    return d[n];
}

int main() {
    int n,t;

    cin >> t;
    for(int i = 1; i <= t ; i++){
        cin >> n;
        int result = onePlus(n);

        cout << result << '\n';
    }

    return 0;
}