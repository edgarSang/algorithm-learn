#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
bool check[15000] = {false,};
int from[15000] = {0,};
char how[15000];

int dCalc(int i) {
    return (2*i) % 10000;
}

int sCalc(int i) {
    return (i+9999) % 10000;
}

int pivot(int i, char flag) {
    if(i==0) {
        return 0;
    }
    int ret;

    if(flag == 'L') {
        int first = i / 1000;
        int last = i % 1000;
        ret = (last * 10) + first;
    } else {
        int first = i / 10;
        int last = i % 10;
        ret = (last * 1000) + first;
    }

    return ret;
}

void solve(int start, int end) {
    queue<int> q;
    q.push(start);
    check[start] = true;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        if(front == end) {
            return;
        }
        int D = dCalc(front);
        int S = sCalc(front);
        int L = pivot(front, 'L');
        int R = pivot(front, 'R');

        if(check[D] == false) {
            q.push(D);
            check[D] = true;
            from[D] = front;
            how[D] = 'D';
        }
        if(check[S] == false) {
            q.push(S);
            check[S] = true;
            from[S] = front;
            how[S] = 'S';
        }
        if(check[L] == false) {
            q.push(L);
            check[L] = true;
            how[L] = 'L';
            from[L] = front;
        }
        if(check[R] == false) {
            q.push(R);
            check[R] = true;
            from[R] = front;
            how[R] = 'R';
        }
    }
}

int main() {
    int a,b,t;
    scanf("%d", &t);
    while(t--) {
        memset(check, false, sizeof(check));
        memset(from, 0, sizeof(from));
        memset(how, NULL, sizeof(how));
        scanf("%d %d", &a, &b);
        solve(a, b);
        int parent;
        vector<char> v;
        while(b != a) {
            v.push_back(how[b]);
            b = from[b];
        }
        reverse(v.begin(),v.end());
        for(int i=0; i<v.size(); i++){
            printf("%c", v[i]);
        }
        printf("\n");
    }

    return 0;
}