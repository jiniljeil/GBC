	// 1 ,3 ,6, 10 ~~~
	// 배열 대입 
	// 같은 숫자 3개 
	// 같은 숫자 2개 + 다른 숫자 1개  
	// 다 다른 숫자들  
	// 그게 아니면 0 
#include<iostream>
using namespace std;
int box[51]={ 0 };	
int output[1001]={ 0 };
int result(int num);

int main(void){
	int N ;
	int n;
	int i;
	cin >> N ;
	for(i=0; i<50; i++){
	box[i]= i*(i+1)/2; // T1 , T2 , T3 , T4 	
	} 
	//박스 3개로 입력한 값을 만드는 경우
	for(i=0 ; i< N; i++){
		cin >> n; 
		output[i] = result(n);
	}
	for(i=0; i < N; i++){
		cout << output[i] << endl;	
	}
	
}
int result(int num){
		for(int j =1; j <50; j++){
			for(int k = 1; k<50; k++){
				for(int r = 1; r<50; r++){
					if(num == box[j] + box[k] + box[r]){
						return 1;
					}
				}
			}
		}
		return 0;
	}
