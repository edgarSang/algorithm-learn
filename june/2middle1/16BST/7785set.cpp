#include <iostream>
#include <set>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    set<string> s;

    for(int i=0; i<T; i++) {
        string name, cmd;
        cin >> name >> cmd;
        if(cmd == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }
    
    for(auto rit = s.rbegin(); rit != s.rend(); ++rit) {
        cout << *rit << '\n';
    }
    return 0;
}