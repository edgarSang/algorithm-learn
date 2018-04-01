#include <iostream>
#define MAX 1001

template <typename T>
inline T comp(T a, T b) {
    return a > b ? a : b;
}

using namespace std;
int A[MAX] = {0};
//d[n][0] = 오름 차순 수열 길이 최고값
//d[n][1] = 내림 차순 수열 길이 최고값
int d[MAX][2] = {0};


int bi(int n, int A[]) {
    int max = 0; // 오름차순+내림차순 수열 길이 최고값;
    int aMax = 0; // 오름차순 수열 길이 최고값
    int dMax = 0; //내림차순 수열 길이 최고값
    for(int j=1; j<=n; j++){
        for(int i=0; i<j; i++){
            d[j][0] = A[i] < A[j] ? comp(d[i][0]+1, d[j][0]) : comp(d[j][0], 1);
            aMax = comp(d[j][0], aMax);
        }
        if(j > 1){
            d[j][1] = 1;
            dMax = 0;
            for(int c=j+1; c<=n; c++){
                for(int b=j; b<c; b++) {
                    d[c][1] = A[b] > A[c] ? comp(d[b][1]+1, d[c][1]) : comp(d[c][1], 1);
                    dMax = comp(d[c][1], dMax);              
                }
            }         
            for(int i=0; i<=n; i++){
                d[i][1] = 0;
            }
        }

        max = comp(max, aMax+dMax-1);

        
        // cout << max << "=" << " "<< aMax << "+" << dMax << endl;
    }
    return max;
}

int main() {
    int n,  cnt = 1;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }

    cout << bi(n, A) << '\n';
    return 0;
}