#include <iostream>
#include <string>
#include <list>

using namespace std;

int cursor;
int N;
list<char> data;

void leftCursor () {
    if (cursor > 0) cursor--;
}

void rightCursor () {
    if (cursor < data.size()) cursor++;
}

void execCmd (char cmd) {
    char pChar;

    if (cmd == 'L') {
        leftCursor();
    } else if (cmd == 'D') {
        rightCursor();
    } else if (cmd == 'B') { //삭제시에는 무조건 advance -1 만큼을 해줘야함.

        if(cursor != 0) {
            auto it = data.begin();
            advance(it, cursor - 1);
            data.erase(it);
        }
            
        leftCursor();
    } else if (cmd == 'P') {
        cin >> pChar;

        auto it = data.begin();
        if(cursor != data.size()) {
            advance(it, cursor);
            data.insert(it, pChar);
        } else {
            data.push_back(pChar);
        }
        
        rightCursor();
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
    cursor = data.size();

    for (int i = 0 ; i < N ; i++) {
        cin >> cmd;
        execCmd(cmd);
    }

    for (std::list<char>::iterator it=data.begin(); it!=data.end(); ++it)
        std::cout << *it;

    return 0;
}