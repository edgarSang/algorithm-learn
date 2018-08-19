#include <iostream>

using namespace std;

int main () {
    int n = 0;
    
    scanf("%d" , &n);
    for(unsigned int i = 1; i <= 9 ; i ++) {
        printf("%d * %d = %d\n", n, i, i*n);
    }

    return 0;
}