#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    set<string> no,dap;

    for(int i=0; i<N; i++) {
        string name;
        cin >> name;
        no.insert(name);
    }
    for(int i=0; i<M; i++) {
        string name;
        cin >> name;
        if(no.find(name) != no.end()) {
            dap.insert(name);
        }
    }

    cout<<dap.size()<<'\n';
    for(auto it=dap.begin(); it!=dap.end(); ++it) {
        cout << *it << '\n';
    }

    return 0;
}