#include <cstdio>

int main () {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if(i % 2 == 0) { //짝수줄 일때
            for (unsigned int j = 0 ; j < n-i; j++ ) {
                printf(" ");
            }
            for (unsigned int j = 1 ; j <= 2*i ; j++ ) {
                if(j % 2 == 0)
                    printf(" "); 
                else
                    printf("*");
            }
        } else { // 홀수줄일때
            for (unsigned int j = 0 ; j < n-i ; j++ ) {
                printf(" ");
            }
            for (unsigned int j = 1 ; j <= 2*i ; j++ ) {
                if(j % 2 == 0)
                    printf(" ");
                else
                    printf("*");
            }
        }
        printf("\n");
    }
}