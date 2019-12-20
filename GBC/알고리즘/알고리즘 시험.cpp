#include<iostream>
#include<math.h>
using namespace std;

int main(void){
	int M, N ;
	int min ,max;
	int minN, maxN; 
	int c[101]= { 0 }; // 10000 이하의 값이므로 100의 제곱 
	cin >> M >> N ;
	
	if(M >=1  && N>=1 && M <= 10000 && N <=10000 && M<=N){
		for(int i=1 ; i<101; i++){
		c[i]= pow(i,2); //완전 제곱수 생성  
	}
	for(int i =1; i<101; i++){
		if(c[i]<=M && M<=c[i+1] ){
			if(M ==c[i]){
				minN =i;
			}else{
				minN = i+1;	 // 완전제곱 최소값 
			}	
		}
		if(c[i]<=N && N<=c[i+1]){
			maxN = i; // 완전제곱 최댓값 
		} 
	}
	// 완전 제곱 최소와 최대의 사이 값들
	int sum =0 ;
	for(int i=minN; i<=maxN; i ++){
		sum += pow(i,2);
	}
	min = pow(minN, 2);
	// 완전제곱이 존재하지 않을 경우

	if(sum == 0 ){
	cout << "-1" << endl;
	}else{
	cout << sum << endl;
	cout << min << endl;	
	}
	}
	// a 와 b 사이에 완전제곱수가 있는지 없는지  	
	return 0;
}
