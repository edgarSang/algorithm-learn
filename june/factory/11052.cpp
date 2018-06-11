#include <iostream>
#define MAX 1000
using namespace std;

bool arr[MAX+1];

//세개의 소수 로직
void ex(int num) {
    for(int i=2; i<=num; i++) 
        if(arr[i])
        for(int j=2; j<=num; j++)
            if(arr[j])
            for(int c=2; c<=num; c++)
                if(arr[c]&& i + j + c == num){
                    cout << i << ' ' << j << ' ' << c << '\n';
                    return;
                }
                    
                    
    cout<< "0" << '\n';
    return;
}

int main(){
    int T, k;

    cin >> T;

    for(int i=0;i<=MAX;i++){
        arr[i] = true;
    }

    //에라토스테네스의 체
    for(int i=2; i<=MAX; i++) {
        for(int j=2; j<=MAX; j++) {
            if(j != i  && j % i == 0)
                arr[j] = false;
        }
    }

    while(T--) {
        cin >> k;
        ex(k);
    }

    return 0;
}