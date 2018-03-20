#include <iostream>
#define MAX 1001

using namespace std;

template <typename T>
inline T comp(T num1, T num2) {
    return num1 >= num2 ? num1 : num2;
}

int A[MAX] = {0};
int d[MAX] = {0};


int main(){
    int n;
    int max = 0;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> A[i];
    }
    d[1] = 1;
    max = 1;
    if(n > 1){
        for(int j=2; j<=n; j++){
            for(int i=1; i<=j-1; i++){
                d[j] = A[i] < A[j] ? comp(d[j], d[i]+1) : comp(d[j], 1); 
                max = comp(max, d[j]);
            }
        }
    }
    
    cout << max << '\n';
    return 0;
}