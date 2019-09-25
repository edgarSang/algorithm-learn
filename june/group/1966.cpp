#include <iostream>
#include <vector>

using namespace std;

//더 높은게 존자하나 안존재하나 확인
bool isNotExist(vector<pair<int, bool>> q, int start) {
    int cur = q[start].first;
    for(int i=start+1; i<q.size(); i++) {
        if(cur < q[i].first) {
            return false;
        }
    }

    return true;
}

int go(vector<pair<int, bool>> q, int M) {
    int cnt = 0;
    int s = 0;
    //q가 한개면 바로출력
    if(q.size() == 1) {
        return 1;
    }
    //1.현재큐의 중요도보다 높은거 있나확인,
    //2.현재큐의 중요도보다 높은거없으면 push
    //3.cnt++
    // +맨처음 지정되었던 것과 현재 시작과 같으면 종료
    while (s < q.size()) {

        //큰 수가 없을 경우, pop (start index + 1)
        if(isNotExist(q, s)) {
            // printf("<%d,%d> cnt: %d s:%d var: ", q[s].first , q[s].second, cnt, s);
            // for(int i=s; i<q.size(); i++) {
            //     printf("%d ", q[i]);
            // }printf("\n");
            cnt ++;
            if(q[s].second) {
                return cnt;
            }
            s ++;
        } else {
            pair<int,bool> front = q[s];
            q.push_back(front);
            s++;
        }
    }

    return cnt;
}

int main () {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N,M;
        vector<pair<int, bool>> q;
        scanf("%d %d", &N, &M);

        for(int i=0; i<N; i++) {
            int in;
            scanf("%d", &in);
            if(i == M) {
                q.push_back(pair<int,bool>(in, true));
            } else {
                q.push_back(pair<int,bool>(in, false));
            }
        }
        printf("%d\n", go(q, M));
    }

    return 0;
}