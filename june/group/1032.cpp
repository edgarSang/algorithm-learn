#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    string a,b;
    cin >> T;
    cin >> a;
    for(int i=1; i<T; i++) {
        cin >> b;
        for(int j=0; j<a.size(); j++) {
            if(a[j] != b[j]) {
                a[j] = '?';
            }
        }
    }

    cout << a << endl;
    return 0;
}
