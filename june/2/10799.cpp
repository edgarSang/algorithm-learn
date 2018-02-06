#include <stack>
#include <iostream>
#include <string>

using namespace std;

int total = 0;
stack<char> stick;

int main () {
    ios::sync_with_stdio(false);
    string line;

    cin >> line;

    for (int i = 0; i < line.size(); i ++) {
        if (line[i] == '(') { // 막대 쌓기
            stick.push(line[i]);
            total += 1;
        } else if (line[i-1] == '(' && line[i] == ')') { // 레이저의 경우
            stick.pop();
            total -= 1;
            total += stick.size();
        } else { // 레이저 아니면 조립라인위에 있는 막대 버려줘야함.
            stick.pop();
        }
    }

    cout << total << '\n';
}