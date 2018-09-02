#include <cstdio>
#include <vector>

using namespace std;

long long f[21] = {1};
bool c[21];

void solve1(int n) {
    long long k;
    scanf("%lld", &k);
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        for (int j=1; j<=n; j++) {
            if (c[j] == true) continue;
            //n-i-1 이 부분이 잘 이해가안된다.
            if (f[n-i-1] < k) {
                k -= f[n-i-1];
            } else {
                a[i] = j;
                c[j] = true;
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}

void solve2(int n) {
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        long long ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=1; j<a[i]; j++) {
                if (c[j] == false) {
                    ans += f[n-i-1];
                }
            }
            c[a[i]] = true;
        }
        printf("%lld", ans+1);
}

int main() {
    for (int i=1; i<=20; i++) {
        f[i] = f[i-1] * i;
    }
    int n, exnum;

    scanf("%d %d", &n, &exnum);

    if(exnum == 1) {
        solve1(n);
    } else {
        solve2(n);
    }

    return 0;
}