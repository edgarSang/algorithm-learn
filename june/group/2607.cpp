#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

string word,word2;
int T,cnt=0,dap=0;
int A1[26];
int A2[26];

 
int main() {
    cin >> T;
    cin >> word;
    for(int i=0; i<word.size(); i++) {
        A1[word[i]-'A']++;
    }

    while(--T) {
        memset(A2, 0, sizeof(A2));
        cnt = 0;

        cin >> word2;
        for(int i=0; i<word2.size(); i++) {
            A2[word2[i]-'A']++;
        }

        // for(int i=0; i<26; i++) {
        //     printf("%d ", A2[i]);
        // }printf("\n");

        for(int i=0; i<26; i++) {
            if(A1[i] > 0) {
                int plus = A1[i] < A2[i] ? A1[i] : A2[i];
                cnt += plus;
            }

        }
        
        //두개의 사이즈가 같으면
        int len = word.size() - cnt;
        int len2 = word.size() - word2.size();
        if(word.size() == word2.size()) {
            if(abs(len) <= 1) {
                dap++;
            } else if(word.size() == 1) {
                dap++;
            }
        } else {
            len = len > word2.size() - cnt ? len : word2.size() - cnt;
            if(abs(len) <= 1 && abs(len2) <= 1) {
                dap ++;
            }
        }
    }
    
    printf("%d\n", dap);

    return 0;
}