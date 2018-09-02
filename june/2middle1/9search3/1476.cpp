#include <cstdio>

int main() {
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);

    int cnt = 1;

    int tE=1;
    int tS=1;
    int tM=1;
    while(true) {
        if(tE == E && tS == S && tM == M) {
            printf("%d", cnt);
            return 0;
        }
        cnt++;
        tE++;
        tS++;
        tM++;
        tE = tE % 16 == 0? 1 : tE % 16;
        tS = tS % 29 == 0? 1 : tS % 29;
        tM = tM % 20 == 0? 1 : tM % 20;
        printf("%d %d %d\n", tE, tS, tM);
    }
    return 0;
}