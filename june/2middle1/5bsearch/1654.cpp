#include <iostream>
#include <algorithm>

#define KMAX 10001
using namespace std;

long KArr[KMAX];

// 시간 초과
int main () {
    int K,N;
    int cnt = 0,cm = 0;

    cin >> K >> N;
    for(int i=0; i<K ; i++) {
        long a;
        cin >> a;
        KArr[i] = a;
    }
    sort(KArr, KArr + K);


    for(int i=1; i<KArr[K-1]; i++) {
        long tempCm = i;
        int portionSum = 0;
        for(int j=0; j < K; j++) {
            if(KArr[j] % tempCm != KArr[j]) {
                int portion = KArr[j] / tempCm;
                portionSum += portion;

                if(portionSum >= N) {
                    cm = tempCm;
                    break;
                }
            }
        }    
        if(portionSum < N) {
            break;
        }
    }

    cout << cm << endl;
    return 0;
}