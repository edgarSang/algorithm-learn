#include <iostream>
#define MAX 100001

template <typename T>
inline T comp(T a, T b) {
    return a > b ? a : b;
}

using namespace std;

int d[MAX];
int A[MAX] = {0};

int main(){
    int n, m = -1002;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }

    for(int i=1; i<=n; i++){
        d[i] = comp(d[i-1] + A[i], A[i]);
        m = comp(d[i], m);
    }

    cout << m << '\n';
    return 0;
}