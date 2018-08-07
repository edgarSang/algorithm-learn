#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

int main() {
    int T,A,B;
    cin >> T;
    while(T--) {
        cin >> A >> B;
        int g = gcd(A,B);
        int l = g * (A/g) * (B/g);
        cout << l << endl;
    }
}