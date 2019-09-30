#include <cstdio>
#define MAX 500

int A[MAX];

double pow(double k) {
    return k*k;
}

int main() {
    int N,K;
    long long sum=0;
    //평균,표준편차,분산
    double m,s,v = 0;

    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
        sum+=A[i];
    }

    m = sum/N;

    for(int i=0; i<N; i++) {
        s += pow(A[i] - m);     
    }
    s = s/N;

    printf("m:%lf, s:%lf\n%lf\n", m,s, pow(s));

    return 0;
}