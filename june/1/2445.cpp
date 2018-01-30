#include <cstdio>

int main () {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 2 * n / 2 - 1 ; i ++) {
        for(int j = 0; j < 2 * n - 8 + 2 * i; j ++) {
            printf("*");
        }
        printf("\n");
    }

}


// 2 = 10 - 8 = 2m - 8               - i=0
// 4 = 10 - 6 = 2m - 8 + 2i           1
// 6 = 10 - 4 = 2m - 8 + 2i           2
// 8 = 10 - 2 = 2m - 8 + 2i           3
// [2n]10 = 10 - 0                    4
// 8 =                                5
// 6                                  6         
// 4                                  7
// 2                                  8
