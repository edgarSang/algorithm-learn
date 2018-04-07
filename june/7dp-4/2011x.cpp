#include <iostream>
#define MAX 5001
#define mod 1000000

using namespace std;

int d[MAX] = {0};

int main() {
    int n, x;
    string in;

    cin >> in;
    n = in.length();
    
    d[0] = 1;
    for(int i=1; i<=n; i++) {
        x = in[i-1] - '0';
        if(x>=1 && x<=9)
            d[i] = (d[i] + d[i-1]) % mod;
        
        if(i-1 < 1) continue;
        if(in[i-2] == 0) continue;

        //string 배열 i가 0부터 시작이므로 d[i]와 맞춰주려면 in[i-1] 로 계산해야함
        x = ((in[i-2] - '0') * 10) + (in[i-1] - '0');
        if(x >= 10 && x <= 26)
            d[i] = (d[i] + d[i-2]) % mod;
    }
    
    cout << d[n] << '\n';

    return 0;
}