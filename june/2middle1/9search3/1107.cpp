#include <cstdio>

bool broken[10] ={false,};

int possible(int c) {
    if(c==0) {
        if(broken[0]) {
            return 0;
        } else {
            return 1;
        }
    }
    int len = 0;
    while(c > 0) {
        if(broken[c % 10]) {
            return 0;
        }
        len += 1;
        c /= 10;
    }

    return len;
}


int main() {
    int n,M;
    scanf("%d %d", &n, &M);

    for(int i=0; i<M; i++) {
        int num;
        scanf("%d ", &num);
        broken[num] = true;
    }
    //현재 100번부터 보고있었기 때문에.
    int ans = n - 100; // n >= 100;
    if(ans < 0) {
        ans = -ans; // n < 100;
    }
    for(int i=0; i <= 1000000; i++) {
        int c = i;
        int len = possible(c);
        if(len > 0) {
            int press = c - n; // +나 -몇번 눌러야 하는지 계산
            if (press < 0) {
                press = - press; // +를 눌러야 하는경우
            }
            if(ans > len + press) {
                ans = len + press;
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}