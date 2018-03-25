// hint
// 1.d[n][1], d[n][2]의 뭐가 들어갈지 먼저 생각을 해보자.
// 2.여기서는 계단을 밟고 올라가야하기때문에 한번도 안밟는경우는 생길수가없다.
// 3.1차원 배열로도 풀어보자.
// 4.그림을 직접계단그림으로 그려보아도 도움이된다.
#include <iostream>
#define MAX 301

template <typename T>
inline T comp(T a, T b) {
    return a > b ? a : b;
}

int d[MAX][3] = {0};
int A[MAX] = {0};

using namespace std;

int main () {
    int n, max=0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
    
    d[1][1] = A[1];
    for(int i=2; i<=n; i++){
        d[i][1] = comp(d[i-2][1], d[i-2][2]) + A[i];
        d[i][2] = d[i-1][1] + A[i];
    }

    cout << comp(d[n][1], d[n][2]) << '\n';

}

