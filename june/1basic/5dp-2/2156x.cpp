#include <iostream>
#define MAX 10001

template <typename T>
inline T comp(T num1, T num2) {
    return num1 >= num2 ? num1 : num2;
}

using namespace std;

long long d[MAX][3] = {0};
int A[MAX] = {0};

void grape(int n) {
    for(int i=1; i<=n; i++){
        d[i][0] = comp(d[i-1][0], comp(d[i-1][1], d[i-1][2]));
        d[i][1] = d[i-1][0] + A[i];
        d[i][2] = d[i-1][1] + A[i];
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> A[i];
    }
    grape(n);

    cout << comp(d[n][0], comp(d[n][1], d[n][2])) << '\n';
}