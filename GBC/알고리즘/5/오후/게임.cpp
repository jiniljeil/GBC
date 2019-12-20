#include<iostream>
using namespace std; 

#define MAX 1000000001
int main(void){
int  X , Y ; 	//0<= Y <= X <= 10억 
int Z = 0 ; // 게임 횟수 , 이긴 게임 , 해야하는 판수  	

	cin >> X >> Y ;
    
    int average = Y/X*100;
    
	int L =0;
	int R = MAX;
	int mid = (L + R)/2; 
	
	while ( L<= R ){
	Z = (Y+ mid)/(X+ mid)* 100;
	if( Z > average ){
		R = mid -1 ;
	}else{
		L = mid + 1; 
	}
	cout << L << endl;
	break ;	
	}
	if (average >= 99 ){
	cout << "-1" << endl;
	return 0;
	}// 절대 변하지 않을 경우  	

}
