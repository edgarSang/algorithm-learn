#include <string>
#include <iostream>

using namespace std;

int main () {
    string line;

    getline(cin, line);

    cout << line.size() << "\n";

    return 0;
}