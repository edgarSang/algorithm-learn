#include <iostream>

using namespace std;
int A[101];

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}


int main() {
    int t;

    scanf("%d", &t);
    while(t--) {
        int n;
        long long int total = 0;

        scanf("%d", &n);
        
        for(int i=0; i<n; i++) {
            scanf("%d", &A[i]);
        }

        for(int i=0; i<n;i++){
            for(int j=i; j<n;j++){
                if(i!=j) {
                    total += gcd(A[i],A[j]);
                }
            }
        }

        for(int i=0; i<n; i++) {
            A[i] = 0;
        }
        printf("%lld \n", total);
    }

    return 0;
}