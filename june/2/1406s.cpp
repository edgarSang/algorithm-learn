#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cursor;
int N;
list<char> data;


void execCmd (char cmd) {
    char pChar;

    if (cmd == 'L') {

    } else if (cmd == 'D') {

    } else if (cmd == 'B') { 

    } else if (cmd == 'P') {

    }

    // cout << "cursor: " << cursor << endl;
    // cout << "Data: " << data.size();
    // for (std::list<char>::iterator it=data.begin(); it!=data.end(); ++it)
    //     std::cout << *it;
    // cout << "\n";;
}

int main () {
    ios::sync_with_stdio(false);
    string line;
    char cmd;

    cin >> line >> N;
    
    data.assign(line.begin(), line.end());

    for (int i = 0 ; i < N ; i++) {
        cin >> cmd;
        execCmd(cmd);
    }

    for (std::list<char>::iterator it=data.begin(); it!=data.end(); ++it)
        std::cout << *it;

    return 0;
}