#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void NumToHeap(int num) {
    while(num) {
        v.push_back(num%10);
        num/=10;
    }
}

int main() {
    int T, X;
    scanf("%d", &T);

    while(T--) {
        v.clear();
        int curVal=0, cnt=1;
        
        scanf("%d", &X);
        NumToHeap(X);

        sort(v.begin(), v.end());
        curVal = v[0];

        for(int i=0; i<v.size()-1; i++) {
            if(v[i] != v[i+1]) {
                curVal = v[i+1];
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}