#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

bool check[9];
int A[9];


bool dfs(int hap, int idx, vector<int> dap) {
    hap += A[idx];
    dap.push_back(A[idx]);
    check[idx] = true; 
    printf("hap:%d, cur:%d, idx:%d, dapsize:%d, \n", hap, A[idx], idx, dap.size());
    if(hap > 100 || dap.size()>7) {
        return false;
    }

    if(hap == 100 && dap.size() == 7) {
        return true;
    }
    
    for(int i=idx; i<9; i++) {
        if(dfs(hap, i, dap)) {
            break;
        }
    }

}

int main() {
    memset(check, false, sizeof(check));

    for(int i=0; i<9; i++) {
        scanf("%d", &A[i]);
    }
    
    sort(A, A+9);
    vector<int> dap;
    for(int i=0; i<9; i++) {   
        if(dfs(0,i,dap)) {
            break;
        }
    }
    
    sort(dap.begin(), dap.end());

    for(int i=0; i<dap.size(); i++) {
        printf("%d\n", dap[i]);
    }
    return 0;
}