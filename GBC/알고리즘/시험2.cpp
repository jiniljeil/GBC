#include<iostream>
#include<algorithm>
using namespace std;

int main(void){ 

	int N, K;

    cin >> N >> K;
			
	int L=1;
	int R = K;
	int output;
			
	while(L<=R){
	int cir =0;
		int mid = (L+R)/2;
		for(int i=1; i<=N; i++){
			cir += min(mid/i,N);
		}
		if (cir > K){
		R = mid -1;
		output = mid;	
		}else{
		L = mid +1;	
		}
	}
	cout << output << endl;
 	return 0;
}
	
