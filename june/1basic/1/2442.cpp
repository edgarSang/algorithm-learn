#include <cstdio>

int main () {
    int n;
    scanf("%d", &n);

    for (unsigned int i = 1 ; i <= n ; i++ )
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