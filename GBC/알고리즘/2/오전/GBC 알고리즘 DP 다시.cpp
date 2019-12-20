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
	
	coin[1]= 1;
	for(i=1; i<= n ; i++){
		cin >> coin[i]; // 동전 크기
		for(i= coin[i]; i<  )  
	}
		cout << sum << endl; // 경우의 수 출력 
	
	
	return 0;
}
