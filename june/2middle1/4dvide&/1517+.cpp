#include <cstdio>
#define MAX 500000

int A[MAX] = {0,};
long count = 0;
//이걸 위로 빼니까 속도가 더 빨라짐.
int temp[MAX] = {0,};

//이문제의 키포인트는, 버블의 스왑갯수는 인버젼의 갯수랑 똑같음.
//inversion이란? 정렬시에 왼쪽수보다 오른쪽의 수가 작을때를 말한다.
void solve(int start, int end) {
    if (start == end) {
        return ;
    }
    int mid = (start + end) / 2;
    solve(start, mid);
    solve(mid+1, end);
    // printf("%d %d %d \n", start, mid , end);

    int left = start;
    int right = mid+1;
    int tempIdx = start;
    
    // 더 빠르게 하기위해서 이부분을 가독성 이 안좋게바꿔줌
    while(left <= mid || right <= end) {
        //right > end 크거나라는 조건을추가함.
        if(left <= mid && (right > end  || A[left] < A[right])) {
            temp[tempIdx++] = A[left++];
        } else { //이 때가 inversion갯수를 세줘야 할때
            // printf("%d", mid-left+1);
            count += (long) (mid - left + 1);
            temp[tempIdx++] = A[right++];
        }
    }

    for(int i=start; i<=end; i++) {
        A[i] = temp[i];
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
    solve(0, N-1);
    printf("%ld \n", count);
    // for(int i=0; i<N; i++) {
    //     printf("%d ", A[i]);
    // }

    return 0;
}