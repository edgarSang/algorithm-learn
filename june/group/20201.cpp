#include <string>
#include <vector>
#include <iostream> 

using namespace std;

int getZipSize(string s, int len, int curAns) {
    //1.len 만큼 비교를해서
    //2.같으면 cnt를 추가
    // 2-1 만약 현재 cnt가 1이라면 기준 string에 넣기
    //3.기준 string과 다르면 cnt+string dap에 넣고 string count 초기화 
    //3-1 cnt가 1이면 그냥 넣기
    int cnt = 1;
    string dap="",comp="", next="";
    for(int i=0; i <= s.size();) {
        bool isSame = false;
        next = "";
        for(int j=i; j<i+len; j++) {
            next += s[j];
        }
        cout <<"len: " << len << " " << "i: " << i <<" "<< "next:" << next << " " << "comp: " << comp;
        if(next.compare(comp) == 0) {
            isSame = true;
        } else {
            isSame = false;
        }
        
        if(isSame && i != s.size()) {
            cnt ++;
        } else {
            if(cnt > 1) {
                dap += to_string(cnt) + comp;
            } else {
                dap += comp;
            }
            comp = "";
            cnt = 1;
            for(int j=i; j<i+len; j++) {
                comp += s[j];
            }
        }
        cout << " in for "  << "dap: " << dap << endl;
        if(dap.size() > curAns) {
            return curAns;
        }
        if(i+len>s.size()) {
            for(int j=i; j<s.size(); j++) {
                dap+=s[j];
            }
            break;
        }
        i += len;
        
    }
    cout << "out for "  << "dap: " << dap << endl;
    return dap.size();
}

int solution(string s) {
    int answer = 0;
    
    //최악의 경우
    answer = s.size();
    for(int i=1; i<=s.size()/2; i++) {
        int tmp = getZipSize(s, i, answer);
        answer = answer > tmp ? tmp : answer;
    }
    
    return answer;
}

int main() {
    string in;

    cin >> in;

    cout << solution(in) << endl;

    return 0;
}
