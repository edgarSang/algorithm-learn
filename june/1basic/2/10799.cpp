#include <stack>
#include <iostream>
#include <string>

using namespace std;

int total = 0;
stack<char> stick;

// 백준 인강에서는 레이저를 파악할때 스택에 인덱스를 저장해서 전 인덱스와의 차이가 1일때 레이저로 파악했다.
// ( 일때 +1을 해주지 않고 레이저가 아닌 )때 +1을 해줬었다. 쇠막대기가 하나 더생기는거니까
// else if 비교식 == (stick.pop() + 1 == i) 이면 레이져
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