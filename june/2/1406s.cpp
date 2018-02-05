#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cursor;
int N;
stack<char> L_STACK;
stack<char> R_STACK;


void execCmd (char cmd) {
    char pChar;

    if (cmd == 'L') {
        R_STACK.push(L_STACK.top());
        L_STACK.pop();
    } else if (cmd == 'D') {
        L_STACK.push(R_STACK.top());
        R_STACK.pop();
    } else if (cmd == 'B') { 
        L_STACK.pop();
    } else if (cmd == 'P') {
        cin >> pChar;
        R_STACK.push(pChar);
    }

    cout << "Data: ";
    while (!L_STACK.empty())
    {
        std::cout << ' ' << mystack.top();
        L_STACK.pop();
    }
    cout << " |R stack:| ";
    while (!R_STACK.empty())
    {
        std::cout << ' ' << mystack.top();
        R_STACK.pop();
    }
    std::cout << '\n';
}

int main () {
    ios::sync_with_stdio(false);
    string line;
    char cmd;

    cin >> line >> N;
    
    L_STACK.assign(line.begin(), line.end());

    for (int i = 0 ; i < N ; i++) {
        cin >> cmd;
        execCmd(cmd);
    }


    return 0;
}