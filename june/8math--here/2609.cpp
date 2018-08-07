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
    int A,B;
    cin >> A >> B;
    int g = gcd(A,B);
    cout << g << endl; 
    int l = g*(A/g)*(B/g);
    cout << l << endl;

    return 0;
}