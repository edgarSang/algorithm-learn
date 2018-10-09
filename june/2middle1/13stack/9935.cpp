#include <iostream>
#include <string>

using namespace std;
string str, bomb, dap;

void check(int currentIdx) {
    int bombLen = bomb.size();
    for(int i=0; i<bombLen; i++) {
        if(currentIdx-bombLen+i < 0) return;
        // CurrentIdx-bombLen = 현재 쌓인 스택높이에서 bombLen만큼 빠진만큼을가르킴
        // cout << currentIdx-bombLen+i << " " << i << endl; -- 인덱스 틀린거있나로그
        if(dap[currentIdx-bombLen+i] != bomb[i]) {
            // cout << dap[currentIdx-bombLen+i] << " " << bomb[i] << endl;
            return;
        } 
    }
    for(int i=0; i<bombLen; i++){
        dap.pop_back();
    }

    return;
}

int main() {
    
    cin >> str >> bomb;
    
    for(int i=0; i<str.size(); i++) {
        dap.push_back(str[i]);
        if(str[i] == bomb[bomb.size()-1]) {
            check(dap.size());
        }
    }

    if(dap.size() == 0) {
        dap = "FRULA";
    }
    cout << dap << endl;
    return 0;
}