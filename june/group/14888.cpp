#include <cstdio>
#define MIN(a,b) ((a)>(b)? (b):(a))
#define MAX(a,b) ((a)>(b)? (a):(b))

using namespace std;
int A[11];
int T;
int maxVal=-1000000000,minVal=1000000000; 

//각 dfs시마다 sam arr를 가지고 있어야하므로
//arr를 by value로 매개변수를 주기위한 트릭이다.
typedef struct
{
  int sam[4];
} ArrByVal;

void go(int idx, int hap, int samIdx, ArrByVal arr) {
    // printf("idx:%d hap:%d samIdx:%d arr:", idx, hap, samIdx);
    // for(int i=0; i<4; i++) {
    //     printf("%d ", arr.sam[i]);
    // }printf("\n");
    if(idx == T-1) {
        minVal = MIN(minVal, hap);
        maxVal = MAX(maxVal, hap);
        return;
    }
    if(idx!=0) {
        arr.sam[samIdx]--;
    }
    int nextIdx = idx+1;
    for(int i=0; i<4; i++) {
        if(arr.sam[i] > 0) {
            switch (i)
            {
                case 0:
                    go(nextIdx, hap+A[nextIdx], i, arr);
                    break;
                case 1:
                    go(nextIdx, hap-A[nextIdx], i, arr);
                    break;
                case 2:
                    go(nextIdx, hap*A[nextIdx], i, arr);
                    break;
                case 3:
                    go(nextIdx, hap/A[nextIdx], i, arr);
                    break;
                default:
                    break;
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        scanf("%d", &A[i]);
    }
    ArrByVal arr;
    for(int i=0; i<4; i++) {
        scanf("%d", &arr.sam[i]);
    }

    go(0, A[0], 0, arr);

    printf("%d\n", maxVal);
    printf("%d\n", minVal);
    return 0;
}