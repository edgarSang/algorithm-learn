#include <cstdio>
#include <string>
#include <math.h>


using namespace std;

int a = 0;

int main() {
    int M;
    scanf("%d", &M);

    for(int i=0;i<M;i++) {
        char cmd[15];
        scanf("%s", &cmd);
        int x;
        if (cmd[2] == 'd') {
            scanf("%d", &x); 
            a = a | (1 << x);
        } else if (cmd[0] =='r') {
            scanf("%d", &x);  
            a = a & (~(1 << x));
        } else if (cmd[0] =='c') {
            scanf("%d", &x);  
            if((a & (1 << x))) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (cmd[0] == 't') {
            scanf("%d", &x); 
            if(a & (1 << x)) {
                a = a & ~(1 << x);
            } else {
                a = a | (1 << x);
            }
        } else if (cmd[0] =='a') {
            a = (1 << 21)-1;
        } else {
            a=0;
        }
    }   

}