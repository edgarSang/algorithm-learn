#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main() {
    string a, b;
    int xa[26] = {0};
    int xb[26] = {0};
    int sum = 0;

    cin >> a >> b;



    for(int i = 0; i < a.length(); i++) {
        int position = a[i] - 'a';
        xa[position] += 1;
    }
    

    for(int i = 0; i < b.length(); i++) {
        int position = b[i] - 'a';
        xb[position] += 1;
    }

    
    for(int i = 0; i < 26; i++) {
        sum += abs(xa[i] - xb[i]);
    }

    cout << sum << '\n';
    return 0;
}