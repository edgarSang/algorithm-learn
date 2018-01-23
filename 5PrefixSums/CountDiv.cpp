#include <algorithm>
#include <iostream>
#include <math.h>

// 1차답 50%: https://app.codility.com/demo/results/trainingU9HKJM-MUZ/
// 해결완료
using namespace std;

int solution(int A, int B, int K);

int main () {
    solution(11, 345, 17);
}

int solution(int A, int B, int K) {
    int min = 0;
    int max = 0;
    int i = 0;

    max = (int) floor((double)B / K);
    min = (int) ceil((double)A / K);
    
    cout << max << endl;

    i = max - min + 1;

    cout << i;
    return i;
}