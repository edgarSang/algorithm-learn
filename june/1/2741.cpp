#include <iostream>

using namespace std;

int main () {
    int n = 0;
    
    scanf("%d" , &n);
    for(unsigned int i = 0; i < n ; i++) {
        printf("%d\n", i + 1);
    }

    return 0;
}