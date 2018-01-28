#include <iostream>

int search (int[] data, int begin, int end, int target) {
    if (begin > end)
        return -1;
    else {
        int middle = (begin + end) /2;
        if (data[middle] == target)
            return middle;
        int index = search(data, begin, middle - 1, target);
        if (index != -1)
            return index;
        else    
            return search(data, middle + 1, end, target);
    }
}