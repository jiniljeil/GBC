#include<iostream>
#include<algorithm>
using namespace std;
		
int main(void){ 
	int N;
	int temp =0;
    int K;
    int A[101][101];
	int B[10001];
	
	cin >> N ;
	
	for(int i = 1; i<=N; i++){
		for(int j=1; j<=N; j++){
		     	A[i][j]= i*j;
				B[i+j]= A[i][j];	
			}	
		}
	
	sort(B , B+N);	
	
	for(int i = 1; i<=N; i++){
		for(int j =1; j<= N; j++){
			cout << B[i+j] << endl;
		}
	}	
	
	
	
	//cin >> K ;
	//cout << B[K] <<endl;
		
	 
	
	return 0;
}
