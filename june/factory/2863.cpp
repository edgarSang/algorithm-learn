#include <iostream>

using namespace std;

int main() {
    int a[4];
    double max = 0;
    int count = 0;

    for(int i=0; i<4; i++){
        cin >> a[i];
    }

    max = (double) a[0]/a[2] + a[1]/a[3];

    for(int i=1; i<=4; i++){
        int temp;
        temp = a[3];
        a[3] = a[1];
        a[1] = a[0];
        a[0] = a[2];
        a[2] = temp;

        // cout << max << ' '<< (double) a[0]/a[2] + a[1]/a[3] << '\n'; 
        // cout << "count: "<< count << '\n';

        if (max < (double) a[0]/a[2] + a[1]/a[3]) {
            count = i;
            max = (double) a[0]/a[2] + a[1]/a[3];
        }        
    }

    cout << count << '\n';
    return 0;
}
