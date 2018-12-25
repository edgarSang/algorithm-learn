#include <iostream>

using namespace std;

int charToNum(char ch) {
    int ret = 0;
    if(ch=='I') {
        ret = 1;
    } else if (ch=='V') {
        ret = 5;
    } else if (ch=='X') {
        ret = 10;
    } else if (ch=='L') {
        ret = 50;
    } else if (ch=='C') {
        ret = 100;
    } else if (ch=='D') {
        ret = 500;
    } else if (ch=='M') {
        ret = 1000;
    } 
    return ret;
}

int calc(string str) {
    int ret = 0;
    for (auto rit=str.rbegin(); rit!=str.rend(); ++rit) {
        if(*rit == 'V' && rit+1 != str.rend()) {
            if(*(rit+1) == 'I') {
                ret += 4;
                rit = rit+1;
                continue;
            }
        } 
        else if(*rit == 'X'  && rit+1 != str.rend()) {
            if(*(rit+1) == 'I') {
                ret += 9;
                rit = rit+1;
                continue;
            }
        } 
        else if(*rit == 'L'  && rit+1 != str.rend()) {
            if(*(rit+1) == 'X') {
                ret += 40;
                rit = rit+1;
                continue;
            }
        } 
        else if(*rit == 'C'  && rit+1 != str.rend()) {
            if(*(rit+1) == 'X') {
                ret += 90;
                rit = rit+1;
                continue;
            }
        } 
        else if(*rit == 'D'  && rit+1 != str.rend()) {
            if(*(rit+1) == 'C') {
                ret += 400;
                rit = rit+1;
                continue;
            }
        } 
        else if(*rit == 'M'  && rit+1 != str.rend()) {
            if(*(rit+1) == 'C') {
                ret += 900;
                rit = rit+1;
                continue;
            }
        } 
        ret += charToNum(*rit);
    }

    return ret;
}

string numToChar(int num) {
    int i = 1;
    string ret;
    for(int i=1; i<=4; i++) {
        int jari = num%10;
        while(jari > 0) {
            if(i==1) {
                if(jari == 9) {
                    ret += "XI";
                    jari -= 9;
                } else if (jari == 5) {
                    ret += "V";
                    jari -= 5;
                } else if (jari == 4) {
                    ret += "VI";
                    jari -= 4;
                } else {
                    ret += "I";
                    jari -= 1;
                }
            } else if (i==2) {
                if(jari == 9) {
                    ret += "CX";
                    jari -= 9;
                } else if (jari == 5) {
                    ret += "L";
                    jari -= 5;
                } else if (jari == 4) {
                    ret += "LX";
                    jari -= 4;
                } else {
                    ret += "X";
                    jari -= 1;
                }
            } else if (i==3) {
                if(jari == 9) {
                    ret += "MC";
                    jari -= 9;
                } else if (jari == 5) {
                    ret += "D";
                    jari -= 5;
                } else if (jari == 4) {
                    ret += "DC";
                    jari -= 4;
                } else  {
                    ret += "C";
                    jari -= 1;
                }
            } else {
                if(jari == 4) {
                    ret = "CMCMM";
                    jari -= 4;
                } else {
                    ret += "M";
                    jari -= 1;
                }
            }
        }
        num = num/10;
    }

    return ret;
}

int main() {
    int result = 0;
    ios_base::sync_with_stdio(false);
    string str1, str2;
    cin >> str1 >> str2;
    result += calc(str1);
    result += calc(str2);
    
    cout << result << '\n';
    string arab = numToChar(result);
    for(int i = arab.length() - 1; i >= 0; --i){
        cout << arab[i];
    }
    cout << '\n';

    return 0;
}