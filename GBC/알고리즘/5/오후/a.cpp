#include<iostream>
using namespace std; 
int main(void){
	long int x,y,z, fz;
	long int l,r, mid;
	
	cin >> x >> y;
	fz = y/x* 100;
	
	if(fz >= 99){
		cout << "-1" ;
		return 0;
	}
	while(l <= r){
		l = 0 ;
		r = x; 
		mid = (l + r)/2 ;
		z = (y + mid )/(x + mid) * 100;
		if(z > fz){
			r = mid -1 ;
		}else{
			l = mid + 1 ;
		}
	}
	cout << l; 
	return 0;
}
