#include <cstdio>

int main () {
    int n = 0, num, min = 1e6, max = -1e6;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i ++) {
        scanf("%d", &num);
        min = min < num ? min : num;
        max = max > num ? max : num;
    }

    printf("%d %d", min, max);

    return 0;
}