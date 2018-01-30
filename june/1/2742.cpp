#include <iostream>

using namespace std;

int main () {
    int n = 0;
    
    scanf("%d" , &n);
    for(unsigned int i = n; i >= 1 ; i--) {
        printf("%d\n", i);
    }

    return 0;
}