#include <cstdio>
#include <queue>

using namespace std;

bool check[201][201][201] = {false,};
bool ans[201] = {false,};
int A,B,C;
struct node {
    int a;
    int b;
    int c;
    node(int a,int b, int c) : a(a),b(b),c(c){}  
};

//소문자 abc는 실제 물의양
//대문자 ABC는 컵의 크기
void bfs() {
    queue<node> q;
    q.push(node(0,0,C));

    while(!q.empty()) {
        node n = q.front();
        int a = n.a;
        int b = n.b;
        int c = n.c;
        q.pop();
        if(check[a][b][c]) {
            continue;
        }
        check[a][b][c] = true;
        if(a == 0) {
            ans[c] = true;
        }
        //a->b
        if(a + b > B) {
            q.push(node(a+b-B, B, c));
        } else {
            q.push(node(0, a+b, c));
        }
        //a->c
        if(a + c > C) {
            q.push(node(a+c-C, b, C));
        } else {
            q.push(node(0, b, a+c));
        }
        //b->a
        if(b+a > A) {
            q.push(node(A, b+a-A, c));
        } else {
            q.push(node(b+a, 0, c));
        }
        //b->c
        if(b+c > C) {
            q.push(node(a, b+c-C, C));
        } else {
            q.push(node(a, 0, b+c));
        }
        //c->a
        if(c+a > A) {
            q.push(node(A, b, c+a-A));
        } else {
            q.push(node(c+a, b, 0));
        }
        //c->b
        if(c+b > B) {
            q.push(node(a, B, c+b-B));
        } else {
            q.push(node(a, c+b, 0));
        }
    }

}

int main() {
    scanf("%d %d %d", &A, &B, &C);
    bfs();
    for(int i=0; i<201; i++) {
        if(ans[i] == true) {
            printf("%d ", i);
        }
    }
    return 0;
}