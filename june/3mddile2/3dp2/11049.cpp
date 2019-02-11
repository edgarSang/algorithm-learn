#include <iostream>

int a[500][2];

int go() {
    
}

int main() {
    int n;

    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }

    return 0;
}