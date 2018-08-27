#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
int A[1000000] = {0,};

bool check(int tempH) {
    long long tempM = 0;
    for(int i=0; i<N; i++) {
        tempM += A[i] - tempH;
        if(tempM >= M) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &N, &M);
    int max = 0;
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
        max = A[i] > max ? A[i] : max;
    }
    sort(A,A+N,greater<int>());

    int left = 0;
    int right = max-1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d", right);
    return 0;
}