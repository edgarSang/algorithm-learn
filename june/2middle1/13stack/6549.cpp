#include <iostream>

int n[100001] = {0,};

int main() {
    int T = 0;
    while(true) {
        scanf("%d", &T);
        if(T == 0) { break; }
        for(int i=0; i<T; i++) {
            scanf("%d", &n[i]);
        }
    } 


    return 0;
}