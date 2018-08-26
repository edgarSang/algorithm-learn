#include <cstdio>

#define MAX 100000

int postorder[MAX];
int inorder[MAX];
int inpostion[MAX+1];

int N;

//ir == inorder 내에 루트의 인덱스, leftSize = inorder 에서 구별할수있는 left 자식 Node의 사이즈
//in_start = 인오더 배열스타트, in_end 인오더 배열 엔드, post_start =포스트배열 스타트, post_end=포스트배열 엔드
//루트= 포스트 오더 배열의 맨마지막 값이 루트노드이다.
void solve(int in_start, int in_end, int post_start, int post_end) {
    if(post_start > post_end) return;
    if(in_start > in_end) return;
    
    int root = postorder[post_end];

    printf("%d ", root);

    int ir = inpostion[root];
    //왼쪽 노드의 크기.
    int leftSize = ir - in_start;
    
    solve(in_start, ir-1, post_start, post_start + leftSize - 1);
    solve(ir+1, in_end, post_start+leftSize, post_end-1);
}

int main() {
    scanf("%d", &N);

    for(int i=0;i<N;i++) {
        scanf("%d", &inorder[i]);
    }
    for(int i=0;i<N;i++) {
        scanf("%d", &postorder[i]);
    }
    for(int i=0;i<N;i++) {
        inpostion[inorder[i]] = i;
    }

    solve(0, N-1, 0, N-1);
    return 0;
}