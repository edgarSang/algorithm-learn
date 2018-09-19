#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string A, T;
stack<char> L, R;
int lIdx = 0, rIdx = 0, aIdx = 0;
int flag = 1;

int lPush() {
    aIdx = 0;
    while(lIdx <= rIdx) {
        L.push(T[lIdx]);
        if(A[aIdx] == T[lIdx]) {
            aIdx++;
        } else {
            aIdx = 0;
        }
        if(aIdx == A.size()) {
            while(aIdx--){
                L.pop();
            }
            lIdx++;
            cout << "L size" << L.size() << " " << lIdx << endl;
            return 2;
        }
        lIdx++;
    }
    return 3;
}

int rPush() {
    aIdx = A.size();
    cout << "start r" << rIdx << endl;
    while(lIdx <= rIdx) {
        R.push(T[rIdx]);
        // A가 0일때 그만두고싶은데 그러면 A.size() 만큼 넣어주어야한다.
        // 실제 인덱스는 사이즈 -1 이므로
        // TODO: 지금과 같은 로직이아니라 현재 인덱스 한글자마다 A.size() 만큼 비교해서
        // true이면 나가게 만들어야겠음
        // 현재 로직의 반례 abc
        // fabaabcbcabccd
        cout << A[aIdx-1] << " " << T[rIdx] << endl;
        if(A[aIdx-1] == T[rIdx]) {
            aIdx--;
        } else {
            aIdx = A.size();
        }
        if(aIdx == 0) {
            aIdx = A.size();
            while(aIdx--){
                R.pop();
            }
            cout << "R size" << R.size() << endl;
            rIdx--;
            return 1;
        }
        rIdx--;
    }
    cout << "end r" << rIdx << endl;
    return 3;
}

void flushToR() {
    aIdx = 0;
    while(L.size()) {
        R.push(L.top());
        if(A[aIdx] == L.top()) {
            aIdx++;
        } else {
            aIdx = 0;
        }
        if(aIdx == A.size()) { 
            while(aIdx--) {
                R.pop();
            }
        }
        L.pop();
    }
}

int main() {
    cin >> A;
    cin >> T;
    rIdx = T.size()-1;
    
    while(true) {
        if(flag == 1) {
            flag = lPush();
        } else if(flag == 2) {
            flag = rPush();
        } else {
            flushToR();
            break;
        }
    }

    while(R.size()) {
        printf("%c", R.top());
        R.pop();
    } 
    return 0;
}