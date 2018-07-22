#include <iostream>
#include <math.h>

using namespace std;
int check[10000000] = {0,};

int main() {
    string A;
    int P;
    int sum = 0;
    int cnt = 0;
    cin >> A >> P;
    int temp = 20;
    cnt++;
    while(temp--) {
        for(int i=0;i<A.length();i++) {
            int a = A[i] - '0';
            for(int j=1;j<P;j++) {
                sum = sum + (a*a);
            }
        }
        A = to_string(sum);
        check[sum] += 1;
        if(check[sum] > 1) { break; }
        sum = 0;
        cnt ++;
    }
    cout << cnt << endl;

    return 0;
}