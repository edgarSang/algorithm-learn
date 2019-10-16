#include <cstdio>
#include <string.h>

using namespace std;

int A[100][100];
int dap[100][100];
bool visited[100][100];
int N=0;

void dfs(int n, int r) {
    for(int c=0; c<N; c++) {
        if(A[r][c] == 1 && visited[r][c] == false) {
            // printf("n:%d r:%d c:%d\n", n, r, c);
            visited[r][c] = true;
            dap[n][c] = 1;
            dfs(n, c);
        }
    }
}

int main() {
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    for(int i=0; i<N; i++) {
        memset(visited, false, sizeof(visited));
        dfs(i,i);
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", dap[i][j]);
        }printf("\n");
    }

    return 0;
}