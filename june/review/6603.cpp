#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int T,N;
int S[12];


void printfDap(vector<int>& dap) {
	for(int i=0; i<6; i++) {
		printf("%d ", S[dap[i]]);
	}
	printf("\n");
}

void go(int n, vector<int>& dap) {
	int size = dap.size();
	if(size > 6) return;
	//dap의 사이즈가 6개를 체웠을경우 출력
	if(size==6) {
		printfDap(dap);
		return;
	}
	
	for(int i=n+1; i<N; i++) {
		//만약 6개를 넘기는 위치의 인덱스를 선택하면종료
		//if(size+(N-n) < 6) return;
		
		dap.push_back(i);
		go(i, dap);
		dap.pop_back();
	}
}

int main() {
	
	
	while(1) {
		memset(S,0,sizeof(S));
		scanf("%d", &N);
		if(N==0) break;
		
		for(int i=0; i<N; i++) {
			scanf("%d", &S[i]);	
		}
		
		vector<int> dap;
		for(int i=0; i<N; i++) {
            dap.push_back(i);
			go(i, dap);
            dap.pop_back();
		}
		
		printf("\n");
	}
	
	return 0;
}