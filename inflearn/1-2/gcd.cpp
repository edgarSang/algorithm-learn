#include <iostream>

using namespace std;

// m >= n 인 두양 정수 m과 n에 대해서 m이 n의 배수이면 gcd(m,n) = n 이고,
// 그렇지 않으면 gcd(m,n) = gcd(n,m%n) 이다.
int gcd (int m, int n) {
    if(m < n) {
        int temp = m; m = n; n = temp;
    }
    if (m > n) {
        if(m % n == 0)
            return n;
    }
    else
        return gcd(n, m%n); 
}

int main () {
    int k = gcd(434, 2);
    cout << k << endl;
    return 0;
}