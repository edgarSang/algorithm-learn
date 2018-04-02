#include <iostream>
#include <map>

using namespace std;

map<string, int, greater<int>> m;

void lineParser(string line) {
    string token, delimiter = "\\";
    size_t pos = 0;
    int depth = 0;
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        m.insert(pair<string, int>(token, depth));
        line.erase(0, pos + delimiter.length());
        depth++;
    }
    m.insert(pair<string, int>(line, depth));
}

int main() {
    int n;
    string line;

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> line;
        lineParser(line);
    }

   
    for ( map<string, int::iterator iter = m.begin(); iter != m.end(); ++iter) {
        for(int i=0; i < iter->second; i++)
            cout << ' ';
        cout << iter->first << '\n';
    }
        
    cout << '\n';

    return 0;
}