#include <iostream>

#define MAX 100010

using namespace std;

long long d[MAX][3] = {0};
long long A[2][MAX] = {0};

template <typename T>
inline T comp(T num1, T num2) {
    return num1 >= num2 ? num1 : num2;
}

void sticker(int n) {
    if(n>1) {
        for(int i=1; i<=n; i++){
            d[i][0] = comp(d[i-1][1], d[i-1][2]);
            d[i][1] = comp(d[i-1][0], d[i-1][2])+ A[0][i];
            d[i][2] = comp(d[i-1][0], d[i-1][1])+ A[1][i];
        }
    }
}

int main() {
    long long T, n;
    cin >> T;

    while(T--){
        cin >> n;

        for(int i=0; i<2; i++){ 
            for(int j=1; j<=n; j++){
                cin >> A[i][j]; 
            }
        }
        sticker(n);
        cout << comp(d[n][0], comp(d[n][1], d[n][2])) << '\n';

        for(int i=0; i<2; i++){ 
            for(int j=1; j<=n; j++){
                A[i][j] = 0; 
            }
        }
    }

    return 0;
}