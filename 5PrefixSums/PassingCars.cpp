#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

// 1차답 90%: https://app.codility.com/demo/results/trainingFS96NM-WT6/
// 해결완료
using namespace std;

int solution(vector<int> &A);

int main () {
    std::vector<int> A = {0, 1, 0, 1, 1};
    solution(A);
}

int solution(vector<int> &A) {
    vector<int> v;
    unsigned int total = 0;

    for (unsigned int i = 0 ; i < A.size(); i++) {
        if(A[i] == 0)
            v.push_back(i);
    }

    std::cout << "v vector:";
    for (std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    for (unsigned int i = 0 ; i < v.size(); i++) {
        total += A.size() - (v[i] + 1) - (v.size() - (i+1));
        if (total > 1000000000)
            return -1;
    }
    
    cout << total << endl;
    return 0;
}