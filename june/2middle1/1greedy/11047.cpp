#include <iostream>

using namespace std;
int token[11];


int main() {
    int N,K,A,tokenCnt;

    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        A = 0;
        cin >> A;
        token[i] = A; 
    }

    tokenCnt = 0;

    while(true) {
        if(K == 0) {
            break;
        }
        // cout << token[N] <<" K:"<<  K << endl;
        if(K % token[N] == K) {
            N --;
        } else {
            int portion = K / token[N];
            K = K % token[N];
            tokenCnt += portion;
        }
    }
    cout << tokenCnt << endl;
}