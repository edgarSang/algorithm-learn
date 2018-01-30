#include <cstdio>

int main () {
    int n;
    scanf("%d", &n);
    for (unsigned int i = 1 ; i <= n ; i++ )
    {
        for (unsigned int j = i ; j > 1 ; j-- ) {
            printf(" ");
        }
        for (unsigned int j = 1 ; j <= 2*n-(2*i-1) ; j++ ) {
            printf("*");
        }
        printf("\n");
    }
    for (unsigned int i = 2 ; i <= n ; i++ )
    {
        for (unsigned int j = 0 ; j < n-i ; j++ ) {
            printf(" ");
        }
        for (unsigned int j = 1 ; j <= 2*i-1 ; j++ ) {
            printf("*");
        }
        printf("\n");
    }
}

// 첫번째 2n - 1
// 두번째 2n - 3
// 세번째 2n - 5
// 네번째 2n - 7
// 다섯번쨰 2n - 9
