#include <cstdio>
#include <math.h> 

struct point {
    int x;
    int y;
    // point(int x, int y) : x(x),y(y) {}
};


point A[100000];

int distance(point p1, point p2) {
    int a = p1.x - p2.x;
    int b = p1.y - p2.y;
    return sqrt(pow(a, 2) + pow(b, 2));
}

int main() {
    int n;
    scanf("%d", &n);
    int min = 800000000;

    for(int i=0; i<n; i++) {
        point in;
        scanf("%d %d", &(in.x), &(in.y));
        A[i] = in;
    }

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            printf("%d %d\n", i, j);
            min = min < distance(A[i], A[j]) ? min : distance(A[i], A[j]);
        }
    }

    printf("%d", min);

}