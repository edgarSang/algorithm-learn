#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int check[1000000] = {0,};
int Arr[1000000] = {0,};
vector<int> v;
//와 전혀 생각지도 못한 기초연산에서 틀려버림
int main() {
    string A;
    int P;
    int sum = 0;
    cin >> A >> P;
    v.push_back(stoi(A));
    check[stoi(A)] = 1;
    while(true) {
        //틀렸던 부분임 하..
        for(int i=0;i<A.length();i++) {
            int a = 1;
            for(int j=0;j<P;j++) {
                a *= A[i] - '0';
            }
            sum += a;
        }
        A = to_string(sum);
        check[sum] += 1;
        if(check[sum] > 1) {
            break;
        }
        Arr[v.back()] = sum;
        v.push_back(sum);
        sum = 0;
    }
    
    int e = sum;
    int cnt = 0;
    
    while(true) {
        if(Arr[e] == 0) {
            break;
        }
        e = Arr[e];
        cnt ++;
    }

    cout << v.size() - cnt - 1<< endl;
    return 0;
}