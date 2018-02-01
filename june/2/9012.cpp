#include <cstdio>
#include <iostream>
#include <string>

#define MAX 50
using namespace std;

char stack[MAX];
int top;

void initStack() {
    top = -1;
}

int push(char t) {
    if (top > MAX - 1)
        return -1;

    stack[++top] = t;
    return 0;
}

int pop() {
    if (top < 0)
        return -1;

    stack[top--];
    return 0;
}

bool isVPS (string str) {
    initStack();

    for(int j = 0; j < str.size(); j++) {
        if(str[j] == '(') {
            push(str[j]);
        }
        if(str[j] == ')') {
            if(pop()) 
                return false;
        }
    }

    if (top == -1) return true;
    else return false;
}

int main () {
    ios::sync_with_stdio(false);
    initStack();
    int T = 0;
    string in;
    cin >> T;

    for (int i = 0 ; i < T ; i++) {
        cin >> in;
        
        if(isVPS(in)) 
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}
