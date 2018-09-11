#include <cstdio>

int go(int count, int sum, int goal) {
    if(sum > goal) return 0;
    if(sum == goal) return 1;
    int now = 0;
    for(int i=1; i<=3; i++) {
        now += go(count, sum + i, goal);
    }

    return now;
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int in;
        scanf("%d", &in);
    
        printf("%d\n", go(0, 0, in));
    }

    return 0;
}