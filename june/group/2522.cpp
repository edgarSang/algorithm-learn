#include <cstdio>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);

    for(int i=1; i<=2*T-1; i++) {
        for(int j=1;j <= abs(T-i); j++) {
            printf(" ");
        }
        for(int j=1;j <= T-abs(T-i); j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}