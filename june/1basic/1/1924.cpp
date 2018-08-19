#include <iostream>
#include <string>

using namespace std;

int main () {
    string days[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int x, y = 0;
    int day = 0;
    scanf("%d", &x);
    scanf("%d", &y);

    for (unsigned int i = x - 1; i >= 1; i--) {
        day += month[i - 1];
    }

    cout << days[(day + y) % 7];

    return 0;
}