#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> section ;
int bs (int N );
int x, n , len ;
int k;
int main(void){

cin >> x >> n ;

for(int i = 0 ; i< n ; i++){
    cin >> len ;
    section.push_back(len);
}	
	
	x *= 10000000; 
    sort ( section.begin(), section.end() );
	
    for(int i= 0; i< section.size() ; i++){ 
        if (section[i] * 2 == x) {
            if (section[i + 1] == section[i]) {
                printf("yes %d %d\n", section[i], x - section[i]);
                return 0;
            }
        }
        else if (bs(x - section[i])) {
            printf("yes %d %d\n", section[i], x - section[i]);
             return 0 ;
        }
    }    
    	cout << "danger" << endl; 

}

int bs (int N ){
    int mid, L , R ;
    
    
    	L = 1;
    	R = section.size();
    
	while (L <= R){
    mid = (L + R)/2;
    if(section[mid]== N){
        return mid;
    }else if (section[mid] > N){
        R = mid -1 ;
    }else{
        L = mid +1 ;
    }
    }
	
   
    return -1;
}
