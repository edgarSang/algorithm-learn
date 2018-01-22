#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 1차답 https://app.codility.com/demo/results/trainingTZD89K-Z7Y/ 
vector<int> solution(int N, vector<int> &A);

int main () {
    std::vector<int> A = {3, 4, 4, 6, 1, 4, 4};
    solution(5, A);
}


vector<int> solution(int N, vector<int> &A) {
    vector<int> counter(N, 0);
    int max = 0;
    int tempMax = 0;

    for (unsigned int i = 0; i < A.size(); i++) {
        if (1 <= A[i] && A[i] <= N) {
            cout << " if A[i] " << A[i]  << " max: " << max << endl;      
            
            if (A[i] < max) {
                counter[A[i]-1] = max + 1; 
            }
            else {
                ++counter[A[i]-1];
            }
            
            if (tempMax < A[i]) {
                tempMax = counter[A[i]-1];
            }

            std::cout << "array counter:";
            for (std::vector<int>::iterator it=counter.begin(); it!=counter.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';      
        } else if (A[i] == N + 1){
            cout << "else if A[i] " << A[i]  << " max: " << max << endl;
            
                max = tempMax;
            
            std::cout << "array counter:";
            for (std::vector<int>::iterator it=counter.begin(); it!=counter.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
    }


    std::cout << "array counter:";
    for (std::vector<int>::iterator it=counter.begin(); it!=counter.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return counter;
}


