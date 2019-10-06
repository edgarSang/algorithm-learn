#include <iostream>
#include <string.h>

using namespace std;

//IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900

int StrToNum(string str) {
    int val = 0;
    for(int i=0; i<str.size(); i++) {
        switch (str[i])
        {
            case 'M':
                val += 1000;
                break;
            case 'D':
                val += 500;
                break;
            case 'C':
                if(i+1<str.size()){
                    if(str[i+1] == 'M') 
                    {
                        val += 900;
                        i++;
                        break;                        
                    }
                    else if(str[i+1] == 'D') 
                    {
                        val+= 400;
                        i++;
                        break;
                    }
                }
                val+=100;
                break;
            case 'L':
                val += 50;
                break;
            case 'X':
                if(i+1<str.size()){
                    if(str[i+1] == 'C') {
                        val += 90;
                        i++;
                        break;                        
                    } else if(str[i+1] == 'L') {
                        val+= 40;
                        i++;
                        break;
                    }
                }  
                val+=10;
                break;
            case 'V':
                val += 5;
                break;
            case 'I':
                if(i+1<str.size()){
                    if(str[i+1] == 'X') {
                        val += 9;
                        i++;
                        break;
                    } else if(str[i+1] == 'V') {
                        val+= 4;
                        i++;
                        break;
                    }

                } 
                val += 1;
                break;
            default:
                break;
        }
    }

    return val;
}

string NumToStr(int val) {
    string str;

    while(val) {
        if(val >= 1000) {
            str.push_back('M');
            val -= 1000;
        } else if(val >= 900) {
            str.push_back('C');
            str.push_back('M');
            val -= 900;            
        } else if(val >= 500) {
            str.push_back('D');
            val -= 500;            
        } else if(val >= 400) {
            str.push_back('C');
            str.push_back('D');
            val -= 400;
        } else if(val >= 100) {
            str.push_back('C');
            val -= 100;
        } else if(val >= 90) {
            str.push_back('X');
            str.push_back('C');
            val -= 90;
        } else if(val >= 50) {
            str.push_back('L');
            val -= 50;    
        } else if(val >= 40) {
            str.push_back('X');
            str.push_back('L');
            val -= 40;
        } else if(val >= 10) {
            str.push_back('X');
            val -= 10;
        } else if(val >= 9) {
            str.push_back('I');
            str.push_back('X');
            val -= 9;            
        } else if(val >= 5) {    
            str.push_back('V');
            val -= 5;
        } else if(val >= 4) {    
            str.push_back('I');
            str.push_back('V');
            val -= 4;
        } else if(val >= 1) {
            str.push_back('I');
            val -= 1;
        }
    }
    
        
    


    return str;
}

int main() {
    string str1, str2, rtnStr;
    int num1=0, num2=0, rtnNum=0;
    cin >> str1 >> str2;
    
    num1 = StrToNum(str1);
    num2 = StrToNum(str2);
    rtnNum = num1 + num2;
    rtnStr = NumToStr(rtnNum);

    cout << rtnNum << endl;
    cout << rtnStr << endl;

    return 0;
}