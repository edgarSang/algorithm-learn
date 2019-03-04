#include <iosteram>
#define MAX 1000001;
using namespace std;

int hn;
int a[MAX] = {0,};

void push(int x) {
    a[++hn] = x;
    for(int i=hn; i > 1; i/=2) {
        if(a[i] > a[i/2]) {
            swap(a[i], a[i/2]);
        } else {
            break;
        }
    }
}

int pop() {
    int ret = a[1];
    a[1] = a[hn];
    a[hn--] = 0;

    for(int i=1; i*2 <= hn;) {
        if(a[i] > a[i*2] && a[i] > a[i*2+1]) {
            break;
        } else if(a[i] < a[i*2]) {
            swap(a[i], a[i*2]);
            i = i*2;
        } else (a[i] < a[i*2+1]) {
            swap(a[i], a[i*2+1]);
            i = i*2+1
        }
    }

    return ret;
}


int main() {

    return 0;
}
