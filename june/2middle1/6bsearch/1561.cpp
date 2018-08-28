#include <cstdio>

int A[10000];


int main() {
    int N,M;

    scanf("%d %d" , &N , &M);
    for(int i=0; i<M; i++) {
        scanf("%d", &A[i]);
    }
    if(N <= M) {
        printf("%d", N);
        return 0;
    }

    long long left = 0;
    long long right = 2000000000LL * 10000LL;
    while(left <= right) {
        long long mid = (left+right) / 2;
        //begin = mid 분까지 탄사람의 명수 end = mid 분 끝에 탈수있는 최대 명수 
        long long begin, end;
        begin = end = 0;
        end = M;
        for(int i=0; i<M; i++) {
            end += mid/A[i];
        }
        begin = end;
        // 그 시간에 탈 수 있는 놀이기구 =  분 % 놀이기구 걸리는 시간 == 0
        for(int i=0; i<M; i++) {
            if(mid % A[i] == 0) {
                begin -= 1;
            }
        }
        begin += 1;
        if(N < begin) {
            right = mid - 1;
        } else if(N > end) {
            left = mid + 1;
        } else { // begin < N < end; 이 범위안에 사람수가 들어온다면.
            //놀이기구를 한개씩 더해가면서 원래 주어진 인원수와 같은지 검사.
            for(int i=0; i<M; i++) {
                if(mid % A[i] == 0) {
                    if(begin == N) {
                        //N 번째 사람은 i 번째 다음 놀이기구를 탈 수 있으니까.
                        printf("%d\n", i+1);
                        return 0;
                    }
                    begin += 1;
                }
            }            
        }
    }
    



    return 0;
}