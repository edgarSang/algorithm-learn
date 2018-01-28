#include <iostream>

// data[0] 에서 data[n-1] 사이에서 target을 검색하는 것이다.
// 하지만 검색구간의 시작 인덱스 0은 보통 생략한다. 즉 암시적 매개변수이다
int search(int [] data, int n, int target){
    for (int i=0; i<n; i++)
        if (data[i] == target)
            return i;
    return -1;
}

// 이 함수를 search(data, 0, n-1, target) 으로호출한다면 
// 암시적으로 호출한것과 완전동일한일을 함
// 이런형태가 더 좋은이유: 명시적 구간(begin) 이 바뀐다면 일시적구간 (begin + 1) 이
// 바뀌기때문에, 명시적으로 매개변수를 정하는게 더 좋다.ㄴ
int search(int[] data, int begin, int end, int target) {
    if (begin > end)
        return -1;
    else if (target == items[begin])
        return begin;
    else
        return search(data, begin + 1, end, target);
}