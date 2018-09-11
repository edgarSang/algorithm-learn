#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string str ="";
string mo = "";
bool check[15] = {false,};

bool checkStr(string s) {
    int moCnt = 0;
    for(int i=0; i < mo.size(); i++) {
        if(s.find(mo[i]) != std::string::npos) {
            moCnt += 1;
        }
        if(s.size() - moCnt < 2) {
            return false;
        }
    }
    if(moCnt == 0) {
        return false;
    }

    return true;
}

void getPassword(int L, string s,int C, int pos) {
    if(s.size() == L) {
        if(checkStr(s)) {
            cout << s << endl;
        }
        return;
    }
    for(int i=pos; i<C; i++) {
        getPassword(L, s + str[i], C, i+1);
    }
}

int main() {
    int L,C;
    string findMo = "aeiou";
    scanf("%d %d", &L, &C);

    for(int i=0; i<C; i++) {
        char in;
        cin >> in;
        if(findMo.find(in) != std::string::npos) {
            mo+= in;
        }
        str+=in;
    }
    sort(str.begin(), str.end());
    string s="";
    getPassword(L, s, C, 0);
    return 0;
}