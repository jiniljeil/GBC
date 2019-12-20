#include<iostream> 
int main(void){
	int n, k ;
	int coin[101] = { 0 }; 
	int i, temp=0, sum =0, p[10001]= { 0 };
	using namespace std;
	using std::cin;
	using std::cout;
	 
	cin >> n;   // 동전 가지 수  
	cin >> k;   // 동전 가치의 합  
	
	for(i=1; i<= n ; i++){
		cin >> coin[i]; // 동전 크기  
	}
	// cout << num[n-1] << endl; 출력
	int j = k/coin[n];
	for(i=1; i<= j; i++){				
		if((k-coin[i]*(j-i))%coin[i-1]==0){
		sum += (k-coin[n]*(j-i+1))/coin[i-1] +1 ;	//두 번째에서 나머지가 0인 경우 = +1 
		} else{ 
		sum += (k-coin[n]*(j-i+1))/coin[i-1]+ (k-coin[n]*(j-i+1))%coin[i-1]; //나머지가 0이 아닌경우 = 몫 + 나머지
		}
	}  // 경우의 수 추가 작업 
	
	cout << sum << endl; // 경우의 수 출력 
	
	
	return 0;
}
