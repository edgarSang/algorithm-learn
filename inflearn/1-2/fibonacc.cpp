#include <iostream>

using namespace std;

int fibonacci (int n) {
    if (n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if (n > 1){
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int k = fibonacci(10);
    cout << k << endl;
    return 0;
}