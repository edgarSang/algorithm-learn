/*#include <iostream>
#include <algorithm>
#define MAX 200001

using namespace std;

int a[MAX];
int n,s;

int main() {
    scanf("%d %d", &n, &s);
    
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    //기본 오름차순 greater<>() = 내림차순
    sort(a,a+n);

    int left = 1;
    int right = a[n-1] - a[0]; //가능한 최대거리
    int d = 0; //d는 실제 설치되는 거리
    int ans;
    while(true) {
        int mid = (left+right)/2;
        int cnt = 1; //몇개 설치했는지
        int start = a[0];
        
        for(int i=0; i<n; i++) {
            //d를 정해줌
            d = a[i] - start;
            //mid 를 기준으로 공유기 설치
            if(d >= mid) {
                cnt++;
                start = a[i];
            }
        }

        if(cnt >= s) {
            //공유기 숫자가 많다 간격을 넓히자
            ans = mid;
            left = mid+1;
        } else {
            //공유기 숫자를 줄여아한다. 간격 좁히자.
            right = mid-1;
        }
    }

    printf("%d", ans);

    return 0;
}*/

#include <cstdio>
#include <algorithm>
#define MAX 

using namespace std;

int n,c;
int a[200000];

int main() {
    scanf("%d %d", &n, &c);

    for(int i=0; i<n; i++) {
        scanf("%d", a[i]);
    }
    sort(a,a+n);
    int left = 1;
    int right = a[n-1] - a[0];
    int start = a[0];
    int ans = 0;

    while(left<=right) {
        int count = 1;
        int mid = (left+right)/2;

        for(int i=0; i<n; i++) {
            int d = a[0] - start;
            if(d >= mid) {
                count ++;
                start = a[i];
            }
        }

        if(count >= c) {
            left = mid+1;
            ans = mid;
        } else {
            right = mid-1;
        }
    }
    
    printf("%d", ans);
    return 0;
}
