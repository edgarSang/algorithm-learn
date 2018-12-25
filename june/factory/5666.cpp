#include <iostream>
#include <math.h>

int main() {
    int H,P;
    while(scanf("%d", &H) != EOF) {
        scanf("%d", &P);
        // printf("H:%d, P:%d\n", H, P);
        double dap = (double) H/P;
        printf("%.2f\n", round(dap * 100) / 100);
    }

    return 0;
}