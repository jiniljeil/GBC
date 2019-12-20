#include <iostream>
#define MAX 1000000000 
using namespace std;

int main(){
int x, y, z;
int l, r, mid, lz;
cin >> x >> y;
    z = y / x * 100;
    
    if (z >= 99){
    cout << -1 << endl; 
	return 0;
    }
    
    l = 0;
    r = MAX;
    while (l <= r)
    { 
	mid = (l + r) / 2;
    lz = (y + mid) / (x + mid) * 100;
    
    if (z < lz){
    r = mid - 1;
    } else{
    l = mid + 1; 
    }
    } 
    cout << l; 
}
