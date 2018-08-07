#include <iostream>

using namespace std;

bool prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i=2; i<=n-1; i++){
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    int cnt = 0;
    cin >> N;

    for(int i=0;i<N;i++) {
        int in;
        cin >> in;
        if(prime(in)) {
            cnt ++;
        }
    }

    cout << cnt << endl;

    return 0;
}