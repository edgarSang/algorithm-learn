#include <iostream>
#define MAX 1000001

int m,n,maxH,minH;
int a[MAX];

int search(int h) {
    int preM = 0;

    while(true) {
        int tempM = 0;
        for(int i=1; i<=n; i++) {
            int sub = a[i] - h;
            if(sub > 0) {
                tempM += sub;
            }
        }
        if(preM-m < tempM-m) return h;
        preM = tempM;
        if(tempM>m) {
            minH = h;
            h = (h+maxH)/2;
        } else {
            maxH = h;
            h = (h+minH)/2;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        maxH = maxH < a[i] ? a[i] : maxH;
        minH = minH > a[i] ? a[i] : minH;
    }

    printf("%d\n" ,search(maxH/2));

    return 0;
}