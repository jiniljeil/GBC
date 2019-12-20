#include<iostream>
#include<algorithm>
using namespace std;
int BS ( int B[],int size, int K);

int main(void){ 

	int N, K;

    cin >> N >> K;
	int B[N*N];
	
	int Bsize = sizeof(B)/sizeof(int);
	int x =BS(B,Bsize, K);
	cout << x << endl;	
	
	return 0;
}
int BS ( int B[],int size ,int K){
	int L=0;
	int R = size-1;
	int mid = (L+R)/2;
	
	while(L<=R){
		mid = (L+R)/2;
		
		if(B[mid] == K){
			return mid;
		}else if (B[mid] > K){
			R = mid -1;
		}else{
			L = mid +1;
		}
	}
	return -1;
}
	
