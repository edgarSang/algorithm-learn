#include <iostream>
#include <queue>

using namespace std;

int front = 0, rear = 0;
queue<int> qu;

void josePurs(int N, int M) {

    cout << "<";
    for (int i = 1; i <= N - 1 ; i++) {
        for (int j = 1; j <= M - 1; j ++) {
            qu.push(qu.front());
            qu.pop();
        }
        cout << qu.front() << ", ";
        qu.pop();
    }
    cout <<  qu.front() << ">";
    qu.pop();
}

int main () {
    int N, M;
    cin >> N >> M;   

    for(int i = 1 ; i <= N; i++) {
        qu.push(i);
    }
    
    josePurs(N, M);
}