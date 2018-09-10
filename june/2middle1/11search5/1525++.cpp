#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int A[3][3];
//동 서 남 북
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int cnt = 0;

bool isArea(int y, int x){
    return ((x>=0 && x<3) && (y>=0 && y<3));
}

//next permutation으로도 풀어보기
int main() {
    int num = 0;
    for(int i=1; i<=9; i++) {
        int in;
        scanf("%d", &in);
        if(in == 0) {
            in = 9;
        }
        
        num = in + num*10;
    }
    map<int,int> m;
    m[num] = 0;
    queue<int> q;
    q.push(num);

    while(!q.empty()) {
        int front = q.front();
        q.pop();
        string s = to_string(front);
        int pos = s.find('9');
        int col = pos%3;
        int row = pos/3;

        for(int i=0; i<4; i++) {
            int dcol = col + dx[i];
            int drow = row + dy[i];
            //어떨때 큐에 넣어주면 될까? bfs를 해줌될까
            if(isArea(drow, dcol)) {
                string tmp = s;
                //row는 n/3을 했고, dcol은 n*3을 했으니 다 더하면 원래 나뉘는수(dcol,drow의 인덱스)
                swap(tmp[pos], tmp[3*drow+dcol]);
                int next = stoi(tmp);
                if(m.count(next) == 0) {
                    q.push(next);
                    m[next] = m[front] + 1;
                }
            }
        }
    }
    
    if(m.count(123456789) == 0) {
        printf("-1");
    } else {
        printf("%d", m[123456789]);
    }
    return 0;
}