#include <cstdio>
#define MAX 500
#include <math.h>
#define MIN(a,b) ((a)>(b)? (b):(a))


int A[MAX];

double pow(double k) {
    return k*k;
}

int main() {
    int N,K;
    long long sum=0;
    //평균,표준편차,분산
    double m,ts=0,s=987654321,v=0;

    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }


    for(int i=0; i<N-K+1; i++) {
        for(int k=K; k<=N-i;k++) {
            ts=v=sum=0;
            for(int j=i; j<i+k; j++) {
                sum+=A[j];
            }
            m =  sum/(double)k;
            for(int j=i; j<i+k; j++) {
                ts += pow(A[j] - m);
            }
            // printf("%d: %f / %d m:%f \n", i,ts,K,m);
            s = MIN(s, sqrt(ts/(double)k));
        }
    }
    

    printf("%.11lf\n", s);

    return 0;
}