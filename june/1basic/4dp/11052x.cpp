#include <iostream>
#define MAX 1001

using namespace std;
inline int max(int num1, int num2) {
    return num1 >= num2 ? num1 : num2;
}

int d[MAX] = {0};
int a[MAX] = {0};

int main() {
    int n, temp;
    cin >> n; 

    for(int i = 1; i <= n; i++) {
        cin >> temp;
        a[i] = temp;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            d[i] = max(d[i], d[i-j] + a[j]);
        }
    }

    cout << d[n] << '\n';

    return 0;
}


//D[n] 에 무엇이들어갈까 핵심개념을 못잡겠음
//처음 생각으론, 1로만 채운 가격, 1,2가격 1,3 가격 등 D[n] \
//에는 가격의 모든 경우가 들어가야된다고생각함.
//그러나 이건 아닌것 같은게 MAX크기도 모르겠고, D[n]이 D[n+1]에 영향을 주지않음
//결과적으로 N이 N+1에 영향을 주는 점화식을 못세우겠음

//해설: D[n]은 N개 팔아서 얻을수 있는 최대 수익.
//만약 4명한테 판다면, N번째엔 P[1],P[2],P[3],P[4] 가 올 수 있다.
//즉 P[1]이면 최대값은 D[N] , D[3] + P[1], D[2] + P[2], D[1] + P[3], D[0] + P[4] 중 MAX값을 고르면 된다.
// D[N] = MAX(D[N], D[N-i] + P[i])
//MAX(D[i], )