#include <cstdio>
#include <stack>

#define MAX 500000
using namespace std;

stack<pair<int,int>> s;

int main() {
    int N;
    long long cnt = 0;
    scanf("%d", &N);
    int in;
    for(int i=0; i<N; i++) {
        scanf("%d", &in);
        //0.스택이 안비어있고 새로운사람이 크다.
        while(!s.empty() && s.top().first < in) {
            cnt += s.top().second;
            s.pop();
        }
        int tmps = 1;
        //1.스택이 안비어있고, 새로들어온사람이 작거나 같다.
        if(!s.empty()) {
            if(s.top().first == in) {
                //새로들어온사람과 기존 탑과 같다?
                cnt += s.top().second;
                tmps += s.top().second;
                s.pop();
                if(!s.empty()) 
                    cnt++;
            } else {
                cnt++;
            }
        }
        s.push({in,tmps});
    }
    printf("%lld\n",cnt);
    return 0;
}