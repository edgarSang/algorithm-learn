#include <iostream>

using namespace std;

int main () {
    int n = 0;
    int total = 0;
    scanf("%d", &n);

    for (unsigned int i = 1; i <= n ; i ++) {
        total += i;
    }

    printf("%d", total);
    return 0;
}