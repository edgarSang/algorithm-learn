#include <iostream>
#include <string>

#define MAX 10000
using namespace std;

int Queue[MAX];
int front = 0, rear = 0;

void qCmd () {
    string cmd;

    cin >> cmd;

    if (!cmd.compare("push")) {
        int in;
        cin >> in;
        Queue[rear] = in;
        rear++;
        // cout << in << '\n';
    } else if (!cmd.compare("pop")) {
        if (rear - front == 0) {
             cout << -1 << '\n';
             return;
        }
        cout << Queue[front] << '\n';
        Queue[front] = 0;
        front ++;
    } else if (!cmd.compare("size")) {
        cout << rear - front << '\n';
    } else if (!cmd.compare("empty")) {
        int tmp;
        tmp = rear - front == 0 ? 1 : 0;
        cout << tmp << '\n';
    } else if (!cmd.compare("front")) {
        int tmp;
        tmp = Queue[front] != 0 ? Queue[front] : -1;
        cout << tmp << '\n';
    } else { //back
        int tmp;
        tmp = rear - front > 0 ? Queue[rear-1] : -1;
        cout << tmp << '\n';
    }
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        qCmd();
    }
}