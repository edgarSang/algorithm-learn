#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int check[10000000] = {0,};
stack<int> s;

int main() {
    string A;
    int P;
    int sum = 0;
    cin >> A >> P;
    s.push(stoi(A));
    check[stoi(A)] = 1;
    while(true) {
        for(int i=0;i<A.length();i++) {
            int a = A[i] - '0';
            for(int j=1;j<P;j++) {
                sum = sum + (a*a);
            }
        }
        A = to_string(sum);
        check[sum] += 1;  
        if(check[sum] > 2) { break; }
        s.push(sum);
        sum = 0;
    }
    while(!s.empty()) {
        if(check[s.top()] == 1) { break; }
        s.pop();
    }
    cout << s.size() << endl;
    return 0;
}