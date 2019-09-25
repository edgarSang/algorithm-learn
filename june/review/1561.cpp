#include <cstdio>
#define MAX 10000

int N,M;
int a[MAX];

int main() {
    scanf("%d %d", &N, &M);

    for(int i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }
    long long left = 0;
    long long right = 60000000000;
    long long need_time = 0;

    while(left <= right) {
        long long mid = (left + right) / 2;
        long long ridden_person = M; 
        for(int i=0; i<M; i++) {
            //이 부분이 이해가 안된다. 놀이기구별로 커버칠수 있는 사람의수??
            ridden_person += mid/a[i];
        } 

        if(ridden_person >= mid) {
            need_time = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }

        //찾은시간에서 마지막사람 전까지의 탑승한 인원을 전부 더한다.
        //찾은시간의 탑승한사람을 구한다.
    }



    return 0;
}