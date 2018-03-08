//D[n] = n 자리 이친수
//1.n번째 자리에 0, 2 n 번째 자리의 1
//n번째 자리의 0이 왔다고 합시다. n-1에 올수있는 수는?
// _ _ N , N-1에는 0,1 이 올수있습니다.
//그러므로 n번째 자리의 0: D[n-1]
//n번째 자리의 1: _ _ 1 앞에는 무조건 _ 0 1 그러므로 D[n-2] 입니다.
#include <iostream>
#define MAX 91

using namespace std;

long long d[MAX] = {0};

int main() {
    int n;

    cin >> n;

    for (int i = 0; i <= n ; i ++) {
        if (i <= 1) d[i] = i;
        else {
            d[i] = d[i-1] + d[i-2];
        }
    }

    cout << d[n] << '\n';
    return 0;
}