#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    string a, b;
    int sum = 0;

    cin >> a >> b;

    for(int i=0; i < a.length(); i++){
        for(int j=0; j< b.length(); j++) {
            if(a[i] != b[j]) {
                a[i] = '*';
                b[j] = '*';
            }
        }
    }

    for(int i=0; i < a.length(); i++) {
        if(a[i] == '*')
            sum ++;
    }
    for(int i=0; i < b.length(); i++) {
        if(b[i] == '*')
            sum ++;
    }

    cout << sum << '\n';

    return 0;
}