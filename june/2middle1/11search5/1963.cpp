#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;
bool prime[10000] = {false,};

bool c[10001];
int d[10001];
void eratos(int n) {    
    for(int i=2; i<=n+1; i++) {
        if(prime[i] == false) {
            for(int j=i*i; j<=n+1; j+=i) {
                prime[j] = true;
            }
        }
    }

    for(int i=0; i<=n+1; i++) {
        prime[i] = !prime[i];
    }
}

int next_num(int num, int index, int digit) {
    if(index == 0 && digit == 0) return -1;
    string s = to_string(num);
    s[index] = digit + '0';
    return stoi(s);
} 

void bfs(int start, int end) {
    memset(c, false, sizeof(c));
    memset(d, 0, sizeof(d));

    queue<int> q;
    c[start] = true;
    q.push(start);

    while(!q.empty()) {
        //present 현재
        int now = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            for(int j=0; j<=9; j++) {
                int next = next_num(now, i, j);
                if(next != -1) {
                    if(prime[next] && c[next] == false) {
                        q.push(next);
                        d[next] = d[now] + 1;
                        c[next] = true;
                    }
                }
            }
        }
    }

    printf("%d \n", d[end]);
}

int main() {
    eratos(9999);
    int t;
    scanf("%d", &t);
    while(t--) {
        int start, end;
        scanf("%d %d", &start, &end);

        bfs(start, end);
    }

    return 0;
}