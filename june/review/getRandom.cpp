#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <dirent.h> 
#include <stdio.h> 
#include <algorithm>
#include <ctime>

using namespace std;

ifstream in("list.txt");

int main() {
    DIR *d;
    d = opendir(".");
    struct dirent *dir;
    
    vector<string> exists;
    vector<string> words;
    
    string fileName = "";
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            string fileName = dir->d_name;
            if(fileName.substr(fileName.find_last_of(".") + 1) == "cpp") {
                exists.push_back(fileName);
            }
        }
        closedir(d);
    }
    
    
    while(in) {
        string word;
        in >> word;
        words.push_back(word);
    }

    string r;
    int cnt = 0;
    while (true) {
        cnt++;
        srand((unsigned int)time(0));
        r = words[rand()%words.size()];
        if(find(exists.begin(), exists.end(), r) != exists.end()) {
            /*contain*/
        } else {
            /*r does not contain */
            cout << r << endl;
            cout << "cnt: " << cnt << endl;
            break;
        }
    }
    
    //문제점 아직 /asd/asd.cpp 일경우 asd.cpp만 빼오는법을 못했음
    //list.txt파일안에 파일이름이 여러경로가 붙었을때도 이름만 뺴와서 벡터를 만드는법을 해봐야겠음
    return 0;
}