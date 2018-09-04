#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int S[14];
int d[14];

bool next_permutation(int n, int *A) {
    int i = n-1;
    while(i > 0 && A[i-1] >= A[i]){
        i -= 1;
    }
    if(i <= 0) {
        return false;
    }
    int j = n-1;
    while(j > 0 && A[i-1] >= A[j]) {
        j -= 1;
    }
    swap(A[i-1], A[j]);
    j = n-1;
    while(i < j) {
        swap(A[i], A[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    int n;
    while(true) {
        scanf("%d", &n);
        if(n == 0) { break; }
        for(int i=0; i<n; i++) {
            scanf("%d", &S[i]);
        }
        
        for(int i=0; i<n-6; i++) {
            d[i] = 0;
        }
        for(int i=n-6; i<n; i++) {
            d[i] = 1;
        }
        vector<vector<int>> ans;
        do {
            vector<int> current;
            for(int i=0; i<n; i++) {
                if(d[i] == 1) {
                    current.push_back(S[i]);
                }
            }
            ans.push_back(current);
        } while (next_permutation(n, d));
        sort(ans.begin(), ans.end());
        for(auto &v : ans) {
            for(int i=0; i<v.size(); i++) {
                printf("%d ", v[i]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}