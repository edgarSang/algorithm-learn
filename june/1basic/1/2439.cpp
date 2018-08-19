#include <cstdio>

int main () {
    int n;
    scanf("%d", &n);

    for (unsigned int i = 1 ; i <= n ; i++ )
    {
        for (unsigned int j = n ; j >= i ; j-- ) {
            printf("*");
        }
        printf("\n");
    }
}