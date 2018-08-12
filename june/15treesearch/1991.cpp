#include <iostream>

using namespace std;

int A[26][2] = {-1,};
int N;

void preorder(int node) {
    if(node == -1) {
        return;
    }
    printf("%c", node + 'A');
    preorder(A[node][0]);
    preorder(A[node][1]);
}

void inorder(int node) {
    if(node == -1) {
        return;
    }
    inorder(A[node][0]);
    printf("%c", node + 'A');
    inorder(A[node][1]);
}

void postorder(int node) {
    if(node == -1) {
        return;
    }
    postorder(A[node][0]);
    postorder(A[node][1]);
    printf("%c", node + 'A');
}

int main() {
    char nodeChar, in;
    scanf("%d", &N);

    for(int i=0;i<N;i++) {
        scanf(" %c", &nodeChar);
        for(int j=0; j<2; j++) {
            scanf(" %c", &in);
            if(in == '.') {
                int node = nodeChar - 'A';
                A[node][j] = -1;
            } else {
                int node = nodeChar - 'A';
                A[node][j] = in - 'A';
            }
        }
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    // for(int i=0;i<N;i++){
    //     printf("%c", i+'A');
    //     for(int j=0;j<2;j++) {
    //         if(A[i][j] == -1) {
    //             printf(" .");
    //         } else {
    //             printf(" %c", A[i][j] + 'A');
    //         }
    //     }
    //     printf("\n");
    // }

    return 0;
}