#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int myints[] = {1,4,1};
    std::vector<int> A(myints, myints + sizeof(myints) / sizeof(int));


    int sum = 0;
    int total = 0;
    
    sort(A.begin(), A.end());
    
    for(unsigned int i = 0 ; i < A.size(); i++) {
        if(i > 0)
        if(A[i] == A[i-1])
        return 0;
    }



    for(unsigned int i = 1 ; i <= A.size() ; i++) {
        total += i;
    }
    
        
    for(unsigned int i = 0 ; i < A.size() ; i++) {
        sum += A[i];
    }

    if(sum == total)
        return 1;
    else
        return 0;

    // std::cout << "A are:";
    // for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
    // std::cout << ' ' << *it;
}

// 빠른답: boolean형 배열을 vector size만큼 만들어서, vector 벨류값과 index 값이 매칭되면 
// 요소들을 true로 초기화 시킴. 
// int solution(vector<int> &A) {
//     // the use of a auto_ptr would be better, but it does not work with arrays
//     // use of boost::scoped_array seems like an overkill
//     bool * seen = new bool[A.size()];
     
//     for (unsigned int i=0; i< A.size(); i++){
//         seen[i] = false;
//     }    
     
//     for (unsigned int i=0; i< A.size(); i++){
//         if (!(0 < A[i] && A[i] <=A.size() && seen[A[i]-1] == false)){
//             delete[] seen;
//             return 0;
//         } else {
//             seen[A[i]-1] = true;
//         }
//     }
     
//     delete[] seen;
//     return 1;
// }
