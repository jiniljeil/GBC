#include<stdio.h> 
int main(void){
	int n, k ;
	int num[100001] = { 0 }; 
	int i, temp=0, sum =0, p[1000];

	 
	scanf("%d", &n);   // 동전 가지 수  
	scanf("%d", &k);   // 동전 가치의 합  
	
	for(i=1; i<= n ; i++){
	scanf("%d", &num[i]); // 동전 크기  
	}
	// cout << num[n-1] << endl; 출력
	int j = k/num[n-1];
	for(i=1; i<= j; i++){
		//나머지가 0인 경우 = +1 
		if(k%num[i]==0){
		sum += k/num[i] +1 ;	
		} else{//나머지가 0이 아닌경우 = 몫 + 나머지
		sum += k/num[i]+ k%num[i];
		}
	}  // 경우의 수 추가 작업 
	
	printf("%d", sum);// 경우의 수 출력 
	
	
	return 0;
}
