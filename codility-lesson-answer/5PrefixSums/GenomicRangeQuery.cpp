#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

using namespace std;

// A C G T 
// 1 2 3 4

int main () {
    vector<int> P = {2, 5, 0};
    vector<int> Q = {4, 5, 6};
    string s = "CAGCCTA";

    solution(s, P, Q);
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector<int> v;
    vector<string> strVec;
    string nu = "ACGT";

    for(unsigned int i = 0; i < P.size(); i++) {
        strVec.push_back(S.substr(P[i], Q[i]-P[i]+1));
    }

    std::cout << "strVec vector:";
    for (std::vector<string>::iterator it=strVec.begin(); it!=strVec.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n'; 

    for(unsigned int i = 0; i < P.size(); i++) {
        strVec.push_back(S.substr(P[i], Q[i]-P[i]+1));
    }  

    return v;
}