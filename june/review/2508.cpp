#include <iostream>
#include <cstdio>
#include <string>
#define MAX 400

//.o<>v^
//46, 111, 60, 62, 118, 94
using namespace std;

string a[MAX];

int r,c;
bool isArea(int x,int y) {
	return (x >= 0 && x < r) && (y >= 0 && y < c);
}

int main() {
	int cnt, t;
	scanf("%d", &t);

	for(int n=0; n<t; n++) {
		scanf("%d %d", &r,&c);
		cnt = 0;
		for(int i=0; i<r; i++) {
			cin >> a[i];
		}
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++){
				if(a[i][j] == 'o') {
					if(isArea(i-1, j) && isArea(i+1, j)) {
						if(a[i-1][j] == 'v' && a[i+1][j] == '^') {
							cnt ++;
						}
					} 
					if(isArea(i, j-1) && isArea(i, j+1)) {				
						if(a[i][j-1] == '>' && a[i][j+1] == '<') {
							cnt ++;
						}
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	
	
	return 0;
}