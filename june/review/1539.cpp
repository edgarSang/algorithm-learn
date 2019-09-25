#include <cstdio>
#define MAX 250000

int p[MAX];

struct Node {
    int v;
    Node *l;
    Node *r;
    Node(int v) {
        v = v;
        l = NULL;
        r = NULL;
    }
};


void insert(Node & n, int x) {
    if(x < n->v) {
        insert(n->l, x);
    } else {
        v->l = Node(x);
    } else {
        if(v->r != NULL) {
            insert(v->r, x);
        } else {
            v->r = Node(x);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0;i<n; i++) {
        scanf("%d", &p[i]);
    }
    
    Node *root = new Node;
    for(int i=1; i<=n-1; i++) {
        insert(root, p[i]);
    }
    return 0;
}