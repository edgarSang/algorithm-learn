#include <iostream>
#include <stack>

using namespace std;
#define MAX 1001

int A[MAX] = {0,};
int check[MAX] = {0,};

void dfs(int start) {
    stack<int> s;
    s.push(start);
    check[start] = 1;
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        
        for(int i=0;i<1;i++){
            if(check[A[top]]==0){
                check[A[top]] = 1;
                s.push(top);
                s.push(A[top]);
                break;
            }
        }
    }
}

int main() {
    int T,N;
    cin >> T;

    while(T--){
        int cnt=0;
        cin >> N;
        for(int i=1;i<=N;i++){
            int v;
            cin >> v; 
            A[i] = v;
        }
        for(int i=1;i<=N;i++){
            check[i] = 0;
        }
        for(int i=1;i<=N;i++){
            if(check[i] == 0){
                dfs(i);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}