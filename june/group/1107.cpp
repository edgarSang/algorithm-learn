#include <cstdio>
#include <cstdlib>

using namespace std;

bool broken[10] = {false,};

int possible(int click) {
    //c 가 영일때
    if(click==0) {
        if(broken[click]) {
            return 0;
        } else {
            return 1;
        }
    }

    int len = 0;
    while(click > 0) {
        if(broken[click % 10]) {
            return 0;
        } 
        len += 1;
        click /= 10;
    }

    return len;
}


int main() {
    int N,M,ans;
    
    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++) {
        int in;
        scanf("%d", &in);
        broken[in] = true;
    }

    //온전히 + or - 로만 접근했을때 답.
    ans = N - 100;
    if(ans < 0) {
        ans = -ans;
    }

    for(int i=0; i<=1000000; i++) {
        int c = i;
        int len = possible(c);

        //len이 1이상일때만 +-만 누른값에서 줄일수있으므로
        if(len > 0) {
            int press = N-c;
            if(press < 0) {
                press = -press;
            }
            if(ans > len+press) {
                ans = len+press;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}