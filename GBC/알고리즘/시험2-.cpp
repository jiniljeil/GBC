#include<iostream>
#include<algorithm>
using namespace std;
int BS ( int N, int K);
int N, K;
int main(void){ 

    cin >> N >> K;
	
	cout << BS(N, K) << endl;	
	
	return 0;
}
int BS (int N, int K){
	int L=1;
	int R = K;
	int mid = (L+R)/2;
    int con= 0;
	int output=0;
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

return output;
}
