#include <iostream>
#define MAX 1001

template <typename T>
inline T comp(T num1, T num2) {
    return num1 >= num2 ? num1 : num2;
}

using namespace std;
int A[MAX] = {0};
int d[MAX] = {0};

int main (){
    int n, m = 0;
    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
    m = d[1] = A[1];
    for(int j=2; j<=n; j++){
        for(int i=1; i<=j-1; i++){
            d[j] = A[i] < A[j] ? comp(A[j]+d[i], d[j]) : comp(d[j], A[j]);
            m = comp(d[j], m);
        }
    }

    cout << m << '\n';
    return 0;
}