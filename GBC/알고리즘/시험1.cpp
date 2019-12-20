#include<iostream>
using namespace std;
int main(void){
	int M,N,sum =0, min = 10000;
	cin >> M >> N;
	for(int i =1 ; i<= 100; i++){
		if(M <= i*i && N >= i*i){
			sum += i*i;
			if(min > i*i){
				min = i*i;
			}
		}

	}
	if (sum ==0){
		cout << "-1"<< endl;
	}else{
		cout << sum << endl;
		cout << min << endl;
	}
	
	return 0; 
}
