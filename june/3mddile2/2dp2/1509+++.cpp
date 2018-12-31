#include <iostream>
#include <cstring>

using namespace std;

string s;
bool c[2501][2501];
int d[2501];

int main() {
    int result = 0;
    
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i=1; i<=n; i++) {
        c[i][i] = true;
    }
    for (int i=1; i<=n-1; i++) {
        if (s[i] == s[i+1]) {
            c[i][i+1] = true;
        }
    }
    //와 이부분이 너무어렵다
    //[i][j]는 문자열 사이의 갯수가 2 ~ n-2 까지의 개수를 나타냄
    //i와 j 의 문자열 사이의 개수가 2개인것부터 n-2개까지 플래토닉인지 구해나감
    for (int k=2; k<n; k++) {
        for (int i=1; i<=n-k; i++) {
            int j = i+k;
            c[i][j] = (s[i] == s[j] && c[i+1][j-1]);
        }
    }
    d[0] = 0;
    for(int i=1; i<=n; i++) {
        d[i] = -1;
        for(int j=1; j<=i; j++) {
            if(c[j][i]) {
                if(d[i] == -1 || d[i] > d[j-1]+1) {
                    d[i] = d[j-1] +1;
                }
            }
        }
    }

    cout << d[n] << endl;
    return 0;
}