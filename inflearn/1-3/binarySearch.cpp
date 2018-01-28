#include <iostream>
#include <string>

using namespace std;

int binarySearch(string[] items, string target, int begin, int end) {
    if (begin > end)
        return -1;
    else {
        int middle = (begin + end) / 2;
        int compResult = target.compareTo(items[middle]);
        if (compResult == 0)
            return middle;
        else if (compResult < 0)
            return binarySearch(items, target, begin, middle - 1);
        else
            return binarySearch(items, target, middle + 1, end);
    }
}