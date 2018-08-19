#include <cstdio>

void count() {
    char character;
    int small = 0, cap = 0, num = 0, space = 0;

    while (scanf("%c", &character)) {

        if ((int)character >= 87 && (int)character <= 122)
            small++;
        else if ((int)character >= 65 && (int)character <= 90)
            cap++;
        else if ((int)character >= 48 && (int)character <= 57)
            num++;
        else if ((int)character == 32)
            space++;


        if((int) character == 10) {
            printf("%d %d %d %d\n", small, cap, num, space);
            small = 0; cap = 0; num = 0; space = 0;
        }
    }

}

int main () {

    count();

    return 0;
}