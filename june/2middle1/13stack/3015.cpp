#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<pair<int, int>> s;
    int T;
    long long result = 0;
    scanf("%d", &T);
    for(int i=0; i<T; i++) {
        int in;
        scanf("%d", &in);
        pair<int,int> p = {in, 1};
        //스택이 비어있지 x
        while(!s.empty()) {
            //스택TOP < in stack.pop
            if(s.top().first <= in) {
                result += (long long) s.top().second;
                if(s.top().first == in) {
                    p.second += s.top().second;
                }
                s.pop();
            } else {
                break;
            }
        }

        //스택 비어있을경우
        if(!s.empty()) result += 1LL;
        s.push(p);
    }

    cout << result << endl;

    return 0;
}