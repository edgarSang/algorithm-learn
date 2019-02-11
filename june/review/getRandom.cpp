#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <dirent.h> 
#include <stdio.h> 
#include <algorithm>

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
    while (true) { 
        r = words[rand()%words.size()];
        if(find(exists.begin(), exists.end(), r) != exists.end()) {
            /*contain*/
        } else {
            /*r does not contain */
            cout << r << endl;
            break;
        }
    }
    
    return 0;
}