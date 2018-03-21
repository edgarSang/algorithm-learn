#include <iostream>
#define MAX 1001

template <typename T>
inline T comp(T a, T b) {
    return a > b ? a : b;
}

using namespace std;
int A[MAX] = {0};
int RA[MAX] = {0};
int d[MAX] = {0};
int m = 0, rm = 0, mi = 0;

int bio(int n, int A[]) {
    int localMax = 0;
    for(int j=1; j<=n; j++){
        for(int i=0; i<j; i++){
            d[j] = A[i] < A[j] ? comp(d[i]+1, d[j]) : comp(d[j], 1);
            if(d[j] > localMax) {
                localMax = d[j];
                mi = j;
            }
        }
    }
    for(int j=mi+1; j<=n; j++){
        for(int i=mi; i<j; i++){
            d[j] = A[i] > A[j] ? comp(d[i]+1, d[j]) : comp(d[j], 1);
            if(d[j] > localMax) {
                localMax = d[j];
            }
        }
    }

    return localMax;
}

int main() {
    int n,  cnt = 1;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
    for(int i=n; i>0; i--){
        RA[i] = A[cnt];
        cnt++;
    }
    
    m = bio(n, A);
    mi = 0;
    for(int i=1; i<=n; i++){
        d[i] = 0;
    }
    rm = bio(n, RA);

    cout << comp(m, rm) << '\n';
    return 0;
}