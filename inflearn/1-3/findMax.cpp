#include <iostream>

int findMax (int[] data, int begin, int end) {
    if (begin == end)
        return data[begin];
    else
        return Math.max(data[begin], findMax(data, begin+1, end));
}

int findMax (int[] data, int begin, int end){
    if (begin == end)
        return data[begin];
    else {
        int middle = end / 2;
        int max1 = findMax(data, begin + 1, middle);
        int max2 = findMax(data, middle + 1, end);
        return Math.max(max1, max2);
    }
}