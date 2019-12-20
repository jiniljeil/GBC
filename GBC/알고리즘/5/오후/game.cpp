
#include <iostream>

using namespace std;

int main(void){
long long  x, y, z, l, r, mid , lz ;

cin >> x >> y;

    z = y / x * 100;
    
    if (z >= 99){
    cout << -1 << endl; 
	return 0;
    }
    
    l = 0;
    r = 10000;
    while (l <= r)
    { 
	mid = (l + r) / 2;
    lz = (y + mid) / (x + mid) * 100;
    
    if ( z < lz) {
    l = mid + 1; 
    }else{
    r = mid - 1;
    } 
	}
	cout << l << endl ;
    
    return 0;
}
