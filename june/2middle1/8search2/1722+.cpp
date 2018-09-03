#include <cstdio>
#include <algorithm>

using namespace std;

bool arr_eqaul(int *a, int *b, int size) {
    for(int i=0; i<size; i++) {
        if(a[i] != b[i]) 
            return false;
    }
    return true;
}

bool next_permutation(int *a, int n) {
    int i = n-1;
    while(i > 0 && a[i-1] >= a[i]) {
        i -= 1;
    }
    if(i <= 0) {
        return false;
    }
    int j = n-1;
    while(j > 0 && a[i-1] >= a[j]) {
        j -= 1;
    }
    swap(a[i-1], a[j]);
    j = n-1;
    while(i < j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

int main() {
    int n, exnum;
    scanf("%d %d", &n, &exnum);
    int a[n];

    for(int i=0; i<n; i++) {
        a[i] = i+1;
    }
    if(exnum == 1) { //1번문제 n번째 배열출력
        int k;
        scanf("%d", &k);
        k = k-1;
        while(k--) {
            next_permutation(a, n);
        }
        for(int i=0; i<n; i++) {
            printf("%d ", a[i]);
        }
    } else { //2번문제 index 출력
        int temp[n] = {0,};
        int cnt = 1;
        for(int i=0; i<n; i++) {
            scanf("%d", &temp[i]);
        }
        while(true) {
            if(arr_eqaul(a, temp, n)) {
                printf("%d", cnt);
                break;
            }
            next_permutation(a, n);
            cnt ++;
        }
    }

    return 0;
}