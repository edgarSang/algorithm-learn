#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> 


using namespace std;

int solution(int X, vector<int> &A);

int main () {
    std::vector<int> A = {1, 3, 1, 4, 2, 3, 5, 4};
    solution(5, A);
}

int solution(int X, vector<int> &A) {
    bool step[X] = {false};
    int cnt = 0;
    int sum = 0;

    for (unsigned int i = 0 ; i < A.size(); i++) {
        if(A[i] <= X) {
            step[A[i]-1] = true;
            ++cnt;
        }
        
        for (unsigned int i = 0 ; i < X; i++) {
            cout << (step[i] ? 1 : 0);
        }
        cout << endl;
    }
    
    sum = std::accumulate(step, step + X, 0);
    if(sum == X) {
        cout << cnt << endl;
        return cnt-1;
    }
    
    for (unsigned int i = 0 ; i < X; i++) {
        cout << (step[i] ? 1 : 0);
    }

    cout << endl << cnt << endl;

    return -1;
}