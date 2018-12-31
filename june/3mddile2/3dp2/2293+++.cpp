#include <iostream>

using namespace std;

int a[100];
int d[10001];

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    d[0] = 1;

    for(int j=0; j<n; j++) {
        for(int i=1; i<=k; i++) {
            if(i-a[j]>=0) {
                d[i] += d[i-a[j]];
            }
        }
    }

    printf("%d", d[k]);
    return 0;
}