#include <iostream>
#include <algorithm>
#include <functional>

#define MAX 100001
using namespace std;
int N,K;
long long KArr[MAX];
//최종 확정된 쎈치미터

int check(long long tempCm) {
    int count = 0;
    bool flag = false;
    for(int i=0; i<K; i++) {
        // 이 뒤로는 안나눠지니 for문 탈출해도됨
        if(KArr[i] % tempCm == KArr[i]) {
            break;
        }
        int portion = KArr[i] / tempCm;
        count += portion;
    }
    if (count >= N) {
        //만들어진 줄의 갯수가 N보다 크면 cm을 키워도 됨
        flag = true;
    } else {
        flag = false;
    }
    return flag;
}

int main() {
    //K= 이미 있는개수 , N = 만들개수
    
    cin >> K >> N;
    long long left = 1;
    long long right = 0;
    long long mid = 0;
    
    for(int i=0; i<K; i++) {
        long long in;
        cin >> in;
        KArr[i] = in;
        right = in > right ? in : right;
    }

    sort(KArr, KArr + K, greater<long long>());

    while(left <= right) {
        mid = (left + right) / 2;
        // cout << "left: " << left <<" cm: " << mid << " right: " << right << endl;
        // cm으로 나눈 줄개수가 N보다 크면
        // cm을 증가 시킬 수 있다.
        if(check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << right << endl;
    return 0;
}