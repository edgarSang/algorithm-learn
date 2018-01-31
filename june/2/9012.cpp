#include <cstdio>
#include <iostream>
#include <string>
#define MAX 500

using namespace std;

char stack[50];
int top,flow;

void initStack() {
    top = -1;
    flow = 0;
}

int push(char t) {
    if (top > MAX -1)
        return -1;

    stack[++top] = t;
    return 0;
}

int pop() {
    if (top < 0)
        return -1;
    stack[top--];
}

int main () {
    ios::sync_with_stdio(false);
    initStack();
    int T = 0;
    string in;
    scanf("%d", &T);

    for (int i = 0 ; i < T ; i++) {
        cin >> in;
        for(int j = 0; j < in.size(); j++) {
            if(in[j] == '(') {
                push(in[j]);
            }
            if(in[j] == ')') {
                flow = pop();
            }
            printf("%d %d \n", top, flow);
        }
        
        if(top == -1 && flow != -1) printf("YES");
        else printf("NO");
        fflush(stdin);
        initStack();
    }
    return 0;
}