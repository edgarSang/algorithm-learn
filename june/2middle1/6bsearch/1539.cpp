#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct node {
    int to;
    int weight;
    node(int to, int weight) : to(to),weight(weight) {}
};

vector<node> A[10000];
int check[10001] = {0,};

bool dfs(int start, int end, int weight) {
    std::fill_n(check, 10001, 0);
    stack<int> s;
    s.push(start);
    check[start] = 1;  

    while(!s.empty()) {
        
        int top = s.top();
        s.pop();

        for(int i=0; i<A[top].size(); i++) {
            node tmp = A[top][i];

            if(check[tmp.to] == 0 && tmp.weight >= weight) {
                if(tmp.to == end) {
                    return true;
                }
                // printf("%d - ", tmp.to);
                check[tmp.to] = 1;
                s.push(top);
                s.push(tmp.to);
                break;
            }
        }
    }
    return false;  
}

int main() {
    int N,M,start,end;
    int left = 1, right = 0;
    scanf("%d %d", &N, &M);

    for(int i=0; i<M; i++) {
        int v, e, w;
        scanf("%d %d %d", &v, &e, &w);
        A[v].push_back(node(e,w));
        A[e].push_back(node(v,w));
        right = right > w ? right : w;
    }

    // for(int i=0; i<M; i++) {
    //     printf("%d", i);
    //     for(int j=0; j<A[i].size(); j++) {
    //         node tmp = A[i][j];
    //         printf(" %d",tmp.to);
    //     }
    //     printf("\n");
    // }

    // printf("%d \n", right);
    scanf("%d %d", &start, &end);

    while(left <= right) {
        int mid = (left+right)/2;
        if(dfs(start, end, mid)){
            // printf("true %d \n", mid);
            left = mid+1;
        } else {
            // printf("false %d \n", mid);
            right = mid-1;
        }
        
    }
    
    printf("%d", right);

    return 0;
}