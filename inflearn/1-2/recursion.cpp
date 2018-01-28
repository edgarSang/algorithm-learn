#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> 

using namespace std;

//이 함수의 mission은 0~n까지의 합을 구하는것이다.
int func(int n){ 
    if (n == 0) // n이 0이면 합은 0이다.
        return 0;
    else
        return n + func(n-1); // N > 0 일때  n + n-1은 0 ~ n 의 합이다
}

int main() {
    int k = func(4);

    cout << k << endl;
    return 0;
}