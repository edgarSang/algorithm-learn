#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> 

// 1차답 72%
using namespace std;

int solution(int X, vector<int> &A);

int main () {
    std::vector<int> A = {2, 2, 2, 2, 2};
    solution(2, A);
}

int solution(int X, vector<int> &A) {
    bool step[X] = {false};
    int cnt = 0;

    for (unsigned int i = 0 ; i < A.size(); i++) {
        if (A[i] == X) {
            step[A[i]] = true;
        }
        ++cnt;
    }

    cout << cnt << endl;

    for (unsigned int i = 0 ; i < X; i++) {
        cout << (step[i] ? 1 : 0);
    }

    int sum = std::accumulate(step, step + X, 0);
    if(sum == X)
        return cnt;


    return -1;
}