#include <cstring>

bool check(int x, int y) {
    bool c[10] = {false,};
    for(int i=0; i<=y; i++) {
        for(int j=0; j<=x; j++) {
            c[A[i][j]] = !c[A[i][j]];
            if(A[i][j] == 0 || c[A[i][j]] == false ){
                return false;
            } 
        }
    }

    return true;
}

int main() {


    return 0;
}