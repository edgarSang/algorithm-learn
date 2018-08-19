#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> L_STACK;
stack<char> R_STACK;

template <class T>
void print(stack<T> st)
{
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}

template <class T>
void reverseStack(stack<T>& st)
{
    T item;
    stack<T> tmpStack;

    while (!st.empty())
    {
        item = st.top();
        st.pop();
        tmpStack.push(item);
    }

    st = tmpStack;
    return;
}

void execCmd (char cmd) {
    char pChar;

    if (cmd == 'L') {
        if (!L_STACK.empty()) {
            R_STACK.push(L_STACK.top());
            L_STACK.pop();
        }
    } else if (cmd == 'D') {
        if(!R_STACK.empty()) {
            L_STACK.push(R_STACK.top());
            R_STACK.pop();
        }
    } else if (cmd == 'B') { 
        if (!L_STACK.empty()) {
            L_STACK.pop();
        }
    } else if (cmd == 'P') {
        cin >> pChar;
        L_STACK.push(pChar);
    }
}

int main () {
    ios::sync_with_stdio(false);
    string line;
    char cmd;

    cin >> line >> N;
    
    for(int i = 0; i < line.length(); i++)
		L_STACK.push(line.at(i));

    for (int i = 0 ; i < N ; i++) {
        cin >> cmd;
        execCmd(cmd);
    }


    reverseStack(L_STACK);
    print(L_STACK);
    print(R_STACK);

    std::cout << '\n';
    return 0;
}