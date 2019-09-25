#include <iostream>
#include <limits.h>
#include <cstring>
#include <algorithm>

using namespace std;

struct sch {
    int s;
    int l;
    sch(){};
    sch(int s, int l) : s(s),l(l) {};
};

bool cmp(const sch &a, const sch &b) {
    if(a.l == b.l) {
        return a.s < b.s;
    } else {
        return a.l < b.l;
    }
}

int cnt=0;
sch a[100001];

int main() {
    int n,now=0;
    cin >> n;
    for(int i=1; i<=n; i++) {
        int b,c;
        cin >> b >> c;
        a[i] = sch(b,c);
    }
    sort(a, a+n+1, cmp);

    for(int i=1; i<=n; i++) {
        int s = a[i].s;
        int l = a[i].l;
        if(now <= a[i].s) {
            now = a[i].l;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}