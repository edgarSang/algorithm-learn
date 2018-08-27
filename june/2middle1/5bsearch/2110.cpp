#include <iostream>
#include <algorithm>

using namespace std;

int N,C;

int A[200000] = {0,};

bool possible(int tempDistance) {
    int cnt = 1;
    int last = A[0];
    for(int i=0; i<N; i++) {
        if(A[i] - last >= tempDistance) {
            cnt += 1;
            last = A[i];
        }
    }
    return cnt >= C;
}

int main() {
    int ans;
    scanf("%d %d", &N, &C);

    for(int i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    sort(A, A+N);

    
    int left = ans = 1;
    int right = A[N-1] - A[0];
    while(left <= right) {
        int mid = (left + right) / 2;
        if(possible(mid)) {
            ans = mid > ans ? mid : ans;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("%d", right);
    return 0;
}