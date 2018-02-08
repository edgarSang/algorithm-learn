#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

void count() {
    string character;
    int small = 0, cap = 0, num = 0, space = 0;

    while (1) {
        getline(cin, character);
        if (character == "") { break; }
        for(int i = 0; i < character.size(); i++) {
            if ((int)character[i] >= 97 && (int)character[i] <= 122)
                small++;
            else if ((int)character[i] >= 65 && (int)character[i] <= 90)
                cap++;
            else if ((int)character[i] >= 48 && (int)character[i] <= 57)
                num++;
            else if ((int)character[i] == 32)
                space++;
        }
        
        printf("%d %d %d %d\n", small, cap, num, space);
        small = 0; cap = 0; num = 0; space = 0;
    }

}

int main () {

    count();

    return 0;
}