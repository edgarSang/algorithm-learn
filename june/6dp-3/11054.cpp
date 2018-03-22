#include <iostream>
#define MAX 1001

template <typename T>
inline T comp(T a, T b) {
    return a > b ? a : b;
}

using namespace std;
int A[MAX] = {0};
int d[MAX][2] = {0};
int m = 0, rm = 0, mi = 0;

int bi(int n, int A[]) {
    int max = 0;
    for(int j=1; j<=n; j++){
        for(int i=0; i<j; i++){
            d[j][0] = A[i] < A[j] ? comp(d[i][0]+1, d[j][0]) : comp(d[j][0], 1);
            // if(d[j][0] > localMax) {
            //     localMax = d[j][0];
            //     mi = j;
            // }
        }
        for(int c=j+1; c<=n; c++){
            d[c-1][1] = 1;
            for(int b=j; b<c; b++) {
                d[c][1] = A[b] > A[c] ? comp(d[b][1]+1, d[c][1]) : comp(d[c][1], 1);
            }
        }
        for(int c=j; c<=n; c++){
            cout << d[j][1] << ' ';
        } cout << '\n';
    }

    return max;
}

int main() {
    int n,  cnt = 1;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }

    
    m = bi(n, A);
    mi = 0;

    cout << comp(m, rm) << '\n';
    return 0;
}